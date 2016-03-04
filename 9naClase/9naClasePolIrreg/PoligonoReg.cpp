#include <iostream>
#include <stdlib.h>	
#include <vector>
#include "PoligonoReg.h"

using namespace std;

PoligonoIrreg::PoligonoReg()
{}

PoligonoIrreg::PoligonoReg(double yy, double xx) : x(xx), y(yy)
{
	v.push_back(Coordenada(xx,yy));
}