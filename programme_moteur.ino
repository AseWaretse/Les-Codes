#include <AccelStepper.h>;
AccelStepper moteur(1, 7, 4);                  // Création de l'objet moteur. 1: utilisation d'un driver. 7: STEP, 4: DIR
unsigned long t, tprec=0;
int etat=0;                                    //valeur de etat a l'origine
int v=0;                                       //valeur de v a l'origine

void setup() 
{
  moteur.setMaxSpeed(1000);                    // Vitesse maxi du moteur: 1000 pas par seconde
}

void loop(){
  t=millis();
  if ((t-tprec) > 2000){
    switch (etat)
    {
      case 0:
        v=500;                            //vitesse du bloc
        etat=1;                           //valeur de etat
        break;                            //sortie de case
      case 1:
        v=0;                            //vitesse du bloc
        etat=2;                           //valeur de etat
        break;                            //sortie de case
      case 2:
        v=0;                            //vitesse du bloc
        etat=3;                           //valeur de etat
        break;                            //sortie de case
      case 3:
        v=-500;                            //vitesse du bloc
        etat=0;                           //valeur de etat
        break;                            //sortie de case
    }
    moteur.setSpeed(v);                      // Vitesse du moteur: v pas par seconde
    tprec=t;                           //nouvelle valeur a temps
  }
  moteur.runSpeed();                        // Mise en rotation du moteur
}
