#ifndef Circulo_h_
#define Circulo_h_
#include "math.h"

const double PI = acos(-1.0);  

class Circulo 
{ 
protected: 
	double radio;
public: 
	Circulo(double = 1.0); 
	double calcval(); 
}; 


#endif