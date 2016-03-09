#include "Fecha.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	Fecha a, b, c(21, 9, 1973);
	b.inicializaFecha(17, 6 , 2000);
	a.muestraFecha();
	b.muestraFecha();
	c.muestraFecha();

	//La sentencia mas abajo no es usada debido a que intenta llamar a un atributo
	//privado
	//cout << "La fecha es(dia-mes-año): " << a.dia << "-" << a.mes << "-" << a::anio << endl;
}
