#include "Archivo.h"
#include <stdlib.h>  //exit()
#include <fcntl.h>   //open(), O_RDONLY, O_WRONLY, O_TRUNC, etc
#include <stdio.h>   //BUFSIZ, printf(), perror();
#include <unistd.h>  //write(), read(), close()

#include <iostream>
using namespace std;

Archivo::Archivo(const char *filename, int banderas) {
  if ((fd = open(filename, banderas)) == -1) {
    perror(filename);
    exit(-1);
  }
}

Archivo::Archivo(const char *filename, int banderas, mode_t modo) {
  if ((fd = open(filename, banderas, modo)) == -1) {
    perror(filename);
    exit(-1);
  }
}

Archivo::~Archivo() {}

size_t Archivo::lee(size_t nbytes) {
  contenido = new char[nbytes];
  //cout << "nbytes contenido: " << nbytes * sizeof(char) << endl;
  nbytes = read(fd, contenido, nbytes);
  //cout << "nbytes leidos: " << nbytes * sizeof(char) << endl;
  return nbytes;
}

size_t Archivo::escribe(const void *buffer, size_t nbytes) {
  write(fd, buffer, nbytes);
  return nbytes;
}

char *Archivo::get_contenido() { return contenido; }

void Archivo::cerrar() { close(fd); }

// public:
//  Archivo(const char *filename, int banderas);
//  Archivo(const char *filename, int banderas, mode_t modo);
//  ~Archivo();
//  size_t lee(size_t nbytes);
//  size_t escribe(const void *buffer, size_t nbytes);
//  char *get_contenido();
//  void cerrar();