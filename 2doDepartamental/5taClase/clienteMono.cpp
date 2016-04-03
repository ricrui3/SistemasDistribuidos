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
  // char ipDir[] = "192.168.0.1";
  char ipDir[] = "127.0.0.1";
  struct timeval timerInicio;
  struct timeval timerFinal;
  struct timeval resta;
  cout << ipDir << endl;

  SocketDatagrama sckt(0);
  PaqueteDatagrama envia((char *)num, sizeof(int) * 2, ipDir, puerto);
  PaqueteDatagrama recibe(BUFSIZ);

  sckt.setTimeOut(0,500000);

  for (i = 100; i < 255; i++) {
    sckt.envia(envia);
    gettimeofday(&timerInicio,NULL);
    if ((tam = sckt.recibeTimeOut(recibe)) != -1) {
      //sleep(1);
      gettimeofday(&timerFinal,NULL);
      timersub(&timerFinal, &timerInicio, &resta);
      cout << "Servidor encontrado en la direccion: "
           << recibe.obtieneDireccion() << " con un timepo de: " << resta.tv_sec << "    micros: " << resta.tv_usec << endl;

    }
    sprintf(ipDir, "192.168.0.%d", i);
    cout << ipDir << endl;
    envia.inicializaIp(ipDir);
    if (i == 254) {
      i = 90;
    }
  }
}
