/* Librerias minimas para el cliente */
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
//--------------------------------------
#include <string.h> //bzero()
#include <stdlib.h> //qsort()
#include <iostream>

using namespace std;

int compara(const void *a, const void *b);
void imprimeMatriz(int array[], int tam);
int puerto = 7200;

int main(void) {
  int tamBuff = 70000;
  int num[tamBuff];
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
    n = recvfrom(s, (char *)num, tamBuff, 0,
                 (struct sockaddr *)&msg_to_client_addr, &clilen);
    int tam = n / 4;

    cout << "\nTamanio de n: " << n << " equivalente a " << tam << " enteros"
         << endl;

    // Imprime el arreglo con los valores desordenados
    cout << "El arreglo de numeros aleatorios de tamaño " << tam
         << " es:" << endl;
    imprimeMatriz(num,tam);

    /* envía la petición al cliente. La estructura msg_to_client_addr contiene
     * la dirección socket del cliente */
    qsort(num, tam, sizeof(int), compara);

    // Imprime el arreglo con los valores ordenados
    cout << "\nEl arreglo de numeros ordenados de tamaño " << tam
         << " es:" << endl;
    imprimeMatriz(num,tam);

    sendto(s, (char *)num, tam * sizeof(int), 0,
           (struct sockaddr *)&msg_to_client_addr, clilen);
  }
}

int compara(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
void imprimeMatriz(int array[], int tam) {
  for (int i = 0; i < tam; ++i) {
    cout << array[i] << " ";
  }
  cout << "\n" << endl;
}