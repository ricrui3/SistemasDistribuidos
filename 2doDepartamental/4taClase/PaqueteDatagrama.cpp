#include "PaqueteDatagrama.h"
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
using namespace std;

void imprimeDatos(char *datos) {
  // cout << sizeof(datos) << endl;
  while (*datos != '\0') {
    cout << *datos;
    datos++;
  }
  cout << "\n" << endl;
}

PaqueteDatagrama::PaqueteDatagrama(char* d, unsigned int l, char* i, int p) {
  datos = new char[sizeof(d)];
  datos = d;
  //longitud = l;
  //strcpy(ip, i);
  //puerto = p;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int l) {
  datos = new char[l];
  longitud = l;
}

PaqueteDatagrama::~PaqueteDatagrama() { delete datos; }

char* PaqueteDatagrama::obtieneDireccion() { return ip; }

unsigned int PaqueteDatagrama::obtieneLongitud() { return longitud; }

int PaqueteDatagrama::obtienePuerto() { return puerto; }

char* PaqueteDatagrama::obtieneDatos() { return datos; }

void PaqueteDatagrama::inicializaPuerto(int p) { puerto = p; }

void PaqueteDatagrama::inicializaIp(char* i) { strcpy(ip, i); }

void PaqueteDatagrama::inicializaDatos(char* d) { datos = d; }

