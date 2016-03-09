main9: main9.cpp Cilindro.o Toroide.o
	g++ main9.cpp Cilindro.o Circulo.o Toroide.o -o main9.out

Toroide.o: Toroide.cpp Cilindro.o Toroide.h
	g++ Toroide.cpp -c
Cilindro.o: Cilindro.cpp Circulo.o Cilindro.h
	g++ Cilindro.cpp -c
Circulo.o: Circulo.cpp Circulo.h
	g++ Circulo.cpp -c
