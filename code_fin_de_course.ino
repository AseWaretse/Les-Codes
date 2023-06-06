byte Pin_fin_course=5;                                                   // Port de connexion
int valeur_fin_course;                                                   // Création de variable valeur


void setup() 
{
  pinMode(Pin_fin_course,INPUT);                                        // pin_bouton envooie info
  Serial.begin(9600);                                                   // Ouverture du moniteur série
}
  


void loop() 
{
  valeur_fin_course=digitalRead (Pin_fin_course);                      // Valeur égale lire pin bouton
  Serial.println(valeur_fin_course);                                   // Écrire la valeur sur le moniteur
  delay(1000);
//fin de course 
if (valeur_fin_course=0)
 {                                    
  moteur.setSpeed(0);                                                  // Vitesse du moteur: 500 pas par seconde
 }
}
