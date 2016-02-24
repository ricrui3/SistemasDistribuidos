#include "Fecha.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
  int count = 0;
  Fecha a, b, c(21, 9, 1973);
  bool b1,b2,b3;
  b.inicializaFecha(17, 6 , 2000);
  a.muestraFecha();
  b.muestraFecha();
  c.muestraFecha();
  b1 = a.leapyr();
  b2 = b.leapyr();       
  b3 = c.leapyr();
  for(int x = 1; x<2017; x++){
    if(a.leapyr() == true){
      count++;
    }
    a.masAnio();
  }       
  cout << "el numero de anios es" << count << endl;
}