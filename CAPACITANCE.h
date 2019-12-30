class capacitance
{
public:
float resistorValue = 1000.0F;
unsigned long startTime;
unsigned long elapsedTime;
int analogPin =0;
float microFarads;                
float nanoFarads;

void capsetup(){
  pinMode(13, OUTPUT);     
  pinMode(11, INPUT);
  digitalWrite(13, LOW);  
             
};

void caploop(){
  digitalWrite(13, HIGH);  
  startTime = millis();
  while(analogRead(analogPin) < 648){       
  }

  elapsedTime= millis() - startTime;
  microFarads = ((float)elapsedTime / resistorValue) * 1000;   
  Serial.print(elapsedTime);       
  Serial.println(" mS    ");         

  if (microFarads > 1){
    Serial.print((long)microFarads);       
    Serial.println(" microFarads");         
  }

  else{
    nanoFarads = microFarads * 1000.0;      
    Serial.print((long)nanoFarads);         
    Serial.println(" nanoFarads");          
    delay(25000); 
  }

  digitalWrite(11, LOW);                     
  digitalWrite(13, LOW);          
  while(analogRead(analogPin) > 0){         
  }
          
};
};
