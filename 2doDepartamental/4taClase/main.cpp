#include "PaqueteDatagrama.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  char a[] = {2, 3, 7, 8, 9, 1, 2, 5};
  char ip[] = "192.168.2.1";
  PaqueteDatagrama paq1(a, sizeof(a), ip, 7200);
  cout << "Debugger" << endl;
  PaqueteDatagrama paq2(20);

  paq1.obtieneDireccion();
  paq1.obtieneLongitud();
  paq1.obtienePuerto();
  paq1.obtieneDatos();

  paq2.obtieneDireccion();
  paq2.obtieneLongitud();
  paq2.obtienePuerto();
  paq2.obtieneDatos();

  return 0;
}

// s