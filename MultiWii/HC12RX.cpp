#include <NeoSWSerial.h>
#include "Arduino.h"
#include "config.h"
#include "def.h"
#include "types.h"
#include "MultiWii.h"
#include "HC12RX.h"

#if defined(HC12RX)

#define PADDING 10
#define THROTTLE_INC 11

int16_t HC12_rcData[RC_CHANS];
NeoSWSerial HC12(7, 8);

unsigned long lastReceiveTime = 0, lastRunTime = 0;
const char delimiter = ',';
byte boundLow, boundHigh;

char input[32];  // Allocate memory for input parsing
int throttle = 0, yaw = 512, pitch = 512, roll = 512, aux1 = 1, aux2 = 0;

void HC12_Init() {
  HC12.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void HC12_Read_RC() {	
  unsigned long currentTime = millis();

  if ((currentTime - lastRunTime) >= 100) {
    int numDelimiter = 0, i = 0;
    if (HC12.available() > 0) {
      i = HC12.readBytesUntil('\n', input, sizeof(input));
      input[i] = '\0';  // Null-terminate string
      
      // Count delimiters and validate input
      for (int j = 0; j < i; j++) if (input[j] == delimiter) numDelimiter++;
      
      if (numDelimiter == 5) {
        lastReceiveTime = currentTime;
        
        // Parse throttle
        char* p = strtok(input, ",");
        int throttle_det = atoi(p);
        if (throttle_det >= 600 && throttle <= (1023 - THROTTLE_INC)) throttle += THROTTLE_INC;
        if (throttle_det <= 424 && throttle >= THROTTLE_INC) throttle -= THROTTLE_INC;

        // Parse remaining values
        yaw = atoi(strtok(NULL, ","));
        pitch = atoi(strtok(NULL, ","));
        roll = atoi(strtok(NULL, ","));
        aux1 = atoi(strtok(NULL, ","));
        aux2 = atoi(strtok(NULL, ","));
        
        // Reset throttle if in defined position
        if ((throttle_det < PADDING) && (yaw < PADDING) && (roll > (1023 - PADDING)) && (pitch < PADDING)) throttle = 0;
      }
    }
    
    // Check for connection loss
    if ((currentTime - lastReceiveTime) > 1000) {
      digitalWrite(LED_BUILTIN, HIGH);
      if (throttle >= (THROTTLE_INC / 5)) throttle -= (THROTTLE_INC / 5);
      yaw = 512; pitch = 512; roll = 512; aux1 = 1; aux2 = 0;
    } else {
      digitalWrite(LED_BUILTIN, LOW);
    }

    // Map RC values to range
    HC12_rcData[THROTTLE] = map(throttle, 0, 1023, 1000, 2000);
    HC12_rcData[YAW] = map(yaw, 0, 1023, 1000, 2000);
    HC12_rcData[PITCH] = map(pitch, 0, 1023, 1000, 2000);
    HC12_rcData[ROLL] = map(roll, 0, 1023, 1000, 2000);
    HC12_rcData[AUX1] = map(aux1, 0, 1, 2000, 1000);
    HC12_rcData[AUX2] = 1000;

    lastRunTime = currentTime;  // Update last run time
  }
}
#endif
