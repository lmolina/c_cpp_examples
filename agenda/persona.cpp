#include <iostream>
#include <string>
using namespace std;

#include "persona.h"

Persona::Persona(string nom, string ape, long telef) {
  this->nombre_ = nom;
  this->apellido_ = ape;
  this->telefono_ = telef;
}

void Persona::nombre(const string &nombre_actual) {
  this->nombre_ = nombre_actual;
}

void Persona::apellido(const string &apellido_actual) {
  this->apellido_ = apellido_actual;
}

void Persona::telefono(const long &telefono_actual) {
  this->telefono_ = telefono_actual;
}

string Persona::nombre() const {
  return this->nombre_;
}
string Persona::apellido() const {
  return this->apellido_;
}

long Persona::telefono() const {
  return this->telefono_;
}

void Persona::mostrar() const {
  cout << this->apellido_ << ", " << this->nombre_ << ": " << this->telefono_;
}

Persona::~Persona() {
  /* vacio */
}
