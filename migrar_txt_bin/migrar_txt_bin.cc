# include <iostream>
# include <fstream>
# include <list>
using namespace std;

# include <cstdlib>

# include "estudiante.h"

bool leer(Estudiante & e, fstream & archivo, const char delimitador = ';') {
  string buffer;

  if (not archivo)
    return false;

  getline(archivo, buffer, delimitador);
  e.nombre(buffer);

  if (archivo.eof())
    return false;

  getline(archivo, buffer, delimitador);
  e.apellido(buffer);

  getline(archivo, buffer, delimitador);
  e.nacionalidad(buffer);

  getline(archivo, buffer, delimitador);
  e.cedula(atol(buffer.c_str()));

  getline(archivo, buffer, delimitador);
  e.fecha_ingreso(atoi(buffer.c_str()));

  getline(archivo, buffer, '\n');
  e.carrera(buffer.c_str());

  return true;
}

int main(int argc, char * argv[]) {

  if (argc != 3)
  {
    cerr << "Error:" << endl
        << argv[0] << " <archivo de entrada> <archivo de salida>" << endl;
    exit(1);
  }

  string nombre_entrada = string(argv[1]);
  string nombre_salida = string(argv[2]);

  fstream entrada(nombre_entrada.c_str(), ios::in);
  
  if (not entrada)
  {
    cerr << "Error al abrir el archivo " << nombre_entrada << endl;
    exit(1);
  }

  fstream salida(nombre_salida.c_str(), ios::out | ios::binary);

  if( not salida)
  {
    cerr << "Error al abrir el archivo " << nombre_salida << endl;
    exit(1);
  }

  list< Estudiante > estudiantes;

  Estudiante e;

  while(leer(e, entrada)) {
    estudiantes.push_back(e);
  }

  estudiantes.sort();

  while(not estudiantes.empty()) {
    salida.write(reinterpret_cast< const char * >(&estudiantes.front()),
                 sizeof(e));
    estudiantes.pop_front();
  }

  cout << endl;

  return 0;
}
