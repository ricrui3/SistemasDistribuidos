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

using namespace std;

int puerto = 7200;

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

  int numPeticiones2 = 0, numPeticiones = atoi(argv[1]);
  int tam, j;
  // bool petsMax = false;
  struct timeval;
  int numSolTot = 0, numResp = 0;
  float porcDatPerd;
  mensaje *men = new mensaje;
  mensaje *menAux = new mensaje;
  SocketDatagrama sckt(0);
  PaqueteDatagrama envia((char *)&men, sizeof(struct mensaje), (char *)argv[2],
                         puerto);
  PaqueteDatagrama recibe(BUFSIZ);

  sckt.setTimeOut(0, 200000);
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
      if ((tam = sckt.recibeTimeOut(recibe)) != -1) {
        numResp++;
        memcpy(menAux, recibe.obtieneDatos(), sizeof(struct mensaje));
        cout << "Servidor encontrado en la direccion: "
             << recibe.obtieneDireccion() << " la suma de "
             << (*menAux).solicitud[0] << " + " << (*menAux).solicitud[1]
             << " es: " << (*menAux).respuesta << endl;
        break;
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
