import processing.serial.*;

public static final short portIndex = 1; 
Serial myPort;
PrintWriter output;

void setup() {  
  //size(200, 200);
  println(Serial.list());
  println(" Connecting to -> " + Serial.list()[portIndex]);
  myPort = new Serial(this, Serial.list()[portIndex], 9600);
  output = createWriter("../data/cardID.TXT");
  myPort.write("S");
  background(255, 0, 0);
}

void draw() {
  if (myPort.available()>0) {

    char temp = char(myPort.read());
    if (temp == '>') {
      background(0, 255, 0);
      println("\n End of File");
      output.close();
    }
    else {
      output.print(temp);
      print(temp);
    }
  }
}

