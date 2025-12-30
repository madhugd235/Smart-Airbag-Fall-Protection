# Smart-Airbag-System-Fall-Protection
IoT-based Smart Airbag System for Fall Detection using ESP32
An IoT-based smart airbag system designed to detect human falls using an ADXL335 accelerometer and ESP32. Upon fall detection, the system inflates an airbag, activates a buzzer, and sends an email alert to the guardian.

 Hardware Components:
- ESP32
- ADXL335 Accelerometer
- Relay Module
- Air Compressor
- Buzzer

 Software Tools:
- Arduino IDE
- Embedded C/C++
- ESP32 Wi-Fi Libraries

 Working Principle:
The accelerometer continuously monitors motion. When acceleration crosses threshold values indicating a fall, ESP32 triggers airbag inflation and sends an email alert via Wi-Fi.

 Applications:
- Elderly care
- Construction worker safety
- Industrial fall protection
