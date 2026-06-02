# ESP32 Home Automation System

An IoT-based Home Automation System built using ESP32 and a 4-channel relay module. This project enables users to control household appliances such as lights, fans, and power sockets from any device connected to the same WiFi network.

The ESP32 hosts a web server that provides a simple and user-friendly interface for switching appliances ON and OFF in real time without requiring any additional mobile application.

## Features

- WiFi-based appliance control
- Responsive web dashboard
- Control up to 4 devices independently
- Real-time relay switching
- Low-cost and scalable solution
- Easy to expand with MQTT, Blynk, or voice assistants

## Hardware Used

- ESP32 Development Board
- 4-Channel Relay Module
- Jumper Wires
- WiFi Router
- AC Appliances (for demonstration)

## Software Used

- Arduino IDE
- ESP32 Board Package
- WiFi Library
- WebServer Library

## Working Principle

The ESP32 connects to a local WiFi network and starts an embedded web server. Users access the server through a browser using the ESP32's IP address. Button presses on the web dashboard send HTTP requests to the ESP32, which then toggles the corresponding relay and appliance state.

## Applications

- Smart Home Systems
- Remote Lighting Control
- Fan Automation
- Energy Management
- IoT Learning Projects

## Future Improvements

- MQTT Integration
- Mobile Application
- User Authentication
- Energy Monitoring
- Voice Assistant Support
- Cloud Connectivity

## Author

Anirudh Sharma (AdrenoEzz)
