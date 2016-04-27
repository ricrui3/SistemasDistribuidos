#CFLAGS = -Wall -Werror -g

all: cliente3

cliente3: cliente3.cpp Archivo.o SocketDatagrama.o PaqueteDatagrama.o 
	g++ cliente3.cpp Archivo.o SocketDatagrama.o PaqueteDatagrama.o  $(CFLAGS) -o cliente3.out -O2

#cliente2: cliente2.cpp Archivo.o SocketDatagrama.o PaqueteDatagrama.o 
#	g++ cliente2.cpp Archivo.o SocketDatagrama.o PaqueteDatagrama.o  $(CFLAGS) -o cliente2.out -O2

#cliente: cliente.cpp Archivo.o SocketDatagrama.o PaqueteDatagrama.o 
#	g++ cliente.cpp Archivo.o SocketDatagrama.o PaqueteDatagrama.o  $(CFLAGS) -o cliente.out -O2

PaqueteDatagrama: PaqueteDatagrama.cpp
	g++ PaqueteDatagrama.cpp -c

SocketDatagrama: SocketDatagrama.cpp
	g++ SocketDatagrama.cpp -c

Archivo: Archivo.cpp
	g++ Archivo.cpp -c

clean:
	rm -f *.out *.o

clang:
	clang-format-3.4 -i -style=Google *.h *.cpp
