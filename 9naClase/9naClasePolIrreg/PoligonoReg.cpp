#include <iostream>
#include <stdlib.h>	
#include <vector>
#include "math.h"
#include "PoligonoReg.h"

using namespace std;

PoligonoReg::PoligonoReg(int nVertices) : numVertices(nVertices) 
{
	x = 0;
	y = 0;
	angle = (360 / nVertices)

	v.push_back(Coordenada(x,y));

	for (int i = 0; i < nVertices; ++i)
	{
		x = cos(angle);
		y = sin(angle);
		v.push_back(Coordenada(x,y));
		angle += angle;
	}
}

PoligonoReg::obtieneArea(){
	
}

