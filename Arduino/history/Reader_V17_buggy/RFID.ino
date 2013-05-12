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
  rfid.begin(9600);
}

void checkRFID(){
  //Store CardID in an array
  if(rfid.available()){
    cardID[rfidCount++]=rfid.read();
    delay(5);
    //Serial.write(rfid.read());
  }
  if(rfidCount==12){
    //Log card entry to the Memory Card
    //Generate Filename
    String fileName = "logs/"+getDate()+".txt";
    char logFile[fileName.length()+1];
    fileName.toCharArray(logFile,fileName.length()+1);
    //log attendance
    logAttendance(logFile,cardID);
    delay(20);
    //Display User on the LCD Display
    displayCardID(cardID);
    delay(1000);
    clearLCD();
    getUser(cardID);
    delay(20);
    //comment this code
    printCardID();
    Serial.println("");
    Serial.println("About to display time");
    timeBuff = getTime();
    Serial.print("Value of timeBuff = ");
    Serial.println(timeBuff);
    Display(timeBuff,1);
    delay(2000);
    //Reset for new entry
    rfidCount=0;
    clearLCD();
    delay(50);
    Display(welcomeMsg,0);
    delay(30);
  }
}

void printCardID(){
  for(int i=0;i<12;i++)
    Serial.write(cardID[i]);
}







