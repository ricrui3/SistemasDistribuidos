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
  int numSolTot = 0, numResp = 0;
  int tam;
  int puerto = atoi(argv[2]);
  int offs = 0, j;
  bool final = true;
  struct timeval inicial;
  struct timeval tiempoFinal;
  struct timeval tiempoTotal;
  struct timeval auxT;
  messageCS *messCS = new messageCS;
  messageSC *messSC = new messageSC;
  SocketDatagrama sckt(0);
  PaqueteDatagrama envia((char *)&messCS, sizeof(struct messageCS),
                         (char *)argv[1], puerto);
  PaqueteDatagrama recibe(BUFSIZ);
  sckt.setTimeOut(6, 0);

  messCS->opcode = READ;
  messCS->count = BUF_SIZE;
  messCS->offset = offs;
  strcpy(messCS->name, (char *)argv[3]);

  Archivo archivo((char *)argv[3], O_WRONLY | O_TRUNC | O_CREAT, 0666);
  while (final) {
    for (j = 0; j < 7; j++) {
      numSolTot++;
      // cout << (*men).solicitud[0] << "." << (*men).solicitud[0] << endl;
      gettimeofday(&inicial, NULL);
      // cout << "\ninicial sec: "<< inicial.tv_sec << " inicial usec: " <<
      // inicial.tv_usec << endl;
      auxT.tv_sec = inicial.tv_sec + floor(sckt.getRTO());
      auxT.tv_usec =
          inicial.tv_usec + (sckt.getRTO() - floor(sckt.getRTO())) * 1000000;
      if (auxT.tv_usec >= 1000000) {
        auxT.tv_sec++;
        auxT.tv_usec -= 1000000;
      }
      // cout << "RTO: " << sckt.getRTO() << " SEC: " << auxT.tv_sec << " USEC:
      // " << auxT.tv_usec << endl;
      messSC->timestamp.tv_sec = auxT.tv_sec;
      messSC->timestamp.tv_usec = auxT.tv_usec;
      envia.inicializaDatos((char *)messCS);
      sckt.envia(envia);
      if ((tam = sckt.recibe(recibe)) != -1) {
        gettimeofday(&tiempoFinal, NULL);
        memcpy(messSC, recibe.obtieneDatos(), tam);
        if (timercmp(&messSC->timestamp, &tiempoFinal, <= )) {
          continue;
        }
        timersub(&tiempoFinal, &inicial, &tiempoTotal);

        sckt.setTimeOut(tiempoTotal);
        numResp++;
        cout << "Enviado" << endl;
        offs = offs + messSC->count;
        messCS->offset = offs;
        cout << "offs: " << offs << endl;
        archivo.escribe(messSC->data, messSC->count);
        cout << "tamanio: " << messSC->count << endl << endl;
        if (messSC->count < BUF_SIZE) {
          final = false;
        }
        break;
      } else {
        gettimeofday(&tiempoFinal, NULL);
        timersub(&tiempoFinal, &inicial, &tiempoTotal);
        sckt.setTimeOut(tiempoTotal);
      }
    }
    // if (j == 7) break;
  }
}
