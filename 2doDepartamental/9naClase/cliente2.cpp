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
  int offs = 0;
  bool final = true;
  messageCS *messCS = new messageCS;
  messageSC *messSC = new messageSC;
  SocketDatagrama sckt(0);
  PaqueteDatagrama envia((char *)&messCS, sizeof(struct messageCS),
                         (char *)argv[1], puerto);
  PaqueteDatagrama recibe(BUFSIZ);

  messCS->opcode = READ;
  messCS->count = BUF_SIZE;
  messCS->offset = offs;
  strcpy(messCS->name, (char *)argv[3]);

  Archivo archivo((char *)argv[3], O_WRONLY | O_TRUNC | O_CREAT, 0666);
  while (final) {
    envia.inicializaDatos((char *)messCS);
    sckt.envia(envia);
    cout << "Enviado" << endl;
    tam = sckt.recibe(recibe);
    memcpy(messSC, recibe.obtieneDatos(), tam);
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

void setTimeOutRTO(){
  for (j = 0; j < 7; j++) {
      numSolTot++;
      (*men).secuencia = j + 1;
      (*men).solicitud[0] = rand() % 100;
      (*men).solicitud[1] = rand() % 100;
      (*men).respuesta = 0;
      envia.inicializaDatos((char *)men);
      // cout << (*men).solicitud[0] << "." << (*men).solicitud[0] << endl;
      sckt.envia(envia);
      gettimeofday(&inicial, NULL);
      if ((tam = sckt.recibeTimeOut(recibe)) != -1) {
        gettimeofday(&tiempoFinal, NULL);
        timersub(&tiempoFinal, &inicial, &tiempoTotal);
        long double lalala =
            tiempoTotal.tv_usec / float(1000000) + tiempoTotal.tv_sec;
        delta = lalala - srtt;
        srtt = srtt + 0.125 * delta;
        rttvar = rttvar + 0.25 * (absoluto(delta) - rttvar);
        RTO = srtt + 4 * rttvar;
        cout << "RTT Medido: " << ceil(lalala) << "s "
             << (ceil(lalala) - lalala) * 1000000 << "us delta: " << delta
             << " srtt: " << srtt << " rttvar " << rttvar << endl;
        cout << "RTO:  " << floor(RTO) << " micros: " << ceill((RTO-floor(RTO))*1000000)
             << endl;
        sckt.setTimeOut(RTO, ceill((RTO-floor(RTO))*1000000));
        numResp++;
        memcpy(menAux, recibe.obtieneDatos(), sizeof(struct mensaje));
        cout << "Servidor encontrado en la direccion: "
             << recibe.obtieneDireccion() << " la suma de "
             << (*menAux).solicitud[0] << " + " << (*menAux).solicitud[1]
             << " es: " << (*menAux).respuesta << endl << endl;
        break;
      } else {
        gettimeofday(&tiempoFinal, NULL);
        timersub(&tiempoFinal, &inicial, &tiempoTotal);
        long double lalala =
            tiempoTotal.tv_usec / float(1000000) + tiempoTotal.tv_sec;
        delta = lalala - srtt;
        srtt = srtt + 0.125 * delta;
        rttvar = rttvar + 0.25 * (absoluto(delta) - rttvar);
        RTO = srtt + 4 * rttvar;
        cout << "RTT Medido: " << ceil(lalala) << "s "
             << (ceil(lalala) - lalala) * 1000000 << "us delta: " << delta
             << " srtt: " << srtt << " rttvar " << rttvar << endl << endl;
        
        cout << "RTO:  " <<  floor(RTO) << " micros: " << ceill((RTO-floor(RTO))*1000000)
             << endl;
        sckt.setTimeOut(RTO, ceill((RTO-floor(RTO))*1000000));
      }
    }
    if (j == 7) break;
}