# include <iostream>
# include <vector>
using namespace std;


# include "agenda.h"


Agenda::Agenda() {
  /*vacio*/
}

vector<Persona> Agenda::buscar_nombre(string &nombre) {
  vector <Persona> r;
  vector<Persona>::iterator tmp;

  for (tmp = contenedor.begin(); tmp < contenedor.end(); ++tmp)
    if (tmp->nombre() == nombre) {
      r.push_back(*tmp);
    }

  return r;
}

vector <Persona> Agenda::buscar_apellido(string &apellido) {}
/*
vector <Persona> Agenda::buscar_apellido(string & apellido){
  vector <Persona> r;
  Persona tmp;
  for(//falta)
  if(tmp.apellido()==apellido){
    r.append(tmp);
    }
  return r;

  }
*/

Persona Agenda::buscar_telefono(long telefono) {

  vector<Persona>::iterator it;

  for (it = contenedor.begin(); it < contenedor.end(); ++it)
    if (it->telefono() == telefono)
      return *it;

  Persona r;
  r.telefono(-1);
  return r;
}

void Agenda::agregar_persona(const Persona &p) {
  Persona tmp = buscar_telefono(p.telefono());

  if (tmp.telefono() > 0)
    cerr << "Error! Numero telefonico ya esta registrado" << endl;
  else
    contenedor.push_back(p);
}

void Agenda::eliminar_persona(Persona &p) {
  vector<Persona>::iterator it;

  for (it = contenedor.begin(); it < contenedor.end(); ++it)
    if (it->telefono() == p.telefono()) {
      it->telefono(-1);
      it->nombre("-1");
      it->apellido("-1");
    }
}

void Agenda::mostrar() {

  vector<Persona>::iterator it;

  for (it = contenedor.begin(); it < contenedor.end(); ++it)
    if (it->telefono() > 0) {
      it->mostrar();
      cout << endl;
    }
}

Agenda::~Agenda() {
  /*vacio*/
}
