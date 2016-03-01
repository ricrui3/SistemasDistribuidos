#include <iostream>
#include "math.h"

using namespace std;

int main(){
	int i=0, MAX=1000000;
	double seno, coseno, tangente, logaritmo, raiz;
	while(i < MAX){
		seno += sin(i);
		coseno += cos(i);
		tangente += tan(i);
		logaritmo += log(i);
		raiz += sqrt(i);
		i++;
	}
}