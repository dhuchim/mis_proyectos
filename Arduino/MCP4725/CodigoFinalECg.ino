#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <LCD5110_Basic.h>
Adafruit_MCP4725 dac;
LCD5110 pantalla(8,9,10,12,11);
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

const uint8_t corazon[] PROGMEM={
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

int up=3;//boton para subir
int down=2;//boton para bajar
int cont=3;//indice de array para frecuencias
int pulsopush=130;//tiempo de espera para presionar el boton
int duracion[]={3000,2000,1500,1000,750,600,500,429,375,333,300,273,250,231,214,200};//duracion de la prueba de frecuencia
int frecuencias[]={20,30,40,60,80,100,120,140,160,180,200,220,240,260,280,300};//frecuencias para mostrar en pantalla
unsigned long tiempopush=0;//medidor de tiempo millis para push
unsigned long anterior=0;//medidor de tiempo millis para la prueba de frecuencia
//-----Variables de la señal
int ecg[]={390,441,475,490,495,504,473,434,387,385,377,339,328,340,236,545,802,1155,1424,1764,1393,1116,846,//84pts //linea de espacio a 390
623,69,11,97,241,326,375,405,431,453,476,501,516,532,550,567,605,635,652,695,715,743,774,799,819,841,866,879,
910,926,947,957,942,926,903,872,860,832,803,777,752,730,690,642,575,525,491,471,453,435,424,421,415,412,408,
408,416,416,399,389,361};
//-----Fin variables señal

void setup() {
  pantalla.InitLCD();
  pinMode(up,INPUT_PULLUP);//se configuran como pines pull-up
  pinMode(down,INPUT_PULLUP); // se configuran como pines pull-up
  attachInterrupt(digitalPinToInterrupt(up),mas,FALLING);//configuracion interrupcione por pines especiales
  attachInterrupt(digitalPinToInterrupt(down),menos,FALLING);//configuracion de interrupcion por pines especiales
  pantalla.setFont(SmallFont);
  pantalla.print("David Huchim", CENTER, 18);
  delay(1000);
  pantalla.clrScr();
  pantalla.drawBitmap(0, 0, firm, 80, 48);
  delay(1000);
  pantalla.clrScr();
  dac.begin(0x62);
  pantalla.drawBitmap(57, -7,corazon, 80, 48);//(X,Y,FIGURA,80,48)
  pantalla.setFont(SmallFont);
  pantalla.print("Frecuencia", CENTER, 0);
  pantalla.setFont(SmallFont);
  pantalla.print("bpm", 60, 40); //(tEXTO,X,Y)
  pantalla.setFont(BigNumbers);//999
  pantalla.printNumI(frecuencias[cont], 10, 18);
}

void loop() {
// si es la ECG[] el valor max es 186 y si es ECG2[] es de 92
for(int i=0;i<84;i++){
  dac.setVoltage(ecg[i], false);
    }
// espacios entre señales
anterior=millis();
while(millis()-anterior<=(duracion[cont]-12)){
  int espacio=390;
  dac.setVoltage(espacio, false);
  }
}
//----CONTADOR POR INTERRUPCION-----
void mas(){ // para aumentar la frecuencia de la señal
if (millis() > tiempopush + pulsopush){
  cont++;
  if(cont>=15){
  cont=15;}
  tiempopush = millis();}
  pantalla.clrScr();
  pantalla.drawBitmap(57, -7, corazon, 80, 48);//(X,Y,FIGURA,80,48)
  pantalla.setFont(SmallFont);
  pantalla.print("Frecuencia", CENTER, 0);
  pantalla.setFont(SmallFont);
  pantalla.print("bpm", 60, 40); //(texto,X,Y)
  pantalla.setFont(BigNumbers);//999
  pantalla.printNumI(frecuencias[cont], 10, 18);
  }
void menos(){ //para disminuir la frecuencia de la señal
if (millis() > tiempopush + pulsopush){
  cont--;
  if(cont<=0){
  cont=0;}
  tiempopush = millis();}
  pantalla.clrScr();
  pantalla.drawBitmap(57, -7, corazon, 80, 48);//(X,Y,FIGURA,80,48)
  pantalla.setFont(SmallFont);
  pantalla.print("Frecuencia", CENTER, 0);
  pantalla.setFont(SmallFont);
  pantalla.print("bpm", 60, 40); //(texto,X,Y)
  pantalla.setFont(BigNumbers);//999
  pantalla.printNumI(frecuencias[cont], 10, 18);
}
