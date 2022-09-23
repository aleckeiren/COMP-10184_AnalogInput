/**
  I, Alec Pasion, 000811377 certify that this material is my original work. No other person's work has been used
  without due acknowledgement.
**/
#include <Arduino.h>
#include <math.h>
void setup() {
  Serial.begin(115200);
}
void loop() {
  int iVal; 
  // read digitized value from the D1 Mini's A/D convertor  
  iVal = analogRead(A0);

  float temperature = map(iVal,0,pow(2,10),0,1000)/20.00;
  String statement = "";
  if(temperature < 10){
    statement = "cold!";
  }else if (temperature <15 && temperature >= 10)
  {
    statement = "cool!";
  }else if (temperature <25 && temperature >=15)
  {
    statement = "perfect!";
  }else if (temperature <30 && temperature >=25)
  {
    statement = "warm!";
  }else if (temperature <35 && temperature >= 30)
  {
    statement = "hot!";
  }else {
    statement = "too hot!";
  }
  
  
  Serial.println("Digitized Value of " + String(int(iVal)) + " is equavalent to a temparature of " + String(temperature) +" which is " + statement); 
 
  // wait 0.5 seconds (500 ms) 
  delay(2000); 
}