#include <Time.h>  
#include <Wire.h>  
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t

String welcomeMsg = "Welcome!";
String err = "Error";
#define TIME_HEADER 'T'   // Header tag for serial time sync message
#define SWIPE_HEADER 'S'
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

  //Check if there is some incoming data and process headers
  if(Serial.available()){
    //Read the incoming character
    char c = Serial.read() ; 
    if(c==SWIPE_HEADER) {
      clearLCD();
      Display("Sending CardID",0);
      getSwipe();
    }
    if(c==TIME_HEADER) {
      clearLCD();
      Display("Time Sync!",0);
      delay(200);
      Serial.print("Time Sync c = ");
      Serial.println(c);
      TimeSyncFromPC();
    }

  } 
}




