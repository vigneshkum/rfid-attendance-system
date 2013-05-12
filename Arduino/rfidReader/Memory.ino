#include <SD.h>

/* The circuit:
 * SD card attached to SPI bus as follows: 
 ** CS   - CS  - pin 10
 ** MOSI - DI  - pin 11 
 ** MISO - D0  - pin 12  
 ** CLK  - SCK - pin 13 
 */

#define CS 10

void initMemory(){
  if(debugMode){
    Serial.print("initMemory() :: ");
  }
  pinMode(10, OUTPUT);
  if(debugMode){
    Serial.print("Initializing SD card... => ");
  }
  if (!SD.begin(CS)) {
    Serial.println("SD Card initialization Failed!");
    welcomeMsg = "No Memory Card?";
    //Display("No Memory Card?",0);
    //Disable the RFID READER
    deviceReady = false;
    return;
  }
  if(debugMode){
    Serial.println("Memory Card is Ready.");
  }
}

void logAttendance(char file[], byte cardID[]){
  File logFile = SD.open(file, FILE_WRITE);
  delay(20);
  if (logFile){
    logFile.print(getTimeStamp());
    delay(5);
    logFile.print(",");
    delay(5);
    for(int i=0;i<12;i++){
      logFile.write(cardID[i]);
      delay(5);
    }
    logFile.println("");
    delay(5);
    logFile.close();
    delay(5);

    //Print output to console
    if(verbose){
      //Print log on serial port
      Serial.print(file);
      Serial.print(" -> ");
      Serial.print(getTimeStamp());
      Serial.print(",");
      printCardID();
      Serial.println(";");
    }
  }
  else{
    Serial.print("error opening -> ");
    Serial.println(file);
  }
}


