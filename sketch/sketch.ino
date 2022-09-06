/*
######################################################
#   Novoferm Schievano
#   Arduino legge i valori delle 3 termocoppie e lo
#   spedisce a raspberry per l'elaborazione.
#   
#   18.05.2016 canovam    creazione
#   07.06.2016 canovam    aggiunta lettura rt01
#   ..
#
######################################################
*/

// led che indica la lettura degli input
int oled = 13;
// pin delle termocoppie 
int tc01 = 0;
int tc02 = 1;
int tc03 = 2;
// pin del rilevatore di tensione
int rt01 = A3;

// secondi di attesa tra una lettura e l'altra
int attesa = 30;


void setup() 
{
  // Attivo il collegamento seriale con raspberry pi
  Serial.begin(9600); 
  // Creo un led di notifica di lettura delle termocoppie
  pinMode( oled, OUTPUT );  
}

void loop() 
{
  digitalWrite( oled, HIGH );
  // Serial.println( "inizio lettura" );

  // leggo i 3 valori  
  double t1 = getTemp( tc01 );
  double t2 = getTemp( tc02 );
  double t3 = getTemp( tc03 );  

  // leggo la tensione data in input al motore della catena del forno
  int sensorValue = analogRead(rt01);
  // rimappo il valore letto per comprenderlo meglio
  float voltage = map(sensorValue, 0, 1023, 0, 100); 

  //print temperature in Celsius
  Serial.print( t1 );
  Serial.print( ";" );
  Serial.print( t2 );
  Serial.print( ";" );
  Serial.print( t3 );
  Serial.print( ";" );
  Serial.print( voltage );
  Serial.println( ";" );

  
  delay (1000);  
  digitalWrite( oled, LOW );
  delay ( (attesa -1 ) * 1000 );
}

double getTemp( int in_temp ) 
{    
  int value = analogRead(in_temp);

  double Vin = ( 5 * value );
  float  vinl = Vin / 1024;
  double Vout = vinl - 1.25;
  double T = Vout / 0.005;
  T = T + 10;
  
  return T;
}

