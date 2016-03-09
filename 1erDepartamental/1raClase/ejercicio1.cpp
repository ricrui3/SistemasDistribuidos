#include <iostream>

const double PI=3.1416;

using namespace std;

int main(){
	int radio;
	double area;
	cout << "Ingrese el radio" << endl;
	cin >>radio;
	area=PI*radio*radio;
	cout << "El area es: " << area <<endl;
}