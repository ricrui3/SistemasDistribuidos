#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>

//###################################
//#                                 #
//#            Cliente              #
//#                                 #
//###################################

#define BUFFSIZE 1
/* Puerto donde reside el servicio */
#define PUERTO 50000

int main(int argc, char const *argv[]){
  int s, n;
  int sockLen;
  struct sockaddr_in sa;
  char buffer[BUFFSIZE];
  FILE *archivo;

  /* Direccion IP del servidor de tiempo */
  char* host = (char*) argv[2];

  if(argc < 3){
    perror("El programa se ejectuta de la siguiente manera:\n./clientFiles <archivo a enviar> <direccionIP del servidor>");
    exit(EXIT_FAILURE);
  }

  /*Se abre el archivo a enviar*/
  archivo = fopen(argv[1], "rb");

  /*Se verifica la integridad del archivo*/
  if(!archivo){
    perror("Error al abrir el archivo");
    exit(EXIT_FAILURE);
  }

  //Abre un socket
  if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(1);
  }

  //Inicializa familia, puerto como 50000
  sa.sin_family = AF_INET;
  sa.sin_port = htons(PUERTO);

  //Convierte una direccion ipv4 a notacion binaria
  if (!inet_aton(host, &sa.sin_addr)) {
    perror("inet_aton");
    exit(1);
  }

  sockLen = sizeof(sa);

  if (connect(s, (struct sockaddr *)&sa, sizeof(sa)) < 0) {
    perror("connect");
    close(s);
    exit(1);
  }

  printf("Se ha conectado con el servidor:%s\n",(char *)inet_ntoa(sa.sin_addr));

  /*Se envia el archivo*/
  while(!feof(archivo)){
    fread(buffer,sizeof(char),BUFFSIZE,archivo);
    if(send(s,buffer,BUFFSIZE,0) == -1)
      perror("Error al enviar el arvhivo:");
  }

  //Lee la respuesta del servidor
  if ((n = read(s, buffer, BUFFSIZE)) < 0) {
    perror("read");
    exit(1);
  }

  //cierra el socket
  close(s);

  //Escribe en consola la respuesta del socket
  write(STDOUT_FILENO, buffer, n);

  exit(0);
}
