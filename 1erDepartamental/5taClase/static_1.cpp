#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include "Coordenada.h"
#include "PoligonoIrreg.h"
using namespace std;

static int numVec = 1000000;

int main( )
{
	int numVer = 0;
	vector<PoligonoIrreg> polI;

	polI.resize(numVec);
	cout << polI.size() << endl;

	for(int i = 0; i < polI.size(); i++){
		
		numVer = rand() % 100;

		for(int j = 0; j < numVer; j++){
			polI[i].anadeVertice(j,numVer);
		}

	 	//cout << "vertices anadidos " << polI[i].getNumeroVertices() << endl;
	}

	// poligonoIrreg.imprimeVertices();
	return 0;
}
