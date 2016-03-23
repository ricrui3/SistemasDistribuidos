all: servidor cliente
servidor: servidor.cpp PaqueteDatagrama.o SocketDatagrama.o
	g++ servidor.cpp PaqueteDatagrama.o SocketDatagrama.o -o servidor.out
cliente: cliente.cpp PaqueteDatagrama.o SocketDatagrama.o
	g++ cliente.cpp PaqueteDatagrama.o SocketDatagrama.o -o cliente.out
SocketDatagrama: SocketDatagrama.cpp PaqueteDatagrama.o
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama: PaqueteDatagrama.cpp
	g++ PaqueteDatagrama.cpp -c