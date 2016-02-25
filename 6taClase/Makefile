all: static_1 static_2
static_1: static_1.cpp PoligonoIrreg.o
	g++ static_1.cpp PoligonoIrreg.o Coordenada.o -o static_1
static_2: static_2.cpp PoligonoIrreg.o
	g++ static_2.cpp PoligonoIrreg.o Coordenada.o -o static_2
PoligonoIrreg.o: PoligonoIrreg.cpp Coordenada.o PoligonoIrreg.h
	g++ PoligonoIrreg.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c
