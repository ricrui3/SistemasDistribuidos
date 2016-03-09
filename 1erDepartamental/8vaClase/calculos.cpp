#include <iostream>
#include "math.h"

using namespace std;

int main(){
	int i=0, MAX=10000000;
	double seno = 0, coseno = 0, tangente = 0, logaritmo = 0, raiz = 0;
	while(i < MAX){
		seno += sin(i);
		coseno += cos(i);
		tangente += tan(i);
		logaritmo += log(i);
		raiz += sqrt(i);
		i++;
	}
}