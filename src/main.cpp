#include <Arduino.h>
#include <cable.h>
#include<string.h>

//declaration des broches
//le cote des input
const int BROCHE1_1 = 13;
const int BROCHE1_2 = 14;
const int BROCHE1_3 = 15;
const int BROCHE1_4 = 16;
const int BROCHE1_5 = 17;
const int BROCHE1_6 = 10;
const int BROCHE1_7 = 11;
const int BROCHE1_8 = 12;
//le cote des output
const int BROCHE2_1 = 2;
const int BROCHE2_2 = 3;
const int BROCHE2_3 = 4;
const int BROCHE2_4 = 5;
const int BROCHE2_5 = 6;
const int BROCHE2_6 = 7;
const int BROCHE2_7 = 8;
const int BROCHE2_8 = 9;

int val1, val2;
Cable Cable1(BROCHE1_1, BROCHE1_2, BROCHE1_3, BROCHE1_4, BROCHE1_5, BROCHE1_6, BROCHE1_7, BROCHE1_8);
Cable Cable2(BROCHE2_1, BROCHE2_2, BROCHE2_3, BROCHE2_4, BROCHE2_5, BROCHE2_6, BROCHE2_7, BROCHE2_8);

String cabletype;



void setup() {
  // put your setup code here, to run once:
        pinMode(BROCHE1_1, OUTPUT);
        pinMode(BROCHE1_2, OUTPUT);
        pinMode(BROCHE1_3, OUTPUT);
        pinMode(BROCHE1_4, OUTPUT);
        pinMode(BROCHE1_5, OUTPUT);
        pinMode(BROCHE1_6, OUTPUT);
        pinMode(BROCHE1_7, OUTPUT);
        pinMode(BROCHE1_8, OUTPUT);
        
        pinMode(BROCHE2_1, INPUT);
        pinMode(BROCHE2_2, INPUT);
        pinMode(BROCHE2_3, INPUT);
        pinMode(BROCHE2_4, INPUT);
        pinMode(BROCHE2_5, INPUT);
        pinMode(BROCHE2_6, INPUT);
        pinMode(BROCHE2_7, INPUT);
        pinMode(BROCHE2_8, INPUT);
        
        Serial.begin(9600);
        Cable1.TableauCable(); 
        Cable2.TableauCable();
}

void loop() {
  Cable1.initialisation();
  delay(1000);
  digitalWrite(BROCHE1_1,HIGH);
  val1=digitalRead(BROCHE2_1);
  val2=digitalRead(BROCHE2_3);
  if(val1==1){
    cabletype="droit";
    Serial.println("test 1 ok ");
    for (int i = 1; i < 8; i++)
    {
      Serial.print("test ");
      Serial.print(i+1);
      Serial.println(" ok");
      digitalWrite(Cable1.choix(i),HIGH);

      if(!digitalRead(Cable2.choix(i))){
        val1=0;
        Serial.print("cable non fonctionant");
        cabletype="";
        break;
      }
      delay(1000);
    }
    if(val1==1){
      Serial.print("le cable est: ");
      Serial.print(cabletype);
    }
    } else if(val2==1){
    digitalWrite(BROCHE1_3, HIGH);
    Serial.println(digitalRead(BROCHE2_1));
    if(digitalRead(BROCHE2_1) == 1){
      digitalWrite(BROCHE1_6,HIGH);
        Serial.println(digitalRead(BROCHE2_2));
      if(digitalRead(BROCHE2_2) == 1){
    cabletype="croise";
    Serial.println("test 1 ok ");
    int i = 0;
    for (i = 3 ; i <= 7; i++)
    { 
      if (i != 5)
      {
      digitalWrite(Cable1.choix(i),HIGH);
      if(digitalRead(Cable2.choix(i))==0){
        val2=0;
        Serial.print("cable non fonctionant");
        cabletype="";
        break;
      }
      Serial.print("test ");
      Serial.print(i+1);
      Serial.println(" ok");
      };
      
    delay(1000);
    }
    if(val2==1){
      Serial.print("le cable est: ");
      Serial.print(cabletype);
    }          
  }
  }
  }

  
  Serial.println("----------------------------------------------------");
  delay(2000);
}