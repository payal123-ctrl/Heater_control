# Heater_control
This is the heater control system.
<br>
Author-->Payal Mahure
<br>
Click here to simulate----> https://wokwi.com/projects/438101362340700161
<br>
Heater Control System using Arduino and LM35
<br>
 Overview
 <br>

This project is a temperature-controlled heater system that uses an LM35 analog temperature sensor, an Arduino Uno, and a relay module to switch the heater ON or OFF based on the sensed temperature. The system also uses LED indicators to show the current status of the heater and handle overheat conditions for safety.
<br>

Component	        Description
<br>
Arduino Uno	 -->     Main microcontroller that reads temperature via ADC and controls the relay
<br>
LM35	        --> Analog temperature sensor (10 mV/°C output)
<br>
Relay Module	--> Electrically isolates and controls high-voltage heater switching
<br>
Heater	      --> Any resistive heating element powered via relay
<br>
LEDs	        --> Visual indicators for heater status and overheat alert
<br>
Power Supply	 -> 5V DC for Arduino, LM35, and Relay module (external supply for heater if needed)
<br>

Features:
<br>
 Real-Time Temperature Monitoring using LM35 sensor
<br>
🔄 Automatic Heater ON/OFF control based on temperature setpoint and hysteresis
<br>
🚨 Overheat Protection with status LED or buzzer
<br>
🔌 Relay Switching to control external heater circuit safely
<br>
📶 Analog-to-Digital Conversion using Arduino’s 10-bit ADC (0–1023 range)
<br>
🛠️ Modular Design for easy integration and testing in simulation (Wokwi or Proteus)

