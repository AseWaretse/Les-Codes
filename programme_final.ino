byte Pin_fin_course=10;                                        // Port de connextion
int valeur_fin_course;                                         // Création de variable valeur
byte Pin_fin_course_2=8;                                       // Port de connextion
int valeur_fin_course_2;                                       // Création de variable valeur

int vitesse; // variable pour la vitesse du moteur 

#include <AccelStepper.h>;
AccelStepper moteur(1, 7, 4);                                  // Création de l'objet moteur. 1: utilisation d'un driver. 7: STEP, 4: DIR

int data;

#define VITESSE_RAPIDE 1600
#define VITESSE_LENTE 400

#include <SoftwareSerial.h>
SoftwareSerial bluetooth(11,12);                               // RX, TX pins for Bluetooth module
void setup() 
{
  pinMode(Pin_fin_course,INPUT);                               // pin_bouton envooie info
  pinMode(Pin_fin_course_2,INPUT);                             // pin_bouton envooie info
  Serial.begin(9600);                                          // Ouverture du moniteur série

  moteur.setMaxSpeed(1000);                                    // Vitesse maxi du moteur: 1000 pas par seconde
 
  bluetooth.begin(9600);                                       // Bluetooth module baud rate  
}
  


void loop() 
{
  valeur_fin_course=digitalRead(Pin_fin_course);              // Valeur égale lire Pin fin course
//  Serial.print("valeur_fin_course : ");
//  Serial.println(valeur_fin_course);                        // Écrire la valeur sur le moniteur
  valeur_fin_course_2=digitalRead(Pin_fin_course_2);          // Valeur égale lire pin bouton
//  Serial.print("valeur_fin_course_2 : ");
//  Serial.println(valeur_fin_course_2);                      // Écrire la valeur sur le moniteur

  if(bluetooth.available())
  {
    data = bluetooth.read();
    Serial.print("Received data: ");
    Serial.println(data);

    //gauche rapide
if (data == 1)
{ 
  vitesse = -VITESSE_RAPIDE;                                 // Vitesse du moteur: -1000 pas par seconde
  
}

//gauche rapide
if (data == 50)
{ 
  vitesse = -VITESSE_LENTE;                                 // Vitesse du moteur: -1000 pas par seconde
 
}
 
//stop
if (data == 51)
{
  vitesse = 0;                                             // Vitesse du moteur: 0 pas par seconde
 
}

//droite rapide 
if (data == 53)
{
  vitesse = VITESSE_RAPIDE;                               // Vitesse du moteur: 1000 pas par seconde
 
}

//droite rapide 
if (data == 52)
{
  vitesse = VITESSE_LENTE;                               // Vitesse du moteur: 1000 pas par seconde
 
}
 Serial.print("vitesse : ");
 Serial.println(vitesse);    

  }

//fin de course 
if (valeur_fin_course==0)
 {
  for(byte count=0;count<=100;count++)
  {
     moteur.setSpeed(-150);                                      
    Serial.println(vitesse);                               
    moteur.runSpeed();   
  }
  vitesse = 0;                                          // Vitesse du moteur: 0 pas par seconde
 }

//fin de course 2 
if (valeur_fin_course_2==0)
 {
  byte count=0;
  while(count<=100)
  {
     moteur.setSpeed(150);                                       
    Serial.println(vitesse);                               
    moteur.runSpeed();  
    count++; 
  }

  //moteur.setSpeed(-150);
  // do
  // {                 
  //   moteur.runSpeed(); 
  //   }
  //   while(valeur_fin_course_2!=1);
  //
   
  vitesse = 0;                                       // Vitesse du moteur: 0 pas par seconde
 }

 moteur.setSpeed(vitesse); 
// Serial.print("vitesse : ");
// Serial.println(vitesse);    
// delay(100);                           
 moteur.runSpeed();                                 // Mise en rotation du moteur
}