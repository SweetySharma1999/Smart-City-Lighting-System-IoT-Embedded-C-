# Smart-City-Lighting-System-IoT-Embedded-C-

# Smart City Lighting System 

An automated and energy-efficient street lighting solution developed using **Embedded C**, combining environmental light sensing and real-time scheduling.

##  Overview
This project addresses urban energy wastage by implementing an intelligent lighting controller. The system utilizes an **LDR (Photoresistor)** for ambient light detection and a **DS1307 RTC module** for time-accurate operations .It ensures lights are active only during defined night hours (18:00 - 05:00) or when natural light falls below a specific threshold.

## Technical Features
-**Sensor Fusion:** Integrated LDR and RTC data to manage lighting states efficiently.
-**Adaptive Control:** Implemented logic to handle a darkness threshold of **251** (tunable for various environments)- **Real-Time Scheduling:** Hardcoded night-time logic to ensure public safety even if sensors are obstructed.
- **Serial Telemetry:** Real-time debugging and data logging via Serial Monitor at 115200 baud.

##  Hardware Architecture
The system is built on the **Arduino Uno** platform with the following components:
- **Microcontroller:** Arduino Uno
- **Sensors:** Photoresistor (LDR) 
- **Time Module:** DS1307 Real-Time Clock (I2C) 
- **Output:** High-intensity LED (representing street lights)
- **Components:** 220Ω and 10kΩ Resistors for circuit stability

##  Live Simulation
Experience the live circuit and code execution without hardware:
[Run on Wokwi Simulator](https://wokwi.com/projects/446801076851722241)

##  Project Structure
- `SmartLighting.ino`: Core firmware logic.
- `diagram.json`: Virtual circuit schematic for Wokwi.
- `README.md`: Project documentation.

##  About the Developer
Developed by a dedicated **Electrical Engineering student at GJUST**, focusing on IoT, Power Systems, and Automation.
