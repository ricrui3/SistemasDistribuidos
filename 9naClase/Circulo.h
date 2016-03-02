#ifndef Circulo_h_
#define Circulo_h_
#include "Cilindro.h"

const double PI = acos(-1.0);  

class Circulo 
{ 
private: 
	double radio;
public: 
	Circulo(double = 1.0); 
	double calcval(); 
}; 


#endif