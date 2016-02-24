#ifndef FECHA_H_
#define FECHA_H_


class Fecha
{
private:
	int dia;
	int mes;
	int anio;
	int arr[10000];
public:
	Fecha(int = 3, int = 4, int = 1);
	void masAnio();
	void inicializaFecha(int, int, int);
	void muestraFecha();
	int convierte();
	bool leapyr();
	//int masVieja(Fecha fecha1, Fecha fecha2);
};

#endif
