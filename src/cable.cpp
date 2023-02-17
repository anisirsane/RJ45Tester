#include <cable.h>
#include<Arduino.h>
    Cable::Cable(int Broche1, int Broche2, int Broche3, int Broche4, int Broche5, int Broche6, int Broche7, int Broche8){

        this->Broche1 = Broche1;
        this->Broche2 = Broche2;
        this->Broche3 = Broche3;
        this->Broche4 = Broche4;
        this->Broche5 = Broche5;
        this->Broche6 = Broche6;
        this->Broche7 = Broche7;
        this->Broche8 = Broche8;
    };

    void Cable::TableauCable(){
         Tab[0] = this->Broche1;
         Tab[1] = this->Broche2; 
         Tab[2] = this->Broche3; 
         Tab[3] = this->Broche4; 
         Tab[4] = this->Broche5; 
         Tab[5] = this->Broche6; 
         Tab[6] = this->Broche7; 
         Tab[7] = this->Broche8; 
    };

    void Cable::initialisation(){
        
        digitalWrite(this->Broche1, LOW);
        digitalWrite(this->Broche2, LOW);
        digitalWrite(this->Broche3, LOW);
        digitalWrite(this->Broche4, LOW);
        digitalWrite(this->Broche5, LOW);
        digitalWrite(this->Broche6, LOW);
        digitalWrite(this->Broche7, LOW);
        digitalWrite(this->Broche8, LOW);
    };

    int Cable::choix(int i)
    {  
       return Tab[i]; 
    };