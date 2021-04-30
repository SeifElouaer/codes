int moteur1A=6;  //left
int moteur1B=5;
int moteur2A=10;  //right
int moteur2B=9;



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
  analogWrite(moteur1A,0);
  analogWrite(moteur1B,Speedm);
  // Moteur2
  analogWrite(moteur2A,Speedm);
  analogWrite(moteur2B,0);
 
}


void TurnRight ( int Speedm  ) {
  // Moteur1 
  analogWrite(moteur1A,Speedm);
  analogWrite(moteur1B,0);
  // Moteur2
  analogWrite(moteur2A,0);
  analogWrite(moteur2B,Speedm);
   
}


void Stop  ( ) {
 // Moteur1 
  analogWrite(moteur1A,0);
  analogWrite(moteur1B,0);
  // Moteur2
  analogWrite(moteur2A,0);
  analogWrite(moteur2B,0);
}


void ForWard_right ( ) {
  // Moteur1 
  analogWrite(moteur1A,0);
  analogWrite(moteur1B,250);
  // Moteur2
  analogWrite(moteur2A,0);
  analogWrite(moteur2B,150);
}

void ForWard_left ( ) {
  // Moteur1 
  analogWrite(moteur1A,0);
  analogWrite(moteur1B,150);
  // Moteur2
  analogWrite(moteur2A,0);
  analogWrite(moteur2B,250);
}





void loop() {

if(Serial.available())
{
  char i = Serial.read();

  if(i == 'F')
  ForWard(250);
  if(i == 'B')
  BackWard(250);
  if(i == 'L')
  TurnRight(250);
  if(i == 'R')
  TurnLeft(250);
  if(i == 'S')
  Stop();
  if(i == 'I')
  ForWard_right ();
  if (i == 'G')
  ForWard_left();
  
   
}



  
}
