Apparatus:
•	2 x Arduino Uno
•	2 x 16*2 LCD
•	2 x 5k Variable Resistance
•	3 x Hygrometer Soil Moisture Sensor
•	3 x 12 V Diaphragm Water Pump
•	1 x DHT11 Temp and Hum Sensor
•	Cables M2M
•	Cables M2F
•	2 x Breadboard
•	2 x A to B Cables
•	Water Tubes
•	3 Pots
•	2 Containers
•	Power Supply
Construction:
BREADBOARD 1
3 Moisture sensors are connected to Arduino with their probes buried in soil of plants and their Analog output given to Analog pins of Arduino. Similarly 3 pumps are connected with their ground in Arduino and other end to Digital Pins of Arduino. An LCD is also connected to show the moisture levels of plants via 5k variable resistance. We can adjust brightness of LCD via Variable Resistance.
Pins are given below :
   sensor1Pin = A0
   sensor2Pin = A1
   sensor3Pin = A2
   pump1Pin = 8
   pump2Pin = 7
   pump3Pin = 6
   LCD RS pin to digital pin 12
   LCD Enable pin to digital pin 11
   LCD D4 pin to digital pin 5
   LCD D5 pin to digital pin 4
   LCD D6 pin to digital pin 3
   LCD D7 pin to digital pin 2
  
 Breadboard 2
On the second breadboard DHT11 is connected to Arduino. A LCD is also connected to show temperature and humidity of the room containing plants via Variable Resistance.
Pins are given below
   DHT11 pin = 8
   LCD RS pin to digital pin 12
   LCD Enable pin to digital pin 11
   LCD D4 pin to digital pin 5
   LCD D5 pin to digital pin 4
   LCD D6 pin to digital pin 3
   LCD D7 pin to digital pin
Working:
Arduino 1 is coded in such a way that every sensor is connected to its respective pump. Whenever the moisture level of a certain pot goes below 500 , its respective pump starts action and water is given to that specific plant. LCD shows the moisture level of every plant one by one. The Second Arduino is coded in such a way that it takes input from DHT11 sensor and gives out output in form of temperature and humidity on LCD. Brightness of both LCD’s can be set by the respective Variable resistance connected to it.
