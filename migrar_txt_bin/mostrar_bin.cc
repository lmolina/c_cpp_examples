#include <iostream>
#include <fstream>
using namespace std;

#include <cstdlib>

#include "estudiante.h"

int main(int argc, char * argv[]) {
  Estudiante e;

  if (argc != 2)
  {
    cerr << "Error:" << endl
        << argv[0] << " <archivo de entrada>" << endl;
    exit(1);
  }

  string nombre_salida = string(argv[1]);

  fstream entrada(nombre_salida.c_str(), ios::in | ios::binary);

  if(not entrada) {
    cerr << "Error al abrir " << nombre_salida << endl;
    exit(1);
  }

  entrada.read(reinterpret_cast< char *>(&e), sizeof(e));

  while(not entrada.eof()) {
    cout << e << endl;
    entrada.read(reinterpret_cast< char *>(&e), sizeof(e));
  }

  entrada.close();

  cout << endl;

  return 0;
}
