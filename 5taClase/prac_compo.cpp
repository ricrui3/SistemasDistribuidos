#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include "Coordenada.h"
#include "PoligonoIrreg.h"
using namespace std;

static int numVec = 100000;

int main( )
{
  int numVer = 0, cinn = 0;

  vector<PoligonoIrreg> polI;
  //polI.resize(numVec);
  cout << polI.size() << endl;
  /*polI.size()*/
  for(int i = 0; i < numVec; i++){
    polI.push_back(PoligonoIrreg());
    numVer = rand() % 100;
    //cout << numVer
    //cin >> cinn;
    for(int j = 0; j < numVer; j++){
      cout <<  "this"<<numVer+1 << endl;
      cout << polI.size() << endl;
      polI[j].anadeVertice(j,numVer);
    }
    //cout << "vertices anadidos " << polI[i].getNumeroVertices() << endl;
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
