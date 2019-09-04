//Prueba_cronometro.ino

unsigned long actual;
int h=0;
int m=15;
int s=00;


void setup() {
Serial.begin(9600);
Serial.print(h);
Serial.print(":");
Serial.print(m);
Serial.print(":");
Serial.println(s);
}

void loop() {
	tiempo();

}

void tiempo(){
	if(millis()-actual>=1000){
		if(h>0||m>0||s>0){
			if(s>0){
				seg_menos();
			}
			else{
				if(m>0){
				min_menos();
				 }
				else{
				hr_menos();	
				}
				
			}

		}
		else{
		Serial.println("Fin del conteo");

		}
	actual=millis();
	}
	
}

void seg_menos(){
s--;
Serial.print(h);
Serial.print(":");
Serial.print(m);
Serial.print(":");
Serial.println(s);
}
void min_menos(){
	m--;
	s=60;
	seg_menos();
}
void hr_menos(){
	h--;
	m=60;
	min_menos();
}
