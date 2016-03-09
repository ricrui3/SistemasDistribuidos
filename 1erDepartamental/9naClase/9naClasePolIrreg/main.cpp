#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include "PoligonoReg.h"
using namespace std;

static int  numVec = 1000000;

int main( )
{
	int numVer = 0;
	vector<PoligonoReg> polR;
	std::vector<PoligonoReg>::iterator ipolR;

	for(int i = 3; i < 5; i++){
		PoligonoReg polRegAux = PoligonoReg(i);
		polR.push_back(polRegAux);

	}

	for (ipolR = polR.begin(); ipolR < polR.end(); ++ipolR)
	{
		(*ipolR).imprimeVertices();
	}

	//PoligonoReg.imprimeVertices();
	return 0;
}
