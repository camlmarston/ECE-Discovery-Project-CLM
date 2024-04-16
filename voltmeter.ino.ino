#include "LiquidCrystal.h"

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

float inputVoltage = 0.0; 

void setup() {
  Serial.begin(9600);        
  lcd.begin(16, 2);           
}

void loop() {
  int analogVal = analogRead(A0);                    
  inputVoltage = (analogVal * 5.0) / 1023.0; //arduino reads analog voltage as value b/t (0,1023), need to convert to measurement in volts. 5V is the refrence voltage, divide by the number of possible readings
  
  if (inputVoltage < 0.05) {         //filter noise
    inputVoltage = 0;                                
  }

  Serial.print("v= ");
  Serial.println(inputVoltage);

  lcd.setCursor(0, 0);
  lcd.print("voltage = ");
  lcd.print(inputVoltage);
  delay(500);
  
}
