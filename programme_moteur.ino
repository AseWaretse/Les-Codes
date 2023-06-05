#include <AccelStepper.h>;
AccelStepper moteur(1, 7, 4);                  // Création de l'objet moteur. 1: utilisation d'un driver. 7: STEP, 4: DIR
unsigned long t, tprec=0;
int etat=0;
int v=0;

void setup() 
{
  moteur.setMaxSpeed(1000);                    // Vitesse maxi du moteur: 1000 pas par seconde
}

void loop() 
{
  t=millis();
  if ((t-tprec) > 2000)
  {
    switch (etat)
    {
      case 0:
        v=500;
        etat=1;
        break;
      case 1:
        v=0;
        etat=2;
        break;
      case 2:
        v=0;
        etat=3;
        break;
      case 3:
        v=-500;
        etat=0;
        break;
    }
    moteur.setSpeed(v);                      // Vitesse du moteur: v pas par seconde
    tprec=t;
  }
  

  moteur.runSpeed();                        // Mise en rotation du moteur

}
