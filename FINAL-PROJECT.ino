#include "CAPACITANCE.h"
#include "INDUCTANCE.h"
void setup() {
  Serial.begin(9600);  
}

char choice = 0;
void loop() {
                                     
  Serial.println ("A. Capacitance");
  Serial.println ("B. Inductance");
  if (Serial.available () > 0) {  
    choice = Serial.read();       
  }
  

  capacitance CAPACITANCE;
  inductance INDUCTANCE;
  if ((choice == 'A')||(choice == 'a'))

    {
       CAPACITANCE.capsetup ();
       CAPACITANCE.caploop ();
      
    }
  else if ((choice == 'B') || (choice == 'b'))
    {
      INDUCTANCE.inductsetup ();
      INDUCTANCE.inductloop ();
    }

}
