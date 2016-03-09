#include <iostream>
#include <stdlib.h>	
#include <vector>
#include "PoligonoIrreg.h"
#include "Coordenada.h"

using namespace std;

int PoligonoIrreg::numVertices = 0;

int PoligonoIrreg::getNumeroVertices(){
	return numVertices;
}

PoligonoIrreg::PoligonoIrreg()
{}

PoligonoIrreg::PoligonoIrreg(double yy, double xx) : x(xx), y(yy)
{
	v.push_back(Coordenada(xx,yy));
}

void PoligonoIrreg::anadeVertice(double y, double x){
	//cout << "Vertice" << endl;
	v.push_back(Coordenada(x,y));
	numVertices++;
}

void PoligonoIrreg::imprimeVertices(){
	for(int i = 0; i < v.size(); i++){
		cout << v[i].obtenerX() << " - " << v[i].obtenerY() << endl;
	}
}