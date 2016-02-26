#include <iostream>

using namespace std;

int main(){
	double c = 20.4;
	double f;
	int resul;
	f = (1.8* c)  + 32.0;
	resul = static_cast <int> (f);
	cout << "Fahrenheit es: "<< resul << endl;
}