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

int compara(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int puerto = 7200;

int main(void) {
  int tam = 20;
  int num[tam];
  int s, n;
  socklen_t clilen;
  struct sockaddr_in server_addr, msg_to_client_addr;

  s = socket(AF_INET, SOCK_DGRAM, 0);

  /* se asigna una direccion al socket del servidor*/
  bzero((char *)&server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(puerto);
  bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
  clilen = sizeof(msg_to_client_addr);
  while (1) {
    n = recvfrom(s, (char *)num, tam * sizeof(int), 0,
                 (struct sockaddr *)&msg_to_client_addr, &clilen);

    cout << num[0] << num[1] << endl;
    /* envía la petición al cliente. La estructura msg_to_client_addr contiene
     * la dirección socket del cliente */
    qsort(num, tam, sizeof(int), compara);
    cout << num[0] << num[1] << endl;
    sendto(s, (char *)num, tam * sizeof(int), 0,
           (struct sockaddr *)&msg_to_client_addr, clilen);
  }
}