#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int puerto = 7200;

typedef struct mensaje {
  uint32_t secuencia;
  uint32_t solicitud[2];
  uint32_t respuesta;
} mensaje;

int main(void) {
  int s, res;
  socklen_t clilen;
  struct sockaddr_in server_addr, msg_to_client_addr;
  char *menAux = new char[BUFSIZ];
  mensaje *men = new mensaje;
  s = socket(AF_INET, SOCK_DGRAM, 0);

  /* se asigna una direccion al socket del servidor*/
  bzero((char *)&server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(puerto);

  if (bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
	 perror("Error, bind");
  clilen = sizeof(msg_to_client_addr);
  while (1) {
	 recvfrom(s, (char *)&menAux, sizeof(struct mensaje), 0,
				 (struct sockaddr *)&msg_to_client_addr, &clilen);
  	 cout << "-------------->Test" << endl;
	 memcpy(men, menAux, sizeof(struct mensaje));
	 res = (*men).solicitud[0] + (*men).solicitud[1];
	 printf("No. Secuencia: %d : %d + %d = %d\n", (*men).secuencia,
			  (*men).solicitud[0], (*men).solicitud[1], res);
	 (*men).respuesta = 100;
	 /* envía la petición al cliente. La estructura msg_to_client_addr contiene
	  * la dirección socket del cliente */
	 sendto(s, (char *)men, sizeof(struct mensaje), 0,
			  (struct sockaddr *)&msg_to_client_addr, clilen);
  }
}
