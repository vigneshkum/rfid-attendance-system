#include <Time.h>  
#include <Wire.h>  
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t

boolean deviceReady = true;
boolean debugMode = false;
String welcomeMsg = "Welcome!";
String timeBuff = ".";
#define TIME_HEADER 'T'   // Header tag for serial time sync message
#define SWIPE_HEADER 'S'
#define verbose 0

void setup() {
  Serial.begin(9600);
  if(debugMode){
    Serial.println("<==========Device Booted!==========>");
    Serial.print("setup() :: ");
    Serial.println("Now Initializing Dependent Modules and Hardware.");
  }
  //Initializing Hardware Modules
  initTime();
  initMemory();
  initRFID();
  initDisplay();
  //Print Status Message After initialization
  if(debugMode){
    if(deviceReady){
      Serial.print("setup() :: ");
      Serial.println("All Hardware is OK and Ready to Use.");  
    }
    else{
      Serial.print("setup() :: ");
      Serial.println("Hardware Falied! Please check logs and RFID Reader is Disabled unless all Hardware is OK.");  
    }
    Serial.println("<==========End of SETUP()==========>");
  }
  // Print Welcome message to the LCD.
  Display(welcomeMsg,0);
}

void loop() {
  if(deviceReady){
    /*
    checkRFID();
     */
    Display(getTime(),1);
    /*
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
     if(debugMode){
     Serial.print("Time Sync c = ");
     Serial.println(c);
     }
     TimeSyncFromPC();
     }
     
     } 
     */
  }
}














