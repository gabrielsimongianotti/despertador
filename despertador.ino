#include <virtuabotixRTC.h>           

// Determina os pinos ligados ao modulo
// myRTC(clock, data, rst)
virtuabotixRTC myRTC(6, 7, 8);
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);
void setup() {
  // tamanho do display
  lcd.begin (16,2);   
  Serial.begin(9600);
   // myRTC.setDS1302Time(segundos, minutos, hora, dia da semana, dia do mes, mes, ano)
  myRTC.setDS1302Time(20, 03, 18, 6, 23, 03, 2018);
 
  virtuabotixRTC myRTC(6, 7, 8);
  LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);
}

void loop() {
  // Le as informacoes do CI
  myRTC.updateTime(); 
  // liga display
  lcd.setBacklight(HIGH);
  hora();
  data();
}
void hora(){
  lcd.setCursor(0,0);
  lcd.print("Hora ");
  lcd.print(myRTC.hours);
  Serial.println(myRTC.hours);
  lcd.print(":");
  lcd.print(myRTC.minutes);
  lcd.print(":");
  lcd.print(myRTC.seconds);
  }
void data(){
  lcd.setCursor(0,1);
  lcd.print("Data ");
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
  lcd.print(myRTC.month);
  lcd.print("/");
  lcd.print(myRTC.year);
  }
