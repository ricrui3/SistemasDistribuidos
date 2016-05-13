#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>

//###################################
//#                                 #
//#            Servidor             #
//#                                 #
//###################################

/* Puerto donde reside nuestro servicio de tiempo */
#define PUERTO 50000

#define BUFFSIZE 1

int main(void) {
  int sckt, c, n;
  int clientLen;
  FILE *file;
  struct sockaddr_in sa;
  struct sockaddr_in clSockAddr;
  char buffer[BUFFSIZE];
  time_t t;

  // Se crea el socket
  if ((sckt = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(1);
  }
  sa.sin_family = AF_INET;
  sa.sin_port = htons(PUERTO);
  sa.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(sckt, (struct sockaddr *)&sa, sizeof(sa)) < 0) {
    perror("bind");
    close(sckt);
    exit(EXIT_FAILURE);
  }

  if (listen(sckt, 5) < 0) {
    perror("listen");
    close(sckt);
    exit(EXIT_FAILURE);
  }

  do {
    int recibido = -1;
    clientLen = sizeof(clSockAddr);

    if ((c = accept(sckt, (struct sockaddr *)&clSockAddr, &clientLen)) < 0) {
      perror("accept");
      exit(1);
    }

    /*Se configura la dirección del cliente*/
    clSockAddr.sin_family = AF_INET;
    clSockAddr.sin_port = htons(PUERTO);
    printf("Cliente conectado: %s\n", inet_ntoa(clSockAddr.sin_addr));

    t = time(NULL);
    n = sprintf(buffer, "%s", ctime(&t));
    /*Se abre el archivo para escritura*/
    file = fopen("archivoRecibido.mp4", "wb");
    while ((recibido = recv(sckt, buffer, BUFFSIZE, 0)) > 0) {
      printf("%s", buffer);
      fwrite(buffer, sizeof(char), 1, file);
    }  // Termina la recepción del archivo
    fclose(file);
  } while (1);
    close(c);
}
