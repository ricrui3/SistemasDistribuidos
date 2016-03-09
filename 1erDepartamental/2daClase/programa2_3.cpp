#include "Fecha.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
  Fecha a, b, c(21, 9, 1973);
  int fecha;
  b.inicializaFecha(17, 6 , 2000);
  a.muestraFecha();
  b.muestraFecha();
  c.muestraFecha();
  fecha = a.convierte();
  cout << fecha << endl;
}