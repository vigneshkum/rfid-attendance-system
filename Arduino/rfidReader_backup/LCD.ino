#include <LiquidCrystal.h>
#define d7 2
#define d6 3
#define d5 4
#define d4 5
#define enable 6
#define rs 7
// Create Object of LCD
//LiquidCrystal lcd(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7);
//LiquidCrystal lcd(rs, rw, enable, d4, d5, d6, d7);
LiquidCrystal lcd(rs, enable, d4, d5, d6, d7);

void initDisplay(){
  if(debugMode){
    Serial.print("initDisplay() :: ");
  }
  // LCD Settings
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  clearLCD();
  if(debugMode){
    Serial.println("LCD Display is ready!");
  }
}

void Display(String data,int row){
  lcd.setCursor(0, row);
  lcd.print(data); 
}
void Display(int data,int row){
  lcd.setCursor(0, row);
  lcd.print(data); 
}
void Display(String data,int row, int col){
  lcd.setCursor(col, row);
  lcd.print(data); 
}

//To print Hex Values
void writeLCD(byte data,int row, int col){
  lcd.setCursor(col, row);
  lcd.write(data); 
}

void clearLCD(){
  lcd.clear();
}

void displayCardID(byte cardID[]){
  for(int i=0;i<12;i++)
    writeLCD(cardID[i],0,i);
}

