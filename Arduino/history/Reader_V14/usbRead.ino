#define REQ_MSG_LEN  8

char rFile[REQ_MSG_LEN];
int processFileRequest(){
  while(Serial.available() >=  REQ_MSG_LEN ){  
    //char c = Serial.read() ; 
    //Serial.print(c);
    //if( c == REQ_HEADER ) {  
      for(int i=0; i < REQ_MSG_LEN; i++){   
        rFile[i] = Serial.read();     
      } 
      Serial.println("<");  
      readFile(rFile);
      Serial.println(">");
      return 1; 
    //}  
  }
  return 0;  
}

void readFile(char rFile[]){
  Serial.println(rFile);
}





