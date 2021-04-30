int moteur1A=6;  //left
int moteur1B=5;
int moteur2A=10;  //right
int moteur2B=9;
int capteurGauche=A1;
int capteurDroit=A0;
int capteurMid=A2; 
int seuil=100;


void setup() {
pinMode(moteur1A,OUTPUT);
pinMode(moteur1B,OUTPUT);
pinMode(moteur2A,OUTPUT);
pinMode(moteur2B,OUTPUT);
Serial.begin(9600);
}


void ForWard ( int Speedm  ) {
  // Moteur1 
  analogWrite(moteur1A,0);
  analogWrite(moteur1B,Speedm);
  // Moteur2
  analogWrite(moteur2A,0);
  analogWrite(moteur2B,Speedm);
 
}


void BackWard ( int Speedm  ) {
  // Moteur1 
  analogWrite(moteur1A,Speedm);
  analogWrite(moteur1B,0);
  // Moteur2
  analogWrite(moteur2A,Speedm);
  analogWrite(moteur2B,0);

}


void TurnLeft ( int Speedm  ) {
  // Moteur1 
  analogWrite(moteur1A,120);
  analogWrite(moteur1B,0);
  // Moteur2
  analogWrite(moteur2A,0);
  analogWrite(moteur2B,Speedm);
 
}


void TurnRight ( int Speedm  ) {
  // Moteur1 
  analogWrite(moteur1A,0);
  analogWrite(moteur1B,Speedm);
  // Moteur2
  analogWrite(moteur2A,120);
  analogWrite(moteur2B,0);
   
}


void Stop  ( int Speed  ) {
 // Moteur1 
  analogWrite(moteur1A,0);
  analogWrite(moteur1B,0);
  // Moteur2
  analogWrite(moteur2A,0);
  analogWrite(moteur2B,0);
 
}



void loop() {

  int valGauche=(analogRead(capteurGauche));
  int valDroit=(analogRead(capteurDroit));
  int valMid=(analogRead(capteurMid));
 /*ForWard(150);
  delay(1000);
  BackWard(150);
  delay(1000);
  TurnRight(150);
  delay(1000);
  TurnLeft(150);
  delay(1000);
  Stop(150);
  delay(1000);
  */
  
   /* Serial.println("***************************");

  Serial.print("Gauche: ");
  Serial.println(valGauche);
  Serial.print("droite: ");
  Serial.println(valDroit);
  Serial.print("milieu: ");
  Serial.println(valMid);*/
 

   // val < seuil :  Blanc 
   // val > seuil :  Noir 

  if(valGauche<seuil&&valMid<seuil&&valDroit>seuil) 
  {
TurnRight(150);
    Serial.println("TurnRight FAST");
  }

   else{
        if(valGauche<seuil&&valMid>seuil&&valDroit>seuil) 
          {
            TurnRight(120);
            Serial.println("TurnRight SLOW");
          }

        else{
              if(valGauche>seuil&&valMid<seuil&&valDroit<seuil) 
                {
                  TurnLeft(120);
                  Serial.println("TurnLeft FAST");
                }
                    else{
                          if(valGauche>seuil&&valMid>seuil&&valDroit<seuil) 
                            {
                              TurnLeft(120);
                              Serial.println("TurnLeft SLOW");
                            }
                               else{
                                   ForWard(70); 
                                   Serial.println("Forward");
                                   }
                        }
              }

  
        }

}
