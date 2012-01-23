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

  Estudiante * ptr = NULL;
  buscar(ptr, entrada, "Laudin");

  if(ptr != NULL)
    cout << *ptr << endl;
  else
    cout << "La busqueda no obtuvo resultado" << endl;

  cout << endl;

  return 0;
}

bool buscar(Estudiante *& ptr, fstrea & archivo, char nombre[32]) {
  Estudiante aux;

  archivo.seekg(0);
  entrada.read(reinterpret_cast< char *>(&aux), sizeof(aux));

  while(not (aux == nombre) and not entrada.eof()) {
    entrada.read(reinterpret_cast< char *>(&aux), sizeof(aux));
  }

  if(not aux == nombre)
    return false;
  else {
    ptr = &aux;
    return false;
  }
}
