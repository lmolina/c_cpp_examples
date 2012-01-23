#include <iostream>
#include <fstream>
using namespace std;

#include "estudiante.h"

int main() {
  Estudiante e;
  int codigo = 0;

  // El operador de flujo y el objeto cout realizan la conversion apropiada a una
  // cadena de caracteres que pueda ser mostrada por la pantalla
  cout << e << endl;
  cin >> e;
  cout << codigo++ << e << endl;

  // Para guardar en un archivo para salida y permite agregar al final del
  // archivo, sin borrar el contenido anterior (si lo habia).
  fstream out("salida.txt", ios::out | ios::ate);
  out << e << endl;

  cout << "Ingrese los datos en el siguiente orden: nombre, nota1, nota2, " 
      << "nota3" << endl << "Escriba fin de archivo para terminar la entrada"
      << endl << "? ";

  while(cin >> e) {
    out << codigo++ << ' ' << e << endl;
    cout << "? ";
  }

  cout << endl;

  return 0;
}
