#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/wait.h>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int puerto = 7200;

long double absoluto(long double valor);

typedef struct mensaje {
  uint32_t secuencia;     // Numero de secuencia
  uint32_t solicitud[2];  // pareja de números enviados por el cliente para su
                          // suma
  uint32_t respuesta;
  // respuesta enviada por el servidor
} mensaje;

int main(int argc, char const *argv[]) {

  if (argc != 3) {
    cout << "ingrese numPeticiones direccion ip" << endl;
    exit(0);
  }

  long double RTO;
  long double srtt;
  long double rttvar;
  long double delta;
  int numPeticiones2 = 0, numPeticiones = atoi(argv[1]);
  int tam, j;
  // bool petsMax = false;
  struct timeval inicial;
  struct timeval tiempoFinal;
  struct timeval tiempoTotal;
  int numSolTot = 0, numResp = 0;
  float porcDatPerd;
  mensaje *men = new mensaje;
  mensaje *menAux = new mensaje;
  SocketDatagrama sckt(0);
  PaqueteDatagrama envia((char *)&men, sizeof(struct mensaje), (char *)argv[2],
                         puerto);
  PaqueteDatagrama recibe(BUFSIZ);

  srtt = 0;
  rttvar = 3;
  RTO = srtt + 2 * rttvar;
  cout << "--  " << RTO << " " << RTO-floor(RTO) << endl;
  sckt.setTimeOut(RTO, RTO-floor(RTO));

  for (int i = 0; i < numPeticiones; ++i) {
    numPeticiones2++;
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
  cout << "El numero de peticiones fue: " << numPeticiones2 << endl;
  cout << "El número de solicitudes totales hechas al servidor (incluyendo los "
          "reenvíos): " << numSolTot << endl;
  cout << "El número de solicitudes respondidas por el servidor: " << numResp
       << endl;
  porcDatPerd = 100 - (numResp * 100) / numSolTot;
  cout << "Porcentaje de datagramas perdidos: " << porcDatPerd << endl;
}

long double absoluto(long double valor) {
  if (valor >= 0) {
    return valor;
  } else {
    return -valor;
  }
}