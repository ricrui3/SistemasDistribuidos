#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Coordenada.h"
using namespace std;

Coordenada::Coordenada(double yy, double xx) : x(xx), y(yy)
{
	magnitud = sqrt(pow(yy,2) + pow(xx,2));
}

double Coordenada::obtenerX()
{
	return x;
}

double Coordenada::obtenerY()
{
	return y;
}

double Coordenada::obtenerMagnitud()
{
	return magnitud;
}
