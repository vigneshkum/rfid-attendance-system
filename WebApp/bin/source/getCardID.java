import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class getCardID extends PApplet {



public static final short portIndex = 1; 
Serial myPort;
PrintWriter output;

public void setup() {  
  //size(200, 200);
  println(Serial.list());
  println(" Connecting to -> " + Serial.list()[portIndex]);
  myPort = new Serial(this, Serial.list()[portIndex], 9600);
  output = createWriter("../data/cardID.TXT");
  myPort.write("S");
  background(255, 0, 0);
}

public void draw() {
  if (myPort.available()>0) {

    char temp = PApplet.parseChar(myPort.read());
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

  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "getCardID" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
