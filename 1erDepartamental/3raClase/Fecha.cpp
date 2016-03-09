#include "Fecha.h"
#include <cstdlib>
#include <iostream>
using namespace std;

//g++ archivo.cpp -c
//g++ programa2_2.cpp archivo.o -o programa2_2

Fecha::Fecha(int dd, int mm, int aaaa) : dia(dd), mes(mm), anio(aaaa)
{
   
	if((mes)<1 || (mes) > 12){
        cout << "Valor ilegal para el mes!" << endl;
    }
    if((dia)<1 || (dia) > 31){
        cout << "Valor ilegal para el dia!" << endl;
    }
    if((anio)<0 || (anio) > 2016){
        cout << "Valor ilegal para el anio!" << endl;
    }
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