#include "Fecha.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

int masVieja(Fecha fecha1, Fecha fecha2);


int main()
{
	int i;
	//cout << sizeof(Fecha) << endl;
	//cout << sizeof(int) << endl;
	Fecha a(22, 11, 1972);
	Fecha b(21, 11, 1972);

	for(i = 0; i < 1000000; i++){
		a.inicializaFecha((rand() % 30)+1, (rand() % 11)+1, (rand() % 2015)+1);
		b.inicializaFecha((rand() % 30)+1, (rand() % 11)+1, (rand() % 2015)+1);
		//cout << "Fecha a es " << a.convierte() << " Fecha b es " << b.convierte() << endl;
		masVieja(a,b);
	}

	
}

int masVieja(Fecha fecha1, Fecha fecha2){

    if(fecha1.convierte() == fecha2.convierte()){
        return 0;
    }
    else if(fecha1.convierte() < fecha2.convierte()){
        return -1;
    }
    else {
        return 1;
    }
}