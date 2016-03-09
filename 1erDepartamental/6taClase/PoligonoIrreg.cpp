#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "math.h"
#include "PoligonoIrreg.h"
#include "Coordenada.h"

using namespace std;

int PoligonoIrreg::numVertices = 0;

int PoligonoIrreg::getNumeroVertices(){
	return numVertices;
}

struct menor_magnitud{
	bool operator()(const Coordenada& s1, const Coordenada& s2) const {
		return s1.getMagnitud() < s2.getMagnitud();
	}
};

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

void PoligonoIrreg::ordenaA(/* arguments */) {
	sort(v.begin(),v.end(),menor_magnitud());
}

void PoligonoIrreg::imprimeVertices(){
	std::vector<Coordenada>::iterator i;
	for(i = v.begin(); i != v.end(); i++){
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(3);

		//Por precedencia es necesario forzar a que entre primero el *
		cout << (*i).obtenerX() << " - " << (*i).obtenerY() << " - "<< (*i).obtenerMagnitud() << endl;
	}
}
