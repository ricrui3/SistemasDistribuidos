#include "PaqueteDatagrama.h"
#include <iostream>
using namespace std;

void imprimeDatos(char *datos);

int main(int argc, char const *argv[]) {
  char a[] = {2, 3, 7, 8, 9, 1, 2, 5};
  char ip[] = "192.168.2.1";
  imprimeDatos(ip);
  imprimeDatos(a);
  PaqueteDatagrama paq1(a, sizeof(a), ip, 7200);
  PaqueteDatagrama paq2(20);

  cout << paq1.obtieneDireccion() << endl;
  cout << paq1.obtieneLongitud() << endl;
  cout << paq1.obtienePuerto() << endl;

  cout << paq2.obtieneDireccion() << endl;
  cout << paq2.obtieneLongitud() << endl;
  cout << paq2.obtienePuerto() << endl;
  cout << paq2.obtieneDatos() << endl;

  return 0;
}
// s