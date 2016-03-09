#include <iostream> 
#include <cmath> 
#include "Circulo.h"
using namespace std; 



Circulo::Circulo(double r) : radio(r) 
{ } 

double Circulo::calcval() //Calcula el área del círculo 
{ 
	return(PI * radio * radio); 
} 