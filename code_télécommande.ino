byte Pin_bouton=0; // port de connextion
int valeur;   //creation de variable valeur

#include <AccelStepper.h>;
AccelStepper moteur(1, 7, 4);           //Création de l'objet moteur. 1: utilisation d'un driver. 7: STEP, 4: DIR

void setup() 
{
  pinMode(Pin_bouton,INPUT);  //pin_bouton envooie info
  Serial.begin(9600);       //ouverture du moniteur série

  moteur.setMaxSpeed(1000);                    //Vitesse maxi du moteur: 1000 pas par secondes
}
  


void loop() 
{
  valeur=analogRead(Pin_bouton);   //valeur egale lire pin bouton
  Serial.println(valeur);          //ecrire la valeur sur le moniteur
//bleu
if (valeur >660 && valeur < 680)
{
  moteur.setSpeed(-1000);                   //Vitesse du moteur: 500 pas par secondes
 
}
//vert 
if (valeur >600 && valeur < 610)
{
  moteur.setSpeed(1000);                   //Vitesse du moteur: 500 pas par secondes
 
}

 
//blanc
if (valeur >870 && valeur < 890)
{
  moteur.setSpeed(0);                   //Vitesse du moteur: 500 pas par secondes
 
}


//rouge 
if (valeur >750 && valeur < 770)
{
  moteur.setSpeed(-500);                   //Vitesse du moteur: 500 pas par secondes
 
} 
//jaune
if (valeur >530 && valeur < 540)
{
  moteur.setSpeed(500);                   //Vitesse du moteur: 500 pas par secondes
 
}
moteur.runSpeed();                      //Mise en rotation du moteur
}
