#include "PaqueteDatagrama.h"
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

using namespace std;

PaqueteDatagrama::PaqueteDatagrama(const char * d, unsigned int l, const char* i, int p){
	datos = new char[strlen(d)];
	memcpy(datos, d, size_t(strlen(d)));
	longitud = l;
	strcpy(ip, i);
	puerto = p;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int l){
	datos = new char[l];
	longitud = l;
}

PaqueteDatagrama::~PaqueteDatagrama(){
	delete datos;
}

char * PaqueteDatagrama::obtieneDireccion(){
	return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud(){
	return longitud;
}

int PaqueteDatagrama::obtienePuerto(){
	return puerto;
}

char * PaqueteDatagrama::obtieneDatos(){
	return datos;
}

void PaqueteDatagrama::inicializaPuerto(int p){
	puerto = p;
}

void PaqueteDatagrama::inicializaIp(char * i){
	strcpy(ip, i);
}

void PaqueteDatagrama::inicializaDatos(char * d){
	datos = new char[strlen(d)];
	memcpy(datos, d, size_t(strlen(d)));
	longitud = strlen(d);
}