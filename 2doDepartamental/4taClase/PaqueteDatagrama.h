#ifndef PAQUETEDATAGRAMA_H_
#define PAQUETEDATAGRAMA_H_

class PaqueteDatagrama {
 public:
  PaqueteDatagrama(const char *, unsigned int, const char *, int);
  PaqueteDatagrama(unsigned int);
  ~PaqueteDatagrama();
  char *obtieneDireccion();
  char *obtieneDatos();
  unsigned int obtieneLongitud();
  int obtienePuerto();
  void inicializaPuerto(int);
  void inicializaIp(char *);
  void inicializaDatos(char *);

 private:
  char *datos;
  char ip[16];
  unsigned int longitud;
  int puerto;
};

#endif