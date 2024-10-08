# IoT-enabled Automatic Tablet and Syrup Dispenser

## Overview

The IoT-enabled Automatic Tablet and Syrup Dispenser allows for precise medication dispensing controlled by doctors or family members through an Android application. This system generates weekly reports and features a sophisticated mechanism for dispensing both tablets and syrup.

## Features

- **Remote Control**: Medication dispensing can be managed via a user-friendly Android application.
- **Reporting**: The system generates weekly reports for monitoring medication adherence.
- **3D-Printed Mechanism**: A custom-designed tablet and syrup dispensing mechanism.
- **Refrigeration Unit**: Keeps syrups at optimal temperatures.
- **Environmental Monitoring**: Measures temperature and humidity inside the dispensers.

## Hardware Highlights

- **Microcontroller**: ESP32
- **Sensors**: 
  - DHT11/DHT22 for temperature and humidity
- **Actuators**: 
  - DC motors for dispensing tablets and syrups
  - Peltier module for refrigeration
  - Peristaltic pump for liquid dispensing
- **Connectivity**: Wi-Fi for communication with the Android app and Firebase

## Hardware Configuration

### Pin Configuration

| Component                  | Pin Number |
|----------------------------|------------|
| Peristaltic Pump           | 4          |
| Peltier Module             | 5          |
| DC Motor for Tablet Dispense | 6          |
| DC Motor for Syrup Dispense  | 7          |

### Additional Hardware

- **Power Supply**: Ensure a stable power supply for the ESP32 and peripheral devices.
- **3D-Printed Mechanism**: Design and print the dispensing mechanism as per requirements.

## AWS Configuration

1. Set up a Firebase project and obtain the necessary API key.
2. Define the Realtime Database URL in your code.
3. Ensure the ESP32 is connected to Wi-Fi for remote access and control.

## Code Deployment

1. Include the necessary libraries:
   - `Firebase_ESP_Client.h`
   - `WiFi.h`
   - `DHT.h` (if using a DHT sensor)
2. Replace placeholders for Wi-Fi credentials and Firebase configuration in the code.
3. Upload the Arduino sketch to your ESP32.

## Monitoring Data

- Use the Android application to monitor temperature and humidity readings.
- Track the status of dispensing operations and receive alerts.

## Dependencies

- **Arduino IDE**: Required for uploading code to the ESP32.
- **Firebase ESP Client**: For database interactions.
- **DHT Sensor Library**: For temperature and humidity readings.


![android_app](https://github.com/pratz222/IoT-enabled-Automatic-Tablet-and-Syrup-Dispenser/assets/53640877/b81bc51b-83e3-4238-9bca-e0b4b9838b6d)

![prototype](https://github.com/pratz222/IoT-enabled-Automatic-Tablet-and-Syrup-Dispenser/assets/53640877/12126f43-b3ca-4a48-94ae-ec877f314553)

