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
  pinMode(10, OUTPUT);
  if(debug){
    Serial.print("Initializing SD card...");
  }
  if (!SD.begin(CS)) {
    Serial.println("initialization failed!");
    return;
  }
  if(debug){
    Serial.println("initialization done.");
  }
}

void logAttendance(char file[], byte cardID[]){
  File logFile = SD.open(file, FILE_WRITE);
  if (logFile){
    logFile.print(getTimeStamp());
    logFile.print(",");
    for(int i=0;i<12;i++){
      logFile.write(cardID[i]);
      delay(2);
    }
    logFile.println("");
    logFile.close();

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


