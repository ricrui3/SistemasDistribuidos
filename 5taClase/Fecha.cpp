#include <stdlib.h>
#include <iostream>
#include "Fecha.h"

using namespace std;

class Fecha
{
	private:
	int dia;
	int mes;
	int anio;

	static int vecesMuestF;
	public:
		static int getVecesMuestF();
		Fecha(int = 3, int = 4, int = 2014);
		void inicializaFecha(int, int, int);
		void muestraFecha();
		};