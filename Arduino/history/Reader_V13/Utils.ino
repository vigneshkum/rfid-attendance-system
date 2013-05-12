int getUser(byte cardID[]){
  boolean exit = false;
  File file = SD.open("users.txt");
  if(file){
    byte buff = 0;
    byte index = 0;
    while(file.available()){
      buff = file.read();
      if(char(buff)!=','){
        if(buff==cardID[index]){
          index++;          
          if(index==12){         
            buff = file.read();
            buff = file.read();
            byte count = 0;
            while(char(buff)!=';' && file.available()){            
              //writeLCD(byte data,int row, int col);
              writeLCD(buff,0,count++);
              buff = file.read();
            }
            exit = true;
          }
        }
      }
      else{
        //Skip the entire row
        while(char(buff)!=';' && file.available()){         
          buff = file.read();
        }
        if(file.available()){
          buff = file.read();
        }      
        index=0;
      }
      if(exit){
        //break;
        file.close();
        return 1;
      }
    }
    file.close();
  }
  else{
    Serial.println("error opening -> users.txt ");
    //Serial.println(file); 
  }
  return 0;
}









