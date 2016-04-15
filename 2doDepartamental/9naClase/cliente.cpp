#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include "Archivo.h"
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <fcntl.h>

using namespace std;

int main(int argc, char const *argv[]) {

  if (argc != 4) {
    cout << "ingrese" << argv[0] << "direccion_ip puerto archivo" << endl;
    exit(0);
  }

  int tam;
  int puerto = atoi(argv[2]);
  messageCS * messCS = new messageCS;
  messageSC * messSC = new messageSC;
  SocketDatagrama sckt(0);
  PaqueteDatagrama envia((char *)&messCS, sizeof(struct messageCS), (char *)argv[1],
                         puerto);
  PaqueteDatagrama recibe(BUFSIZ);
  
  messCS->opcode = READ; 
  messCS->count = 687; 
  messCS->offset = 0;
  strcpy(messCS->name, (char*)argv[3]);
  envia.inicializaDatos((char *)messCS);
  sckt.envia(envia);
  cout << "Enviado" << endl;
  tam = sckt.recibe(recibe);
  Archivo archivo((char*)argv[3],O_WRONLY | O_TRUNC | O_CREAT, 0666);
  memcpy(messSC, recibe.obtieneDatos(), tam);
  archivo.escribe(messSC->data,messSC->count);
}