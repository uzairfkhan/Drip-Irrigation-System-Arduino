#define soilWet 500   // Define max value we consider soil 'wet'

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int output_value1 ;
int output_value2 ;
int output_value3 ;

// Sensor pins
#define sensor1Pin A0
#define sensor2Pin A1
#define sensor3Pin A2
#define pump1Pin 8
#define pump2Pin 7
#define pump3Pin 6




void setup() {
 
  pinMode(sensor1Pin, INPUT);
  pinMode(sensor2Pin, INPUT);
  pinMode(sensor3Pin, INPUT);
  pinMode(pump1Pin, OUTPUT);
  pinMode(pump2Pin, OUTPUT);
  pinMode(pump3Pin, OUTPUT);
   lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Moisture Levels");

 
 
 
 
 
  Serial.begin(9600);
}


void loop() {
// set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
 

 
  //get the reading from the function below and print it
  int moisture1 = analogRead(sensor1Pin);
  int moisture2 = analogRead(sensor2Pin);
  int moisture3 = analogRead(sensor3Pin);
  /*Serial.print("Analog Output of Sensor 1 : ");
  Serial.println(moisture1);
   Serial.print("Analog Output of Sensor 2 : ");
  Serial.println(moisture2);
   Serial.print("Analog Output of Sensor 3 : ");
  Serial.println(moisture3);*/

  output_value1 = analogRead(sensor1Pin);

  output_value1 = map(output_value1, 1023, 165, 0, 100);

  Serial.print("Plant 1 : ");

  Serial.print(output_value1);

  Serial.println("%");

  output_value2 = analogRead(sensor2Pin);

  output_value2 = map(output_value2, 1023, 165, 0, 100);

  Serial.print("Plant 2 : ");

  Serial.print(output_value2);

  Serial.println("%");

  output_value3 = analogRead(sensor3Pin);

  output_value3 = map(output_value3, 1023, 165, 0, 100);

  Serial.print("Plant 3 : ");

  Serial.print(output_value3);

  Serial.println("%");

 


 



  // Determine status of our soil
  if (moisture1 < soilWet && moisture2<soilWet && moisture3<soilWet) {
    digitalWrite(pump1Pin,LOW);
    digitalWrite(pump2Pin,LOW);
    digitalWrite(pump3Pin,LOW);
   
   
  }
  else if (moisture1 > soilWet && moisture2 > soilWet && moisture3 > soilWet) {
    digitalWrite(pump1Pin,HIGH);
    digitalWrite(pump2Pin,HIGH);
    digitalWrite(pump3Pin,HIGH);
   
  }
  else if (moisture1 >= soilWet && moisture2 < soilWet && moisture3 < soilWet) {
    digitalWrite(pump1Pin,HIGH);
    digitalWrite(pump2Pin,LOW);
    digitalWrite(pump3Pin,LOW);
   
   
  }
  else if (moisture1 < soilWet && moisture2 >= soilWet && moisture3 < soilWet) {
    digitalWrite(pump1Pin,LOW);
    digitalWrite(pump2Pin,HIGH);
    digitalWrite(pump3Pin,LOW);
   
  }
  else if (moisture1 < soilWet && moisture2 < soilWet && moisture3 > soilWet) {
    digitalWrite(pump1Pin,LOW);
    digitalWrite(pump2Pin,LOW);
    digitalWrite(pump3Pin,HIGH);
  }
  else if (moisture1 > soilWet && moisture2 > soilWet && moisture3 < soilWet) {
    digitalWrite(pump1Pin,HIGH);
    digitalWrite(pump2Pin,HIGH);
    digitalWrite(pump3Pin,LOW);
  }
  else if (moisture1 < soilWet && moisture2 > soilWet && moisture3 > soilWet) {
    digitalWrite(pump1Pin,LOW);
    digitalWrite(pump2Pin,HIGH);
    digitalWrite(pump3Pin,HIGH);
   
  }
  else if (moisture1 > soilWet && moisture2 < soilWet && moisture3 > soilWet) {
    digitalWrite(pump1Pin,HIGH);
    digitalWrite(pump2Pin,LOW);
    digitalWrite(pump3Pin,HIGH);
  }
 lcd.clear();
 lcd.setCursor(0, 0); // top left
 lcd.print("Moisture Level");
 lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("Plant 1 : ");
  lcd.print(output_value1);
  lcd.print(" %");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0); // top left
 lcd.print("Moisture Level");
  lcd.setCursor(0, 1);
  lcd.print("Plant 2 : ");
  lcd.print(output_value2);
  lcd.print(" %");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0); // top left
  lcd.print("Moisture Level");
  lcd.setCursor(0, 1);
  lcd.print("Plant 3 : ");
  lcd.print(output_value3);
  lcd.print(" %");
  delay(3000);
  lcd.clear();
 
 
 
  //delay(2000);  
         
  Serial.println();
}