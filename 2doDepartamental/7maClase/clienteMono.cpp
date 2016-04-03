#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
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

  int numPeticiones = atoi(argv[1]);
  int tam;
  struct timeval;

  mensaje men;
  mensaje *menAux  = NULL;
  SocketDatagrama sckt(0);
  PaqueteDatagrama envia((char *)&men, sizeof(men), (char *)argv[2],
                         puerto);
  PaqueteDatagrama recibe(BUFSIZ);

  sckt.setTimeOut(0, 500000);

  for (int i = 0; i < numPeticiones; ++i) {
    men.secuencia = i + 1;
    men.solicitud[0] = 3;
    men.solicitud[1] = 4;
    men.respuesta = 0;
    sckt.envia(envia);
    if ((tam = sckt.recibeTimeOut(recibe)) != -1) {
      memcpy(menAux, recibe.obtieneDatos(), sizeof(mensaje));
      cout << "Test" << endl;
      cout << "Servidor encontrado en la direccion: "
           << recibe.obtieneDireccion() << " la suma de "
           << (*menAux).solicitud[0] << " " << (*menAux).solicitud[1]
           << " es: " << (*menAux).respuesta << endl;
      break;
    }
  }

}
