#ifndef STATIC_H_
#define STATIC_H_

int Fecha::vecesMuestF = 0;

int Fecha::getVecesMuestF()
{
			//return vecesMuestF;
	return dia;
			//return mes;
			//return anio;
}

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
	vecesMuestF++;
	return;
}

#endif