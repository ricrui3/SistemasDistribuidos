/* Librerias minimas para el cliente */
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
//--------------------------------------
#include <strings.h>    //bzero()
#include <stdlib.h>     //rand(), atoi()
#include <arpa/inet.h>  //inet_addr
#include <unistd.h>     //close()
#include <iostream>     //cout, std
using namespace std;

void arregloAleatorio(int array[], int tam);
void imprimeMatriz(int array[], int tam);

int puerto = 7200;

// Para la correcta ejecucion de este archivo es necesario ejecutarlo de la
// siguiente manera:
//  ./cliente.out [Direccion ip] [tamaño del arreglo de numeros aleatorios]
//  Ejemplo:
//  ./cliente.out 127.0.0.1 50

int main(int argc, char const *argv[]) {

  int s, n;
  int tam = atoi(argv[2]);
  int num[tam], res[tam];

  // El socket creado no tiene ninguna direccion, se deja en 0 el protocolo para
  //  dejarlo en manos del sistema
  s = socket(AF_INET, SOCK_DGRAM, 0);

  // sockaddr_in es una estructura que almacena la direccion generica de un
  //  socket, en este caso es el socket internet
  struct sockaddr_in msg_to_server_addr, client_addr, msg_to_client;
  // Longitud del tamaño del tamaño del paquete----
  socklen_t serlen;
  serlen = sizeof(msg_to_client);
  //----------------------------------------------

  // Llena de valores aleatorios el arreglo
  arregloAleatorio(num, tam);

  // Imprime el arreglo con los valores aleatorios
  cout << "\nEl arreglo de numeros aleatorios de tamaño " << tam
       << " es:" << endl;
  imprimeMatriz(num, tam);

  /*Rellena la dirección del servidor */
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

  sendto(s, (char *)num, tam * sizeof(int), 0,
         (struct sockaddr *)&msg_to_server_addr, sizeof(msg_to_server_addr));

  /* se bloquea esperando respuesta */
  n = recvfrom(s, (char *)res, tam * sizeof(int), 0,
               (struct sockaddr *)&msg_to_client, &serlen);
  // Imprime el arreglo con los valores ordenados
  cout << "\nEl arreglo de numeros ordenados de tamaño " << tam
       << " es:" << endl;
      tam = n/4;
  imprimeMatriz(res, tam);

  // u_short puer;
  // memcpy(&puer, &msg_to_client.sin_port, 2);
  // puer = ntohs(puer);
  // printf("\n El puerto es: %d\n", puer);
  // printf("2 + 5 = %d\n", res);
  close(s);
  return 0;
}

void arregloAleatorio(int array[], int tam) {
  for (int i = 0; i < tam; ++i) {
    array[i] = rand();
  }
}

void imprimeMatriz(int array[], int tam) {
  for (int i = 0; i < tam; ++i) {
    cout << array[i] << " ";
  }
  cout << endl;
}