int A = 2; 		
int B = 4;  			

int ANTERIOR = 50;		

volatile int POSICION = 50;

void setup() {
  pinMode(A, INPUT);		
  pinMode(B, INPUT);		

  Serial.begin(9600);		

  attachInterrupt(digitalPinToInterrupt(A), encoder, LOW);

  Serial.println("Listo");	
}


void loop() {
  if (POSICION != ANTERIOR) {	
    Serial.println(POSICION);	
    ANTERIOR = POSICION ;
  }
}

void encoder()  {
  static unsigned long ultimaInterrupcion = 0;	
  unsigned long tiempoInterrupcion = millis();

  if (tiempoInterrupcion - ultimaInterrupcion > 5) {	
    if (digitalRead(B) == HIGH)			
    {
      POSICION++ ;			
    }
    else {					
      POSICION-- ;				
    }

    POSICION = min(100, max(0, POSICION));	
    ultimaInterrupcion = tiempoInterrupcion;	
  }						
}