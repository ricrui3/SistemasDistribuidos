#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include "Coordenada.h"
#include "PoligonoIrreg.h"
using namespace std;

static int  numVec = 100000;

int main( )
{
	int numVer = 0;
	vector<PoligonoIrreg> polI;
	PoligonoIrreg polIrrAux;

	for(int i = 0; i < numVec; i++){
		
		polI.push_back(polIrrAux);
		numVer = rand() % 100;
		
		for(int j = 0; j < numVer; j++){
			polI[i].anadeVertice(j,numVer);
		}

	 	//cout << "vertices anadidos " << polI[i].getNumeroVertices() << endl;

	}

	// poligonoIrreg.imprimeVertices();
	return 0;
}
