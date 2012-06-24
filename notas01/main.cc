# include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

# include <string>
using std::string;

# include <iomanip>
using std::setw;

# include "estudiante.h"
# include "archivo_estudiante.h"

enum Opciones {
  Salir = 0,
  Agregar,
  Mostrar,
  Eliminar,
  Modificar,
  Mezclar,
  Parcionar,
  BuscarCedula,
  BuscarNombre,
  BuscarOtro
};

int menu();
void agregar(ArchivoEstudiante &);
void mostrar(ArchivoEstudiante &);
void eliminar(ArchivoEstudiante &);
void buscar_cedula(ArchivoEstudiante &);
void buscar_nombre(ArchivoEstudiante &);

int main() {
  int opc;

  ArchivoEstudiante archivo("estudiantes.txt");

  do {
    opc = menu();
  
    switch (opc) {
      case Agregar: 
        agregar(archivo);
        break;

      case Mostrar:
        mostrar(archivo);
        break;

      case Eliminar:
        eliminar(archivo);
        break;

/*
      case Modificar:
        modificar();
        break;

      case Mezclar:
        mezclar();
        break;

      case Particionar:
        particionar();
        break;
*/

      case BuscarCedula:
        buscar_cedula(archivo);
        break;

      case BuscarNombre:
        buscar_nombre(archivo);
        break;

/*
      case BuscarOtro:
        buscar_otro();
        break;
*/
      case Salir:
        break;

      default:
        cerr << "Opcion incorrecta" << endl;
        break;
    }
  } while (opc != Salir);

}

int menu() {
  int opc;

  cout << endl
      << endl 
      << "Opciones" << endl
      << endl
      << Agregar << ") Agregar" << endl
      << Mostrar << ") Mostrar" << endl
      << Eliminar << ") Eliminar" << endl
      << ") Modificar" << endl
      << ") Mezclar" << endl
      << ") Particionar" << endl
      << BuscarCedula << ") Buscar por cedula" << endl
      << BuscarNombre << ") Buscar por nombre" << endl
      << ") Buscar por otro" << endl
      << endl
      << Salir << ") Salir" << endl
      << endl
      << "? ";

  cin >> opc;

  return opc;
}

void agregar(ArchivoEstudiante & archivo) {
  Estudiante e;
  string nombre;
  long cedula;
  int nota;

  cout << "Agregar estudiante" << endl;

  cin.get();
  cout << "Nombre? ";
  getline(cin, nombre);
  e.nombre(nombre);

  cout << "Cedula? ";
  cin >> cedula;
  e.cedula(cedula);

  cout << "Nota 1? ";
  cin >> nota;
  e.nota1(nota);

  cout << "Nota 2? ";
  cin >> nota;
  e.nota2(nota);

  cout << "Nota 3? ";
  cin >> nota;
  e.nota3(nota);

  archivo.agregar(e);
}

void mostrar(ArchivoEstudiante & archivo) {

  cout << endl
      << "Todos los registros" << endl
      << setw(34) << left << "Nombre" << setw(16) << "Cedula"
      << setw(8) << "Nota 1" << setw(8) << "Nota 2" << setw(8) << "Nota 3"
      << setw(8) << "Promedio" << endl;

  archivo.mostrar();

  cout << endl;
}

void eliminar(ArchivoEstudiante & archivo) {
  long cedula;
  int opc;
  Estudiante tmp;

  cout << "Cedula a eliminar? ";
  cin >> cedula;

  tmp = archivo.buscar_por_cedula(cedula);

  if (tmp.cedula() != -1) {
    cout << "Seguro que desea eliminar el sgte registro?" << endl
        << endl
        << tmp << endl
        << endl
        << "1: si, otro: no"
        << "? ";
    cin >> opc;


    if (opc == 1) {
      archivo.eliminar(cedula);
      cout << "Hecho" << endl;
    }
    else
      cout << "No se eliminara el registro" << endl;
  }
  else
    cout << "No se encontro registro con la cedula indicada" << endl;
}

void buscar_cedula(ArchivoEstudiante & archivo) {
  long cedula;
  Estudiante tmp;

  cout << "Cedula? ";
  cin >> cedula;

  tmp = archivo.buscar_por_cedula(cedula);

  if (tmp.cedula() != -1) {
    cout << endl
        << endl
        << "Todos los registros" << endl
        << setw(34) << left << "Nombre" << setw(16) << "Cedula"
        << setw(8) << "Nota 1" << setw(8) << "Nota 2" << setw(8) << "Nota 3"
        << setw(8) << "Promedio" << endl;

    cout << tmp << endl;
  }
  else
    cout << "Cedula no encontrada" << endl;
}

void buscar_nombre(ArchivoEstudiante & archivo) {
  list<Estudiante> tmp;
  list<Estudiante>::iterator it;

  string nombre;

  cin.get();
  cout << "Nombre? ";
  getline(cin, nombre);

  tmp = archivo.buscar_por_nombre(nombre);

  if (not tmp.empty()) {
    cout << endl
        << endl
        << "Todos los registros" << endl
        << setw(34) << left << "Nombre" << setw(16) << "Cedula"
        << setw(8) << "Nota 1" << setw(8) << "Nota 2" << setw(8) << "Nota 3"
        << setw(8) << "Promedio" << endl;

    for(it = tmp.begin(); it != tmp.end(); it++)
      cout << *it << endl;
  }
  else
    cout << "Nombre no encontrado" << endl;
}
