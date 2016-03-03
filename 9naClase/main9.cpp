#include <iostream> 
#include <cmath> 
#include "Circulo.h"
#include "Cilindro.h"
#include "Toroide.h"
using namespace std; 

int main() 
{ 
	Circulo Circulo_1, Circulo_2(2);  
	Cilindro Cilindro_1(3,4);
	Toroide toroide_1;

	cout << "El área de Circulo_1 es " << Circulo_1.calcval() << endl; 
	cout << "El área de Circulo_2 es " << Circulo_2.calcval() << endl; 
	cout << "El volumen de Cilindro_1 es " << Cilindro_1.calcval() << endl; 



	Circulo_1 = Cilindro_1; 
	cout << "\nEl área de Circulo_1 es ahora " << Circulo_1.calcval() << endl; 

	cout << "Valor del toroide_1" << toroide_1.calcval() << endl;

	cout.setf(ios::fixed);
   	cout.setf(ios::showpoint);
    cout.precision(100);

	//cout << "Valor de pi " << static_cast<long double>(PI) << endl;

	

	return 0; 
}