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
  struct timeval tiempoSis;
  struct timeval st_rto;
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
      gettimeofday(&tiempoSis, NULL);
      long double rto = sckt.getRTO();
      cout << tiempoSis.tv_sec << "." << tiempoSis.tv_usec << endl;
      st_rto.tv_sec = floor(rto);
      st_rto.tv_usec = ceill((rto - floor(rto)) * 1000000);
      timeradd(&tiempoSis, &st_rto, &tiempoSis);
      cout << st_rto.tv_sec << "." << st_rto.tv_usec << endl;
      cout << tiempoSis.tv_sec << "." << tiempoSis.tv_usec << endl;
      cout << !timercmp(&tiempoFinal, &tiempoSis, > ) << endl;
      messCS->timestamp = tiempoSis.tv_sec * 1000000 + tiempoSis.tv_usec;
      envia.inicializaDatos((char *)messCS);
      sckt.envia(envia);
      bool bandera1 = false;
      while (true) {
        gettimeofday(&inicial, NULL);
        tam = sckt.recibeTimeOut(recibe);
        gettimeofday(&tiempoFinal, NULL);
        if (tam < 0) {  // No recide nada
          timersub(&tiempoFinal, &inicial, &tiempoTotal);
          sckt.setTimeOut(tiempoTotal);
          break;
        } else {
          long trecepcion = tiempoFinal.tv_sec * 1000000 + tiempoFinal.tv_usec;
          memcpy(messSC, recibe.obtieneDatos(), tam);
          if (!(trecepcion <= messSC->timestamp)) {
            bandera1 = true;
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
          }
        }
      }
      if (bandera1) break;
    }
    if (j == 7) break;
  }
}
