#ifndef SOCKETDATAGRAMA_H
#define SOCKETDATAGRAMA_H
#include "PaqueteDatagrama.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

class SocketDatagrama {
 public:
  SocketDatagrama(int);
  ~SocketDatagrama();
  int recibe(PaqueteDatagrama& p);
  int envia(PaqueteDatagrama& p);

 private:
  struct sockaddr_in direccionLocal;
  struct sockaddr_in direccionForeanea;
  int s;
};

#endif