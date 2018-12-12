#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <LCD5110_Basic.h>
Adafruit_MCP4725 dac;
LCD5110 myGLCD(8,9,10,11,12);
extern uint8_t SmallFont[];   
extern uint8_t BigNumbers[];
const uint8_t firm[] PROGMEM={
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0,
0xC0, 0xE0, 0xF0, 0xF8, 0x7C, 0x3C, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0x7E, 0x3E, 0x9F, 0x8F,
0x87, 0x83, 0xC1, 0xC0, 0xE0, 0xE0, 0xF0, 0xF0, 0xF0, 0xF0, 0xE0, 0x00, 0x00, 0x80, 0xC0, 0xC0,
0xE0, 0xF0, 0xF0, 0x78, 0x78, 0x3C, 0x3E, 0x1E, 0x0F, 0x0F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x04, 0x8E, 0xCE, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x0F, 0x07, 0x87,
0xC3, 0xE0, 0xF0, 0xF8, 0x7C, 0x3E, 0x1F, 0x1F, 0x1F, 0x1F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x07,
0x07, 0x07, 0x07, 0x83, 0xC1, 0xE1, 0xF0, 0xF1, 0xFF, 0xFF, 0xFF, 0x1F, 0x0F, 0x07, 0x07, 0x03,
0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xE0, 0xF0,
0xF8, 0x7C, 0x3E, 0x1E, 0x0F, 0x0F, 0x87, 0xC3, 0xE1, 0xF0, 0xF8, 0x7C, 0x3C, 0x3F, 0x0F, 0x0F,
0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8,
0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x1F, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0xF0, 0xFC, 0x7E, 0x3F, 0x1F, 0x0F, 0x87, 0xC3, 0xE1,
0xE0, 0xF0, 0x78, 0x7C, 0x3E, 0x1F, 0x0F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07,
0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x1C, 0x3F, 0x7F, 0x7F, 0x7B, 0x38, 0x3C, 0x3E, 0x1E, 0x0F, 0x0F, 0x07, 0x03,
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t heart[] PROGMEM={
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0xF0, 0xF8, 0xFC, 0xFC, 0xFE, 0xFE, 0xFE, 0xFC, 0xFC, 0xF8, 0x18, 0xFC, 0xFC,
0xFE, 0xFE, 0xFE, 0xFC, 0xFC, 0xF8, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x08, 0x0B, 0x0F, 0x0F, 0x2F, 0x6F, 0xE7, 0xF9, 0xF1, 0xCF, 0xF1, 0xFC, 0xE1, 0x9F,
0xEF, 0xEF, 0x6F, 0x2F, 0x2F, 0x2F, 0x23, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x0F, 0x07, 0x03,
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

int up=2;//boton para subir
int down=3;//boton para bajar
int cont=55;//tiempo entre señales
int pulsopush=130;//tiempo de espera para presionar el boton
int duracion=1000;//duracion de la prueba de frecuencia
unsigned long tiempopush=0;//medidor de tiempo millis para push
unsigned long anterior=0;//medidor de tiempo millis para la prueba de frecuencia
//-----Variables de la señal
int ecg[]={258,258,258,258,258,258,258,259,259,262,264,267,270,273,276,279,282,285,288,292,// esta señal logra 2 formas por segundo
295,298,301,303,306,308,311,313,315,317,319,320,323,325,326,327,326,326,325,323,322,321,319,316,314,312,309,306,303,301,299,296,
294,290,287,284,283,280,277,274,271,267,264,261,259,256,255,255,255,255,255,256,256,256,256,256,248,240,217,202,178,169,194,225,295,359,555,
797,600,490,367,274,173,87,118,138,157,171,186,198,215,231,247,257,258,258,259,258,259,259,259,258,268,271,276,278,284,288,294,298,301,307,313,317,320,325,328,335,338,
341,344,349,350,355,355,359,359,361,362,362,363,362,360,358,355,354,352,348,344,341,339,336,334,331,329,326,324,320,315,312,309,304,302,300,
295,289,286,282,276,271,267,263,259,257,257,257,257,257,257,258,257,256,257,257,256,257,};

int ecg2[]={258,260,259,260,// esta señal logra 3 formas por segundo 
265,267,271,276,283,289,292,295,298,306,311,314,315,317,325,326,
327,327,326,324,323,321,319,314,309,306,299,287,285,277,274,265,
262,258,256,255,260,256,180,160,180,295,359,555,797,600,491,367,
275,216,88,178,258,260,259,268,272,279,284,295,302,307,315,
320,330,340,349,355,362,363,360,356,350,349,339,334,320,313,305,
287,283,277,262,259,257,257,256,255};
//-----Fin variables señal

void setup() {
  myGLCD.InitLCD();
  dac.begin(0x62);
  Serial.begin(9600);
  myGLCD.setFont(SmallFont);
  myGLCD.print("David Huchim", CENTER, 18);
  delay(1000);
  myGLCD.clrScr();
  myGLCD.drawBitmap(0, 0, firm, 80, 48);
  delay(1000);
  myGLCD.clrScr();
  pinMode(up,INPUT_PULLUP);
  pinMode(down,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(up),mas,FALLING);
  attachInterrupt(digitalPinToInterrupt(down),menos,FALLING);
  
}

void loop() {
//sirve para ajustar espacio entre ondas
for(int t=0;t<cont;t++){
    int espacio=258;
    dac.setVoltage(espacio, false);
    //Serial.println(espacio);
    }
// si es la ECG[] el valor max es 186 y si es ECG2[] es de 92
for(int i=0;i<92;i++){
  dac.setVoltage(ecg2[i], false);
    //Serial.println(ecg2[i]);
  }
//sirve para ajustar espacio entre ondas
for(int t=0;t<cont;t++){
    int espacio=258;
    dac.setVoltage(espacio, false);
  //Serial.println(espacio);
    }
//-----------------------------------
////-medir cuantos pulsos se hacen en un tiempo dado en milisegundos
//anterior=millis();
//while(millis()-anterior<=duracion){
//  for(int t=0;t<cont/2;t++){
//    int espacio=258;
//    Serial.println(espacio);
//    }
//  for(int i=0;i<92;i++){// si es la ECG[] el valor max es 186 y si es ECG2[] es de 92
//    Serial.println(ecg2[i]);
//  }
//  for(int t=0;t<cont/2;t++){
//    int espacio=258;
//    Serial.println(espacio);
//    }
//}
//delay(100000);
 //--------------------------------------
}


//----CONTADOR POR INTERRUPCION-----
void mas(){
if (millis() > tiempopush + pulsopush){
  cont=cont+5;
  if(cont>=395){
  cont=400;}
tiempopush = millis();}
   myGLCD.clrScr();
   myGLCD.drawBitmap(57, -7, heart, 80, 48);//(X,Y,FIGURA,80,48)
  myGLCD.setFont(SmallFont);
  myGLCD.print("Frecuencia", CENTER, 0);
  myGLCD.setFont(SmallFont);
  myGLCD.print("bpm", 60, 40); //(tEXTO,X,Y)
  myGLCD.setFont(BigNumbers);//999
  myGLCD.printNumI(cont, 10, 18);
  
  }
void menos(){
if (millis() > tiempopush + pulsopush){
  cont=cont-5;
  if(cont<=0){
   cont=0;}
tiempopush = millis();}
  myGLCD.clrScr();
  myGLCD.drawBitmap(57, -7, heart, 80, 48);//(X,Y,FIGURA,80,48)
  myGLCD.setFont(SmallFont);
  myGLCD.print("Frecuencia", CENTER, 0);
  myGLCD.setFont(SmallFont);
  myGLCD.print("bpm", 60, 40); //(tEXTO,X,Y)
  myGLCD.setFont(BigNumbers);//999
  myGLCD.printNumI(cont, 10, 18);
  
   }
