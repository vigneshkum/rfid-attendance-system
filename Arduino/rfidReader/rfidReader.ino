//Control Variables
boolean deviceReady = true;
boolean debugMode = true;
//Welcome Message
String msg = "Welcome!";
//Header Messages
#define SWIPE_HEADER 'S'

//Initialization Function
void setup() {
  Serial.begin(9600);
  if(debugMode){
    Serial.println("<==========Device Booted!==========>");
    Serial.print("setup() :: ");
    Serial.println("Now Initializing Dependent Modules and Hardware.");
  }
  //Initializing Hardware Modules
  //initTime();
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
  Display(msg,0);
}

void loop() {
  if(deviceReady){
    checkRFID();

    //Request Handler Code
    if(Serial.available()){
      //Read the incoming character
      char c = Serial.read() ; 
      if(c==SWIPE_HEADER) {
        clearLCD();
        Display("Sending CardID",0);
        getSwipe();
      }
    }
  }
}


















