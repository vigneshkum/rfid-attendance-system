#include <Time.h>  
#include <Wire.h>  
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t

String welcomeMsg = "Welcome!";

#define debug 0
#define verbose 0
void setup() {
  Serial.begin(9600);
  initTime();
  initMemory();
  initRFID();
  initDisplay();

  // Print Welcome message to the LCD.
  Display(welcomeMsg,0);
}

void loop() {

  checkRFID();

  Display(getTime(),1);
  
  checkTimeSyncFromPC();
  
  processRequest();
}
