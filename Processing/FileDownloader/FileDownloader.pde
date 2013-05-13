import processing.serial.*;
int x = 0;
public static final short portIndex = 1; 
Serial myPort;
String date = "02102012";
PrintWriter output;
BufferedReader reader;
void setup() {  
  size(200, 400);
  background(255, 0, 0);
  println(Serial.list());
  println(" Connecting to -> " + Serial.list()[portIndex]);
  myPort = new Serial(this, Serial.list()[portIndex], 9600);
  reader = createReader("../anchor.txt");
  try {
    date = reader.readLine();
    trim(date);
  }
  catch (IOException e) {
    e.printStackTrace();
  }
  println(date);
  output = createWriter("../logs/"+date+".txt");
  myPort.write('F');  
}

void draw() {
  if (myPort.available()>0) {
    char temp = char(myPort.read());
    if (temp == '>') {
      background(0, 255, 0);
      println("End of File");
      output.close();
    }else{
      if (temp == '<') {
        //myPort.write(date);
        background(0, 0, 255);
      }
      else {
        output.print(temp);
        print(temp);
        textSize(14);
        text("Downloading..."+temp, 20, x+=20);
        if(x>height){
          x=0;
          background(0, 0, 255);
        }
      }
    }
  }
}

