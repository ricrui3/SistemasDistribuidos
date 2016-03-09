#include <iostream>
#include <stdlib.h>	
#include <math.h>
#include "Coordenada.h"
using namespace std;

Coordenada::Coordenada(double yy, double xx) : x(xx), y(yy)
 {
	//double r, theta;
	
	//x = xx*cos(yy);
	//y =xx*sin(yy);
 }

 double Coordenada::obtenerX()
 {
 return x;
 }

 double Coordenada::obtenerY()
 {
 return y;
 }

