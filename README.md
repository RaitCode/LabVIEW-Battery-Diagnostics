# LabVIEW-Battery-Diagnostics
Battery SOC Estimation and Environmental Monitoring System

🔋 Battery SOC Estimation and Environmental Monitoring System
This LabVIEW project estimates the State of Charge (SOC) of batteries using the Open Circuit Voltage (OCV) Method, monitors environmental conditions, and logs key performance data. It's designed to support battery diagnostics and testing workflows by integrating both hardware and software tools.

🚀 Features
📏 SOC Estimation via OCV Method
Calculates SOC based on the known relationship between open circuit voltage and state of charge for different battery chemistries.

🔧 Customizable Battery Configuration
User inputs include:
Cell chemistry
Nominal voltage
Number of series/parallel cells per module
Number of modules per pack

🌡️ Environmental Monitoring
Reads and logs temperature and humidity using a DHT22 sensor.
Sensor is connected to an Arduino, communicating with LabVIEW via serial protocol.

🧪 Voltage Simulation
SOC changes simulated using a potentiometer to emulate voltage shifts.

🕒 SOC Range Duration Logging
Automatically tracks how long each battery remains in defined SOC bands:
100–75%
75–50%
50–25%
25–10%
10–0%

📊 Live Dashboard + Data Logging
User-friendly interface in LabVIEW.
All data (OCVs, SOCs, temperature, humidity, SOC duration) is logged in structured CSV files.

🖥️ System Requirements
LabVIEW (2017 or later recommended) and NI MAX
Arduino Uno or compatible
DHT22 Sensor
Potentiometer
NI-VISA drivers for serial communication
Jumper wires

🛠️ Getting Started
Connect Arduino with DHT22 sensor and potentiometer as per the provided schematic.
Load the Arduino sketch to handle temperature/humidity and serial communication.
Open the LabVIEW VI.
Configure your battery parameters and start the session.
Observe SOC, environmental conditions, and SOC band durations in real-time.
