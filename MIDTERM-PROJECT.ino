int Voltin = 5;                //mao ni ang volts 
int order1 = 0;               //mabasa nga wrong number sa arduino
int order2 = 0;
int order3 = 0;
float Voltout1 = 0;            // ang volts tinuod nga nabasa
float Voltout2 = 0;
float Voltout3 = 0;

float Resistor0 = 570;              // known resistor
float Resistor1 = 0;
float Resistor2 = 0;
float Resistor3 = 0;

float Resistor12 = 0;              //delta2
float Resistor13 = 0;
float Resistor23 = 0;
float numerator;

void setup() {
Serial.begin( 9600 );
}

void loop() {
order1 = analogRead( A0 );
order2 = analogRead( A1 );
order3 = analogRead( A2 );

Voltout1 = ( order1*Voltin )/1024.0;
Voltout2 = ( order2*Voltin )/1024.0;
Voltout3 = ( order3*Voltin )/1024.0;

Resistor1 = Resistor0 * ( ( Voltout2/Voltout1 ) - 1 );
Resistor2 = Resistor0 * ( ( Voltout3/Voltout1 ) - 1 ) - Resistor1;
Resistor3 = Resistor0 * ( ( Voltin/Voltout1 ) - 1 ) - Resistor1 - Resistor2;
numerator = ( Resistor1*Resistor2 ) + ( Resistor1*Resistor3 ) + ( Resistor2*Resistor3 );

Resistor12 = numerator/Resistor3;
Resistor13 = numerator/Resistor2;
Resistor23 = numerator/Resistor1;

Serial.println();
Serial.println();
Serial.println();
Serial.println();
Serial.println();

Serial.print( "Resistor1 = " );
Serial.println( Resistor1 );
Serial.print( "Resistor2 = " );
Serial.println( Resistor2 );
Serial.print( "Resistor3 = " );
Serial.println( Resistor3 );

Serial.println();
Serial.print( "Resistor12 = " );
Serial.println( Resistor12 );
Serial.print( "Resistor13 = " );
Serial.println( Resistor13 );
Serial.print( "Resistor23 = " );
Serial.println( Resistor23 );

delay( 2000 );

}
