#ifndef TOROIDE_H_
#define TOROIDE_H_ 
#include "Cilindro.h"

class Toroide : public Cilindro 
{ 
private: 
	double longitud2;
public: 
	//Toroide(double r = 1.0, double l = 1.0) : Cilindro(r), num(l) {} 
	double calcval(); 
}; 


#endif