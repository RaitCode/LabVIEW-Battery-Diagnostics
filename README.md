# LabVIEW-Battery-Diagnostics  

**Battery SOC Estimation and Environmental Monitoring System**  

This LabVIEW project estimates the State of Charge (SOC) of batteries using the Open Circuit Voltage (OCV) Method, monitors environmental conditions, and logs key performance data. It's designed to support battery diagnostics and testing workflows by integrating both hardware and software tools.  

**Features**  
*SOC Estimation via OCV Method*  
Calculates SOC based on the known relationship between open circuit voltage and state of charge for different battery chemistries.  
AA size batteries were used to simulate the various battery packs.  

*Customizable Battery Configuration*  
User inputs include:  
Cell chemistry   
Number of series/parallel cells per module  
Number of modules per pack  

*Environmental Monitoring*  
Reads and logs temperature and humidity using a DHT22 sensor.  
Sensor is connected to an Arduino, communicating with LabVIEW via serial protocol.  

*Voltage Simulation*  
SOC changes simulated using a potentiometer to emulate voltage shifts.  

*SOC Range Duration Logging*  
Automatically tracks how long each battery remains in defined SOC bands:  
100–75%  
100–50%  
100–25%  
100–10%  
100–0%  

*Live Dashboard + Data Logging*  
User-friendly interface in LabVIEW.  
All data (OCVs, SOCs, temperature, humidity, SOC duration) is logged in structured CSV files.  

**LabVIEW Design and Programming Techniques**  
To ensure code maintainability, scalability, and performance, the LabVIEW application utilizes advanced development practices:  
State Machine (SM) for controlling test sequencing.  
Use of SubVIs for clean modular architecture.  
Queues for robust and non-blocking data communication between loops.  
Type Definitions (TypeDefs) to enforce consistent data structures.  
These techniques mirror professional LabVIEW development practices commonly used in test engineering environments.  

**System Requirements**  
LabVIEW (2019 or later recommended) and NI MAX  
Arduino Uno or Arduino Mega    
DHT22 Sensor  
Potentiometer  
NI-VISA drivers for serial communication  
Jumper wires  

**Getting Started**  
Connect Arduino with DHT22 sensor and potentiometer as per the provided schematic.  
Load the Arduino sketch to handle temperature/humidity and serial communication.  
Open the LabVIEW VI.  
Configure your battery parameters and start the session.  
Observe SOC, environmental conditions, and SOC band durations in real-time.  

📹 **Video Demonstration**  
Hardware Setup: https://drive.google.com/file/d/1hWF3CI3OBAQfrUSNdoTZlU4-vL8aGdto/view?usp=sharing  
Project in action:  https://drive.google.com/file/d/1drgNqLGD0UWKhNkB90gGlfV_svL5caQ1/view?usp=sharing

