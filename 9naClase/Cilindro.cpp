#include <iostream> 
#include <cmath> 
#include "Circulo.h"
#include "Cilindro.h"


double Cilindro::calcval()  //Calcula el volumen del cilindro 
{ 
	return (longitud * Circulo::calcval()); 
} 