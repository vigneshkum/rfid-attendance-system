#include <Time.h>  
#include <Wire.h>  
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t

String welcomeMsg = "Welcome!";
#define TIME_HEADER  'T'   // Header tag for serial time sync message
#define REQ_HEADER  'F'
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
    //IF Time sync
    if( c == TIME_HEADER ) {
      TimeSyncFromPC();
    }
    //Else IF file sync
    else if( c == REQ_HEADER ) {
      //Send contents of file.
      processFileRequest();
    }
    //else error
    else{
      Display("Error in input",0);
    } 
  }
}
