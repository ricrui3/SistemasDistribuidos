#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>

using namespace std;

int puerto = 7200;

int main(int argc, char const *argv[]) {
  pid_t pid;
  int i = 1;
  int num[2] = {3, 4}, tam, estado;
  //char ipDir[] = "192.168.0.1";
  char ipDir[] = "127.0.0.1";
  cout << ipDir << endl;

  SocketDatagrama sckt(0);

  pid = fork();

  switch (pid) {
    case -1: {
      perror("Error en la creacion de hijos");
      break;
    }
    case 0: {
      cout << "Proceso padre" << endl;
      PaqueteDatagrama envia((char *)num, sizeof(int) * 2, ipDir, puerto);
      for (i = 1; i < 255; i++) {
        sckt.envia(envia);
        sprintf(ipDir, "192.168.0.%d", i);
        // cout << ipDir << endl;
        envia.inicializaIp(ipDir);
        if(i == 254){
        	i = 1;
        }
      }
      break;
    }
    default: {
      PaqueteDatagrama recibe(BUFSIZ);
      while (true) {
        cout << "Test" << endl;
        if ((tam = sckt.recibe(recibe)) != -1) {
          cout << "Servidor encontrado en la direccion: "
               << recibe.obtieneDireccion() << endl;
        }
      }
      break;
    }
  }
  return 0;
}

