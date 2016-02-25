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
	double magnitud;
	std::vector<Coordenada>::iterator i;
	std::vector<double>::iterator j;

	for(i = v.begin(); i != v.end(); i++){
		magnitud = sqrt(pow((*i).obtenerX(),2) + pow((*i).obtenerY(),2));
		m.push_back(magnitud);
	}

	sort(m.begin(),m.end());

	for(j = m.begin(); j != m.end(); j++){
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(3);

		std::cout << *j << std::endl;
	}
}


void PoligonoIrreg::imprimeVertices(){
	std::vector<Coordenada>::iterator i;
	std::vector<double> m;
	double magnitud;

	for(i = v.begin(); i != v.end(); i++){
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(3);

		magnitud = sqrt(pow((*i).obtenerX(),2) + pow((*i).obtenerY(),2));
		m.push_back(magnitud);
		//Por precedencia es necesario forzar a que entre primero el *
		cout << (*i).obtenerX() << " - " << (*i).obtenerY() << " - "<< magnitud << endl;
		sort();
	}
}
