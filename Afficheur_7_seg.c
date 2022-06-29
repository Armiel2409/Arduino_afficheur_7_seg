//ATTRIBUTION DES PINS

#define pinA 12
#define pinB 13
#define pinC 3
#define pinD 4
#define pinE 2
#define pinF 8
#define pinG 7

#define afficheur_gauche 5
#define afficheur_droite 6

// CONFIGURATION - INITIALISATION

void setup() 
{
  
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(afficheur_gauche, OUTPUT);
  pinMode(afficheur_droite, OUTPUT);

  Serial.begin(9600);

}



void chiffre_to_seg(int chiffre)
{
  bool a, b, c, d, e, f, g = 0;

  switch(chiffre)
  {
    case 0:
    a=1;b=1;c=1;d=1;e=1;f=1;g=0;
    break;

    case 1:
    a=0;b=1;c=1;d=0;e=0;f=0;g=0;
    break;

    case 2:
    a=1;b=1;c=0;d=1;e=1;f=0;g=1;
    break;

    case 3:
    a=1;b=1;c=1;d=1;e=0;f=0;g=1;
    break;

    case 4:
    a=0;b=1;c=1;d=0;e=0;f=1;g=1;
    break;

    case 5:
    a=1;b=0;c=1;d=1;e=0;f=1;g=1;
    break;

    case 6:
    a=1;b=0;c=1;d=1;e=1;f=1;g=1;
    break;

    case 7:
    a=1;b=1;c=1;d=0;e=0;f=0;g=0;
    break;

    case 8:
    a=1;b=1;c=1;d=1;e=1;f=1;g=1;
    break;

    case 9:
    a=1;b=1;c=1;d=1;e=0;f=1;g=1;
    break;
  }

  digitalWrite(pinA, a);
  digitalWrite(pinB, b);
  digitalWrite(pinC, c);
  digitalWrite(pinD, d);
  digitalWrite(pinE, e);
  digitalWrite(pinF, f);
  digitalWrite(pinG, g);
}

// COEUR DU PROGRAMME

void loop() 
{
  int nombretest = 26;
  int dizaines = 0;
  int unites = 0;

  unites=nombretest%10;
  dizaines=(nombretest-unites)/10;

  if(nombretest>99)
  {

    chiffre_to_seg(9);
    digitalWrite(afficheur_droite,1);
    digitalWrite(afficheur_gauche,1);

    delay(1000);

    digitalWrite(afficheur_droite,0);
    digitalWrite(afficheur_gauche,0);

    delay(1000);
  }
  else
  {
    digitalWrite(afficheur_gauche,0);
    digitalWrite(afficheur_droite,1);
    chiffre_to_seg(unites);
    
    delay(12);

    digitalWrite(afficheur_gauche,1);
    digitalWrite(afficheur_droite,0);
    chiffre_to_seg(dizaines);

    delay(12);
    
  }
}