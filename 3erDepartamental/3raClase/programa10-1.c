#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <unistd.h>
#include <arpa/inet.h>

int puerto = 8000;

int main(void) {
  struct sockaddr_in msg_to_server_addr, client_addr;
  int s, num[2], res;
  unsigned char TTL = '1';

  s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *)&TTL, sizeof(TTL));

  /* rellena la dirección del servidor */
  bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
  msg_to_server_addr.sin_family = AF_INET;
  msg_to_server_addr.sin_addr.s_addr = inet_addr((char *)"225.1.1.1");
  msg_to_server_addr.sin_port = htons(puerto);

  /* rellena la direcciòn del cliente*/
  bzero((char *)&client_addr, sizeof(client_addr));
  client_addr.sin_family = AF_INET;
  client_addr.sin_addr.s_addr = INADDR_ANY;

  /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de
   * asignarle uno */
  client_addr.sin_port = htons(0);
  bind(s, (struct sockaddr *)&client_addr, sizeof(client_addr));
  num[0] = 489;
  num[1] = 231;
  /*rellena el mensaje */
  sendto(s, (char *)num, 2 * sizeof(int), 0,
         (struct sockaddr *)&msg_to_server_addr, sizeof(msg_to_server_addr));

  /* se bloquea esperando respuesta */
  recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
  printf("489 + 231 = %d\n", res);
  close(s);
}
