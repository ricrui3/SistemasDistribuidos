#include "Fecha.h"

int main()
{
	Fecha a, b, c(21, 9, 1973);
	b.inicializaFecha(17, 6 , 2000);
	a.muestraFecha();
	b.muestraFecha();
	c.muestraFecha();
	//cout << "La fecha es(dia-mes-año): " << a.dia << "-" << a.mes << "-" << a::anio << endl;
}