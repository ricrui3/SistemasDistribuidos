#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include "Coordenada.h"
#include "PoligonoIrreg.h"
using namespace std;

static int numVer = 5;

int main( )
{
	PoligonoIrreg polI;

	for(int j = 0; j < numVer; j++){
		double val1 = static_cast<double> ((rand() % 200) - 100) + ((static_cast<double> (rand() % 1000) + 1)/1000);
		double val2 = static_cast<double> ((rand() % 200) - 100) + ((static_cast<double> (rand() % 1000) + 1)/1000);
		//cout << val1 << val2;
		polI.anadeVertice(val1,val2);
	}
	polI.imprimeVertices();
	std::cout << "" << std::endl;
	polI.ordenaA();
	return 0;
}
