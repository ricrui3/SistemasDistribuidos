#include "Fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha(int dd, int mm, int aaaa)
{
	mes = mm;
	dia = dd;
	anio = aaaa;
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa)
{
	anio = aaaa;
	mes = mm;
	dia = dd;
	return;
}

void Fecha::muestraFecha()
{
	cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
	return;
}

int Fecha::convierte(){
	int entero;
	entero = anio*10000+mes*100+dia;
	return entero;
}

bool Fecha::leapyr(){
	bool bisiesto;

	if((anio%4==0 && anio%100!=0) || anio%400==0){
		bisiesto = true;
		cout << "El anio " << anio << " es bisiesto" << endl;
	}

	else{
		bisiesto = false;
		cout << "El anio " << anio << " no es bisiesto" << endl;
	}
	return bisiesto;
}

void Fecha::masAnio(){
	anio++;
}
