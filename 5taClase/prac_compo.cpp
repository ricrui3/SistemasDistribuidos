 #include <iostream>
 #include <stdlib.h>
#include <vector>
#include <math.h>
#include "Coordenada.h"
#include "PoligonoIrreg.h"
using namespace std;



int main( )
{
	int numVer = 0, numVec = 10000;

	vector<PoligonoIrreg> polI;
	polI.resize(10000);
	cout << polI.size() << endl;
	for(int i = 0; i < polI.size(); i++){
		numVer = rand() % 100;
		for(int j = 0; j < numVer; j++){
			polI[j].anadeVertice(j,numVer);
		}
	 	cout << "vertices anadidos " << polI[i].getNumeroVertices() << endl;
	}

 //poligonoIrreg.imprimeVertices();
	// poligonoIrreg.anadeVertice(5,4);
	// poligonoIrreg.anadeVertice(4,1);
	// poligonoIrreg.anadeVertice(3,2);
	// poligonoIrreg.anadeVertice(2,3);
	// poligonoIrreg.anadeVertice(1,5);

	// poligonoIrreg.imprimeVertices();
	return 0;
}
