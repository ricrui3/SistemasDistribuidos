#ifndef Circulo_h_
#define Circulo_h_

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