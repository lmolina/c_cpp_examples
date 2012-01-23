#include <iostream>
#include <fstream>
using namespace std;

#include <cstdlib>

#include "estudiante.h"

int main() {
  Estudiante e;
  int codigo = 0;

  fstream entrada("salida.bin", ios::in | ios::binary);

  if(!entrada) {
    cerr << "Error al abrir el archivo" << endl;
    exit(1);
  }

  entrada.read(reinterpret_cast< char *>(&e), sizeof(e));

  while(not entrada.eof()) {
    cout << e << endl;;
    entrada.read(reinterpret_cast< char *>(&e), sizeof(e));
  }

  entrada.close();

  cout << endl;

  return 0;
}
