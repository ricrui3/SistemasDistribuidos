#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_
#include "Coordenada.h"
#include <vector>
using namespace std;

class PoligonoIrreg{
	protected:
		vector<Coordenada> v;
		double x;
		double y;
		static int numVertices;
	public:
		static int getNumeroVertices();
		PoligonoIrreg();
		PoligonoIrreg(double x, double y);
		void anadeVertice(double x, double y);
		void imprimeVertices();
};

#endif