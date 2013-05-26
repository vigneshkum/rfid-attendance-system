int displayUser(byte cardID[]){
  Display("Searching...",0);
  if(debugMode){
    Serial.print("userName = ");
  }
  boolean exit = false;
  File file = SD.open("userdb.txt");
  if(file){
    byte buff = 0;
    byte index = 0;
    while(file.available()){
      buff = file.read();
      delay(2);
      if(char(buff)!=','){
        if(buff==cardID[index]){
          index++;          
          if(index==12){
            clearLCD();  
            //remove commna after cardID       
            buff = file.read();
            delay(2);
            buff = file.read();
            delay(2);
            byte count = 0;
            while(char(buff)!=';' && file.available()){            
              //writeLCD(byte data,int row, int col);
              writeLCD(buff,0,count++);
              delay(2);
              if(debugMode){
                Serial.write(buff);
              }
              buff = file.read();
              delay(2);
            }
            //exit = true;
            //Serial.println("Exiting the getUser Function");
            if(debugMode){
              Serial.println(";");
            }
            file.close();
            delay(2);
            return 1;
          }
        }
      }
      else{
        //Skip the entire row
        while(char(buff)!=';' && file.available()){         
          buff = file.read();
          delay(2);
        }
        if(file.available()){
          buff = file.read();
          delay(2);
        }      
        index=0;
      }
      if(exit){
        //break;
        file.close();
        delay(2);
        return 1;
      }
    }
    file.close();
    delay(2);
  }
  else{
    Serial.println("error opening -> usersdb.txt ");
    //Serial.println(file); 
  }
  clearLCD();
  delay(2);
  Display("Unkown?",0);
  if(debugMode){
    Serial.println("Unknown?");
  }
  return 0;
}
















