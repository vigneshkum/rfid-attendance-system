void processFileRequest(){
        Serial.println("<");
        readFile();
        Serial.println(">");
}

void readFile(){
  String fileName = "logs/"+getDate()+".txt";
  char logFile[fileName.length()+1];
  fileName.toCharArray(logFile,fileName.length()+1);
  File file = SD.open(logFile);
  //File file = SD.open("users.txt");
  if(file){
    while(file.available()){
      Serial.write(file.read());
    }
  }else{
    Serial.print("error opening file -> ");
    Serial.println(logFile);
  }
  file.close();
}





