#CPPFLAGS = -Wall -Werror -g
all: clienteMono
clienteMono: clienteMono.cpp PaqueteDatagrama.o SocketDatagrama.o
	g++ clienteMono.cpp PaqueteDatagrama.o SocketDatagrama.o $(CPPFLAGS) -o clienteMono.out
SocketDatagrama: SocketDatagrama.cpp PaqueteDatagrama.o
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama: PaqueteDatagrama.cpp
	g++ PaqueteDatagrama.cpp -c