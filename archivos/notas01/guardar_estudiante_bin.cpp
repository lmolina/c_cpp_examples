#include <iostream>
#include <fstream>
using namespace std;

#include <cstdlib>
#include "estudiante.h"

int main() {
  Estudiante e;
  int codigo = 0;

  // Para guardar en un archivo para salida y permite agregar al final del
  // archivo, sin borrar el contenido anterior (si lo habia).
  fstream out("salida.bin", ios::out | ios::binary);

  cout << "Ingrese los datos en el siguiente orden: nombre, nota1, nota2, " 
      << "nota3" << endl << "Escriba fin de archivo para terminar la entrada"
      << endl << "? ";

  while(cin >> e) {

    // Almacenar en el archivo binario. El archivo binario espera datos en
    // forma de char *, asi que se hace una conversion antes de escribir en el
    // archivo
    out.write(reinterpret_cast< const char * >(&e), sizeof(e));
    codigo++;
    cout << "? ";
  }
  cout << endl;
  cout << "Se almacenaron " << codigo << " registros" << endl;
  cout << endl;

  out.close();
/*
  fstream entrada("salida.bin", ios::in | ios::binary);
  if(!entrada) {
    cerr << "Error al abrir el archivo" << endl;
    exit(1);
  }

  //entrada.read(reinterpret_cast< char *>(&e), sizeof(e));
  //cout << e << endl;
  entrada.read(reinterpret_cast< char * >(&e), sizeof(e));
  cout << e << endl;
  entrada.read(reinterpret_cast< char * >(&e), sizeof(e));
  cout << e << endl;
*/
  cout << endl;

  return 0;
}
