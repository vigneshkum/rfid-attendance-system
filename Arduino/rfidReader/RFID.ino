#include <SoftwareSerial.h>

// The RFID module's TX pin needs to be connected to the Arduino. 
#define rxPin 8 // RFID pin 3 (RED)
#define txPin 9 // RFID pin 2 (BLACK)

// Global Variables
byte cardID[12];
byte rfidCount = 0;
// Create a software serial object for the connection to the RFID module
SoftwareSerial rfid = SoftwareSerial( rxPin, txPin );

void initRFID(){
  if(debugMode){
    Serial.print("initRFID() :: ");
  }
  rfid.begin(9600);
  if(debugMode){
    Serial.println("Connected to RFID Scanner.");
  }
}

void checkRFID(){
  //Store CardID in an array
  if(rfid.available()){
    cardID[rfidCount++]=rfid.read();
    delay(5);
    //Serial.write(rfid.read());
  }
  if(rfidCount==12){
    //Reset for new entry
    rfidCount=0;
    if(debugMode){
      Serial.print("checkRFID() :: ");
      Serial.print("CardID = ");
      printCardID();
      Serial.println();
    }
    //Log CardID with TimeStamp
    /* Write CODE */
    //Display User on the LCD Display
    displayCardID(cardID);
    delay(1000);
    /*
    clearLCD();
     delay(50);
     getUser(cardID);
     */
    delay(2000);
    clearLCD();
    delay(50);
    Display(msg,0);
    delay(30);
  }
}

void printCardID(){
  for(int i=0;i<12;i++)
    Serial.write(cardID[i]);
}









