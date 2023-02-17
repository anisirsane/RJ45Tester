///ficher.h
#ifndef CABLE_HPP
   #define CABLE_HPP

#include<Arduino.h>
#include<string.h>
class Cable{
    // Declaration des attribue
    private:
        int Broche1, Broche2, Broche3, Broche4, Broche5, Broche6, Broche7, Broche8; 
    // Declaration constrecteur par default 
    public : 
        
        int Tab[7];
        Cable();
        Cable(int Broche1, int Broche2, int Broche3, int Broche4, int Broche5, int Broche6, int Broche7, int Broche8);
        
        void initialisation();
        void TableauCable();
        int choix(int i);
};
#endif 