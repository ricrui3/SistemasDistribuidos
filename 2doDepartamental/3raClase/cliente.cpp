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
  int s, n;
  cout << argc << endl;
  int tam = atoi(argv[2]);
  int array[tam], num[tam], res[tam];
  serlen = sizeof(msg_to_client);
  s = socket(AF_INET, SOCK_DGRAM, 0);

  // Llena el arreglo con los valores
  cout << "\nEl arreglo de numeros aleatorios de tamaño " << tam
       << " es:" << endl;
  for (int i = 0; i < tam; ++i) {
    array[i] = rand() % 100;
    cout << array[i] << " ";
  }
  cout << endl;

  /* rellena la dirección del servidor */
  bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
  msg_to_server_addr.sin_family = AF_INET;
  cout << "La direccion ip que ingreso es: " << argv[1] << endl;
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
  n = recvfrom(s, (char *)res, tam * sizeof(int), 0,
               (struct sockaddr *)&msg_to_client, &serlen);
  // Imprime el arreglo con los valores ordenados
  cout << "\nEl arreglo de numeros ordenados de tamaño " << tam
       << " es:" << endl;
  for (int i = 0; i < tam; ++i) {
    cout << res[i] << " ";
  }
  cout << "\n" << endl;

  // u_short puer;
  // memcpy(&puer, &msg_to_client.sin_port, 2);
  // puer = ntohs(puer);
  // printf("\n El puerto es: %d\n", puer);
  // printf("2 + 5 = %d\n", res);
  close(s);
  return 0;
}
