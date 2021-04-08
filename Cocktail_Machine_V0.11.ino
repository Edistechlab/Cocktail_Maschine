/*
Project:  Output send over MQTT with ESP8266 / NodeMCU
Author:   Thomas Edlinger for www.edistechlab.com
Date:     Created 19.04.2020 
Version:  V0.11
 
Required Board (Tools -> Board -> Boards Manager...)
 - Board: Arduino Nano
*/

const int Pumpe1 = 2;  
const int Pumpe2 = 3;  
const int Pumpe3 = 4; 

//Getränke 
const int Wodka = Pumpe1;
const int Orangensaft = Pumpe2;
const int Whisky = Pumpe3;


const int BTN_Cocktail1 = 5;   
const int BTN_Cocktail2 = 6;  
const int BTN_Cocktail3 = 7;  

const int Pumpleistung = 0.56; //0.56s für 1ml
int Menge=0;

void setup() {
  Serial.begin(115200); 
  pinMode(Pumpe1, OUTPUT);
  pinMode(Pumpe2, OUTPUT);
  pinMode(Pumpe3, OUTPUT);

  pinMode(BTN_Cocktail1, INPUT);
  pinMode(BTN_Cocktail2, INPUT);
  pinMode(BTN_Cocktail3, INPUT);

  digitalWrite(Pumpe1, HIGH);
  digitalWrite(Pumpe2, HIGH);
  digitalWrite(Pumpe3, HIGH);
}

void loop() {
  int Btn1 = digitalRead(BTN_Cocktail1);
  int Btn2 = digitalRead(BTN_Cocktail2);
  int Btn3 = digitalRead(BTN_Cocktail3);
  
  //Wodka Orangensaft
  if (Btn1 == LOW) {
    Serial.println ("Starte Wodka Orange");
    digitalWrite(Wodka, LOW); 
    digitalWrite(Orangensaft, LOW);
    Serial.println ("Wodka & Orange ");
    delay(10000);
    digitalWrite(Wodka, HIGH);
    digitalWrite(Orangensaft, LOW); 
    Serial.println ("Orangensaft "); 
    delay(25000);
    digitalWrite(Orangensaft, HIGH);
  } else {
    digitalWrite(Pumpe1, HIGH);
    digitalWrite(Pumpe2, HIGH);
    digitalWrite(Pumpe3, HIGH);
  }

  //Whisky Orangensaft
  if (Btn2 == LOW) {
    Serial.println ("Starte Whisky Orange");
    digitalWrite(Whisky, LOW); 
    digitalWrite(Orangensaft, LOW);
    Serial.println ("Wodka & Orange ");
    delay(10000);
    digitalWrite(Whisky, HIGH);
    digitalWrite(Orangensaft, LOW); 
    Serial.println ("Orangensaft ");
    delay(25000);
    digitalWrite(Orangensaft, HIGH);
  } else {
    digitalWrite(Pumpe1, HIGH);
    digitalWrite(Pumpe2, HIGH);
    digitalWrite(Pumpe3, HIGH);
  }

  //Whisky pur
  if (Btn3 == LOW) {
    Serial.println ("Starte Whisky pur");
    digitalWrite(Whisky, LOW); 
    delay(10000);
    digitalWrite(Whisky, HIGH);
   } else {
    digitalWrite(Pumpe1, HIGH);
    digitalWrite(Pumpe2, HIGH);
    digitalWrite(Pumpe3, HIGH);
  }
  
}
