#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
using namespace std;

SocketDatagrama::SocketDatagrama(int p){
	s = socket(AF_INET, SOCK_DGRAM,0);
	bzero((char*)&direccionLocal, sizeof(direccionLocal));
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	direccionLocal.sin_port = htons(p);
	if(bind(s,(struct sockaddr *)&direccionLocal,sizeof(direccionLocal))==-1)
		cout << "Hubo un error al crear el socket.\n";
}

SocketDatagrama::~SocketDatagrama(){
	close(s);
}

int SocketDatagrama::recibe(PaqueteDatagrama &p){
	int tam;
	char * msn;
	unsigned int n = sizeof(direccionForeanea);
	if((tam=recvfrom(s,p.obtieneDatos(),p.obtieneLongitud(),0,(struct sockaddr *)&direccionForeanea,&n))<=0)
		cout << "Hubo un error al recibir el mensaje.\n" << tam << endl;
	else
		cout << "Mensaje recibido.\n";
	return tam;
}

int SocketDatagrama::envia(PaqueteDatagrama &p){
	bzero((char *)&direccionForeanea, sizeof(direccionForeanea));
	direccionForeanea.sin_family = AF_INET;
	direccionForeanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
	direccionForeanea.sin_port = htons(p.obtienePuerto());
	int tam;
	if((tam = sendto(s,p.obtieneDatos(),p.obtieneLongitud(),0,(struct sockaddr *)&direccionForeanea,sizeof(direccionForeanea)))==-1)
		cout << "Hubo un error al enviar el mensaje.\n";
	else{
		cout << "Mnsaje enviado\n";
	}
	return tam;
}