void initTime(){
  //setTime(hh,mm,ss,DD,MM,YYYY);
  //setTime(02,03,30,25,07,2012);
  setSyncProvider(RTC.get);   // the function to get the time from the RTC
  setSyncInterval(30000);
  if(timeStatus()!= timeSet){ 
     if(debug){
       Serial.println("Unable to sync with the RTC");
     }
     Display("Time not Synced",0);
  }
  else{
    if(debug){
       Serial.println("RTC has set the system time");      
    }
  }
}

String getTime(){
  time_t t = now();
  String cur_time = fix(day(t))+"/"+fix(month(t));
  cur_time += " - "+fix(hour(t))+":"+fix(minute(t))+":"+fix(second(t));
  return cur_time;
}

String getTimeStamp(){
  time_t t = now();
  String cur_time = fix(hour(t))+":"+fix(minute(t))+":"+fix(second(t));
  return cur_time;
}

String getDate(){
  time_t t = now();
  String date = fix(day(t))+fix(month(t))+fix(year(t));
  return date;
}

//To prepend zero for single digit characters
String fix(int val){
  if(val<10){
    return "0"+String(val);
  }
  else{
    return String(val);
  }
}

void TimeSyncFromPC(){
     time_t t = processSyncMessage();
     if(t >0)
     {
        RTC.set(t);   // set the RTC and the system time to the received value
        setTime(t);          
     }
}

/*  code to process time sync messages from the serial port   */
#define TIME_MSG_LEN  11   // time sync to PC is HEADER followed by unix time_t as ten ascii digits


time_t processSyncMessage(){
  // return the time if a valid sync message is received on the serial port.
  while(Serial.available() >=  TIME_MSG_LEN ){  // time message consists of a header and ten ascii digits 
      char c;
      time_t pctime = 0;
      for(int i=0; i < TIME_MSG_LEN -1; i++){   
        c = Serial.read();          
        if( c >= '0' && c <= '9'){   
          pctime = (10 * pctime) + (c - '0') ; // convert digits to a number    
        }
      }   
      return pctime; 
  }
  return 0;
}


