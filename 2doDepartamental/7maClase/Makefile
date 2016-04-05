CPPFLAGS = -Wall -Werror -g
all: clienteMono programa9-1
programa9-1: programa9-1.cpp PaqueteDatagrama.o SocketDatagrama.o
	g++ programa9-1.cpp PaqueteDatagrama.o SocketDatagrama.o $(CPPFLAGS) -o programa9-1.out
clienteMono: clienteMono.cpp PaqueteDatagrama.o SocketDatagrama.o
	g++ clienteMono.cpp PaqueteDatagrama.o SocketDatagrama.o $(CPPFLAGS) -o clienteMono.out
SocketDatagrama: SocketDatagrama.cpp PaqueteDatagrama.o
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama: PaqueteDatagrama.cpp
	g++ PaqueteDatagrama.cpp -c