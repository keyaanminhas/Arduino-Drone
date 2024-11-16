# **Custom Drone Project with MultiWii and HC-12 Integration**

This project integrates and customizes the MultiWii flight control software to include **HC-12 wireless communication support**. The code combines features from **Rupak Podder's repository** and the updated **2020 MultiWii repository by Synersignart**. The goal was to adapt the latest MultiWii version to work seamlessly with HC-12 modules, ensuring improved communication capabilities for drone control.

---

## **Features**

- **Flight Control with MultiWii:**
  - Utilizes the robust MultiWii 2020 code as the base.
  - Implements self-leveling and stabilization features.
- **HC-12 Communication:**
  - Added support for the HC-12 module to enable wireless transmission of commands such as throttle, pitch, roll, yaw, and auxiliary controls.
- **Custom Modifications:**
  - Merged key features from Rupak Podder's repository, specifically the HC-12 communication functionality.
  - Adjusted IMU orientation to resolve axis inversion issues.

---

## **Hardware Components**

- **Flight Controller:** Arduino Nano
- **Sensors:**
  - **MPU9250** (gyroscope and accelerometer)
- **Motors:** 1000KV motors with 10-inch propellers
- **ESCs:** 30A
- **Frame:** F450 quadcopter frame
- **Battery:** 3000mAh LiPo
- **Communication Module:** HC-12

---

## **Software Details**

### **Repositories Used**
- [MultiWii 2020 Update by Synersignart](https://github.com/synersignart/Multiwii-2020-update)
- [Rupak Podder's Drone Repository](https://github.com/Rupakpoddar/Drone)

### **Modifications**
1. Integrated **HC-12 communication** code from Rupak Podder's repository into the latest MultiWii software.
2. Updated IMU orientation to fix axis alignment for stable flight.
3. Added functionality for connection loss detection to ensure safe fallback behavior.

---

## **How to Build and Flash**

1. Clone the repository and open the project in the Arduino IDE.
   ```bash
   git clone <repository-link>
   ```
2. Connect the Arduino Nano to your computer and select the correct board and port in the Arduino IDE.
3. Configure the code:
   - Adjust any pin assignments or settings in the configuration files to match your hardware setup.
   - Ensure HC-12 TX/RX pins are mapped correctly.
4. Upload the sketch to the Arduino Nano.

---

## **Usage Instructions**

1. **Power On:** Connect the battery to power up the drone.
2. **Pair HC-12 Modules:** Ensure the transmitter and receiver HC-12 modules are paired.
3. **Send Commands:**
   - Use a compatible controller to send commands wirelessly via HC-12.
   - Adjust throttle, yaw, pitch, and roll using the controller's joysticks.
4. **Flight Modes:** Utilize MultiWii's flight modes for stability and manual control.

---

## **Goals and Future Work**

- **Primary Goal:**
  - Add HC-12 support to the latest MultiWii code for enhanced wireless communication.
- **Future Improvements:**
  - Implement telemetry feedback via HC-12 for real-time monitoring.
  - Fine-tune PID values for smoother and more stable flight.
  - Add support for GPS modules for autonomous flight.

---

## **Disclaimer**

This project is for personal and educational use. Ensure compliance with local regulations regarding drone usage and radio communication frequencies. Always operate the drone responsibly and in open areas to ensure safety.

---
