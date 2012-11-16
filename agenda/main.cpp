#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

#include <fstream>
using std::fstream;
using std::ios;

#include <iomanip>
using std::setw;
using std::left;

#include "persona.h"
#include "agenda.h"
//#include "corregir.h"

enum Opciones {nombre = 0, apellido, telefono, mostrar, agregar, salir};

int menu(Agenda & agenda);
void buscar_nombre(Agenda & agenda);
void buscar_apellido(Agenda & agenda);
void buscar_telefono(Agenda & agenda);
void mostrar_agenda(Agenda & agenda);
void agregar_entrada(Agenda & agenda);
void cargar_agenda(Agenda & agenda, fstream & entrada);

int main(int argc, char* argv[]) {
  Agenda agenda;

  if (argc > 1) {
    fstream entrada(argv[1], ios::in);
    cargar_agenda(agenda, entrada);
  }
  menu(agenda);
  //int nota = corregir(agenda);
  //cout << nota << endl;

  return 0;
}

int menu(Agenda & agenda) {
  int opc;
  do {
    cout << "Agenda" << endl
        << endl << left
        << setw(20) << "Buscar nombre" << nombre << endl
        << setw(20) << "Buscar apellido" << apellido << endl
        << setw(20) << "Buscar telefono" << telefono << endl
        << setw(20) << "Mostrar agenda" << mostrar << endl
        << setw(20) << "Agregar entrada" << agregar << endl
        << endl
        << setw(20) << "Salir" << salir << endl
        << endl
        << "? ";
    cin >> opc;

    switch (opc) {
      case nombre:
        buscar_nombre(agenda);
        break;
      case apellido:
        buscar_apellido(agenda);
        break;
      case telefono:
        buscar_telefono(agenda);
        break;
      case mostrar:
        mostrar_agenda(agenda);
        break;
      case agregar:
        agregar_entrada(agenda);
        break;
      case salir:
        cout << "Ciao!" << endl;
        break;
      default:
        cerr << "Opcion no valida" << endl;
    }
  } while (opc != salir);
}

void buscar_nombre(Agenda & agenda) {
  string nombre;


  cout << endl
      << "Buscar por nombre" << endl
      << "? ";
  cin >> nombre;

  vector< Persona > r = agenda.buscar_nombre(nombre);
  vector< Persona >::iterator it;

  int total_encontrados = r.size();

  if (total_encontrados > 0) {
    cout << "Se encontraron " << total_encontrados << " coincidencias" << endl; 

    for(it = r.begin(); it < r.end(); ++it) {
      it->mostrar();
      cout << endl;
    }
  }

  else {
    cout << "No se encontraron concidencias:" << endl;
  }
  cout << endl << endl;
}

void buscar_apellido(Agenda & agenda) {
  string apellido;

  cout << endl
      << "Buscar por apellido" << endl
      << "? ";
  cin >> apellido;
  vector< Persona > r = agenda.buscar_apellido(apellido);
  vector< Persona >::iterator it;
  int total_encontrados = r.size();

  if (total_encontrados > 0) {
    cout << "Se encontraron " << total_encontrados << " coincidencias" << endl; 

    for(it = r.begin(); it < r.end(); ++it) {
      it->mostrar();
      cout << endl;
    }
  }
  else {
    cout << "No se encontraron concidencias:" << endl;
  }
  cout << endl << endl;

}

void buscar_telefono(Agenda & agenda) {
  long telefono;

  cout << endl
      << "Buscar telefono" << endl
      << "? ";
  cin >> telefono;

  Persona r = agenda.buscar_telefono(telefono);
  if (r.telefono() > 0)
    r.mostrar();
  else
    cout << "Telefono no encontrado" << endl;
  cout << endl;
}

void mostrar_agenda(Agenda & agenda) {
  agenda.mostrar();
}

void agregar_entrada(Agenda & agenda) {
  string nombre;
  string apellido;
  long telefono;

  cout << "Ingresar datos:" << endl;
  cout << "Nombre? ";
  cin >> nombre;
  cout << "Apellido? ";
  cin >> apellido;
  cout << "Telefono? ";
  cin >> telefono;

  agenda.agregar_persona(Persona(nombre, apellido, telefono));
}

void cargar_agenda(Agenda & agenda, fstream & entrada) {
  string nombre;
  string apellido;
  long telefono;

  if (!entrada) {
    cerr << "Error al abrir el archivo de entrada" << endl;
    return;
  }

  entrada >> nombre >> apellido >> telefono;
  while (!entrada.eof()) {
    agenda.agregar_persona(Persona(nombre, apellido, telefono));     
    entrada >> nombre >> apellido >> telefono;
  }
}
