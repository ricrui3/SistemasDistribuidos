#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <time.h>
#include <stdlib.h>

int puerto = 7200;

typedef struct mensaje{
   uint32_t secuencia;
   uint32_t solicitud[2];
   uint32_t respuesta;
} mensaje;

int main(int argc, char const * argv[])
{
   int porcentaje;
   if(argc ==1)
      porcentaje = 0;
   else
      porcentaje = atoi(argv[1]);
   char p = '%';
   printf("Porcentaje de Mensajes contestados: %d %c\n", porcentaje,p);
   int num[2];
   int s, res, clilen;
   struct sockaddr_in server_addr, msg_to_client_addr;
   mensaje men;
   s = socket(AF_INET, SOCK_DGRAM, 0);
   srand(time(NULL));
   /* se asigna una direccion al socket del servidor*/
   bzero((char *)&server_addr, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;
   server_addr.sin_port = htons(puerto);
   if(bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr))==-1)
      perror("Error, bind");
   clilen = sizeof(msg_to_client_addr);
   while(1) {
      recvfrom(s,&men, sizeof(struct mensaje), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);
      if(rand()%100 >= porcentaje){
         res = men.solicitud[0] + men.solicitud[1];
         printf("No. Secuencia: %d : %d + %d = %d\n",men.secuencia, men.solicitud[0], men.solicitud[1],res);
         men.respuesta = res;
         /* envía la petición al cliente. La estructura msg_to_client_addr contiene la dirección socket del cliente */
         sendto(s, (char *)&men, sizeof(struct mensaje), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
      }
      else
         printf("Solicitud recibida. No contestada\n");
   }
}

