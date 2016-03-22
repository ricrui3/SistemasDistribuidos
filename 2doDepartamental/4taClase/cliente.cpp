#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <cstring>
using namespace std;

#define BUFFSIZE 256
#define LOCAL_PORT 2003
#define REMOTE_PORT 2000

int main(){
	const char * msg;
	PaqueteDatagrama uno("Hola1", 5, "192.168.1.69",REMOTE_PORT);
	PaqueteDatagrama dos(msg, BUFFSIZE, "192.168.1.69",LOCAL_PORT);
	SocketDatagrama s(LOCAL_PORT);
	int tam = s.envia(uno);
	tam = s.recibe(dos);
	if(tam>=0)
		cout << dos.obtieneDatos()<< endl;
}