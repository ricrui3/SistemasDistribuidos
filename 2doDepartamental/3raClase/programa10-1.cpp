#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int puerto = 7200;

int main(int argc, char const *argv[]) {

  struct sockaddr_in msg_to_server_addr, client_addr, msg_to_client;
  socklen_t serlen;
  int s, res, i;
  int tam = 20;
  int array[tam], num[tam];
  serlen = sizeof(msg_to_client);
  s = socket(AF_INET, SOCK_DGRAM, 0);

  // Llena el arreglo con los valores
  for (int i = 0; i < tam - 1; ++i) {
    array[i] = rand() % 100;
    cout << array[i] << endl;
  }

  /* rellena la dirección del servidor */
  bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
  msg_to_server_addr.sin_family = AF_INET;
  msg_to_server_addr.sin_addr.s_addr = inet_addr(argv[1]);
  msg_to_server_addr.sin_port = htons(puerto);

  /* rellena la direcciòn del cliente*/
  bzero((char *)&client_addr, sizeof(client_addr));
  client_addr.sin_family = AF_INET;
  client_addr.sin_addr.s_addr = INADDR_ANY;

  /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de
   * asignarle uno */
  client_addr.sin_port = htons(0);
  bind(s, (struct sockaddr *)&client_addr, sizeof(client_addr));
  for (int i = 0; i < tam; ++i) {
    num[i] = array[i];
  }
  
  sendto(s, (char *)num, tam * sizeof(int), 0,
         (struct sockaddr *)&msg_to_server_addr, sizeof(msg_to_server_addr));

  /* se bloquea esperando respuesta */
  recvfrom(s, (char *)&res, sizeof(int), 0, (struct sockaddr *)&msg_to_client,
           &serlen);

  /* mostrado de la direccion ip */
  unsigned char aux[4];
  memcpy(aux, &msg_to_client.sin_addr.s_addr, 4);
  for (i = 0; i < 4; i++) {
    // aux[i]=ntohs(aux[i]);
    printf("\nLa posicion %d tiene: %d,", i, aux[i]);
  }

  u_short puer;
  memcpy(&puer, &msg_to_client.sin_port, 2);
  puer = ntohs(puer);
  printf("\n El puerto es: %d\n", puer);
  printf("2 + 5 = %d\n", res);
  close(s);
  return 0;
}
