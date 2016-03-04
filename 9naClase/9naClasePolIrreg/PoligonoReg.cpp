#include <iostream>
#include <stdlib.h>	
#include <vector>
#include "math.h"
#include "PoligonoReg.h"

#define PI 3.14159265

using namespace std;

PoligonoReg::PoligonoReg(int nVertices) : numVertices(nVertices) 
{
	x = 1;
	y = 0;
	angle = (360 / nVertices);
	double perimetro;

	v.push_back(Coordenada(x,y));
	//cout << "angulo" << angle << endl;

	for (int i = 0; i < nVertices; ++i)
	{
		x = cos ( angle * PI / 180.0 );
		y = sin ( angle * PI / 180.0 );

		//cout << "angulo: " <<angle << " x: " << x << " y: " << y << endl;
		v.push_back(Coordenada(x,y));
		angle += angle;
	}
	double lado = sqrt(pow(v[1].obtenerX() - v[0].obtenerX(),2) + pow(v[1].obtenerY() - v[0].obtenerY(),2));
	perimetro  = nVertices * sqrt(pow(v[1].obtenerX() - v[0].obtenerX(),2) + pow(v[1].obtenerY() - v[0].obtenerY(),2));
	double pii = perimetro / 2;
	cout << "lado: " << lado << " perimetro: " << perimetro << " pi: " << pii <<endl;


}

int PoligonoReg::obtieneArea(){
	return 0;
}