#include <MCP4922.h>
#include <SPI.h>
int pinSCK=13;
int pinSDI=11;
int pinLDAC=5;
MCP4922 DAC1(pinSDI,pinSCK,10,pinLDAC);    // (MOSI,SCK,CS,LDAC) define Connections for UNO_board, SCK=13,SDI/MOSI=11 y LDAH=5
MCP4922 DAC2(pinSDI,pinSCK,9,pinLDAC);   // (MOSI,SCK,CS,LDAC) define Connections for UNO_board, 
MCP4922 DAC3(pinSDI,pinSCK,8,pinLDAC);    // (MOSI,SCK,CS,LDAC) define Connections for UNO_board, 

int up=2;//boton para subir
int down=3;//boton para bajar
int cont=16;//tiempo entre señales
int pulsopush=130;//tiempo de espera para presionar el boton
int duracion[]={3000,2000,1500,1000,750,600,500,429,375,333,300,273,250,231,214,200,50};//duracion de la prueba de frecuencia
unsigned long tiempopush=0;//medidor de tiempo millis para push
unsigned long anterior=0;//medidor de tiempo millis para la prueba de frecuencia
//-----Variables de la señal
int ecg[]={258,258,258,258,258,258,258,259,259,262,264,267,270,273,276,279,282,285,288,292,// esta señal logra 2 formas por segundo
295,298,301,303,306,308,311,313,315,317,319,320,323,325,326,327,326,326,325,323,322,321,319,316,314,312,309,306,303,301,299,296,
294,290,287,284,283,280,277,274,271,267,264,261,259,256,255,255,255,255,255,256,256,256,256,256,248,240,217,202,178,169,194,225,295,359,555,
797,600,490,367,274,173,87,118,138,157,171,186,198,215,231,247,257,258,258,259,258,259,259,259,258,268,271,276,278,284,288,294,298,301,307,313,317,320,325,328,335,338,
341,344,349,350,355,355,359,359,361,362,362,363,362,360,358,355,354,352,348,344,341,339,336,334,331,329,326,324,320,315,312,309,304,302,300,
295,289,286,282,276,271,267,263,259,257,257,257,257,257,257,258,257,256,257,257,256,257,};

int ecg2[]={390,441,475,490,495,504,473,434,387,385,377,339,328,340,236,545,802,1155,1424,1764,1393,1116,846,//84pts //linea de espacio a 390
623,69,11,97,241,326,375,405,431,453,476,501,516,532,550,567,605,635,652,695,715,743,774,799,819,841,866,879,
910,926,947,957,942,926,903,872,860,832,803,777,752,730,690,642,575,525,491,471,453,435,424,421,415,412,408,
408,416,416,399,389,361};
//-----Fin variables señal


void setup()
{
 // Serial.begin(9600);
  SPI.begin();
  pinMode(up,INPUT_PULLUP);
  pinMode(down,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(up),mas,FALLING);
  attachInterrupt(digitalPinToInterrupt(down),menos,FALLING);
}

void loop()
{
  
 for(int i=0;i<84;i++){
   DAC1.Set(ecg2[i],ecg2[i]);
   
    }
    anterior=millis();
while(millis()-anterior<=(duracion[cont]-12)){
  DAC1.Set(390,390);
  
  }
}
 
  

//----CONTADOR POR INTERRUPCION-----
void mas(){
if (millis() > tiempopush + pulsopush){
  cont=cont+1;
  if(cont>=15){
  cont=15;}
tiempopush = millis();}
  }
void menos(){
if (millis() > tiempopush + pulsopush){
  cont=cont-1;
  if(cont<=0){
   cont=0;}
tiempopush = millis();}
   }
