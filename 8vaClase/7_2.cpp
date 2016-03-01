#include <string>
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[]) {
  string megaCadena;
  string miniCadena;

  for(int i = 0;i < 17576; i++){
    for(int j = 0; j < 3; j++){
      int aux = (rand()%25)+65;
      char c = aux;
      megaCadena += c;
      //std::cout << megaCadena << std::endl;
    }
    megaCadena.append(" ");
  }
  int indice = megaCadena.find("IPN");
  std::cout << indice << std::endl;
  std::cout << megaCadena.substr(indice,3) << std::endl;
  return 0;
}
