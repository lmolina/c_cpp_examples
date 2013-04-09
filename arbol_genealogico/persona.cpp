#include <string>
#include <iostream>
using namespace std;

#include "persona.h"

Persona::Persona() {
  nombre_ = "";
  sexo_ = ' ';
  padre_ = NULL;
  madre_ = NULL;
}

Persona::Persona(string n, char s, unsigned int fnac,
                 unsigned int fmuerte, Persona * p, Persona * m) {
  nombre(n);
  sexo(s);
  padre(p);
  madre(m);
}

Persona::Persona(string, char, unsigned int, unsigned int) {}

Persona::Persona(Persona * p, Persona * m) {
  if (p != this and m != this) {
    padre_ = p;
    madre_ = m;
  }
}

Persona::Persona(const Persona &) {}

string Persona::nombre() {
  return nombre_;
}

void Persona::nombre(const string & n) {
  nombre_ = n;
}

char Persona::sexo() {
  return sexo_;
}

void Persona::sexo(const char & s) {
  if (s == ' ' or s == 'm' or s == 'f')
    sexo_ = s;
}

Persona * Persona::padre() {
  return this->padre_;
}

void Persona::padre(Persona * p) {
  this->padre_ = p;
}

Persona * Persona::madre() {
  return this->madre_;
}

void Persona::madre(Persona * m) {
  this->madre_ = m;
}

// El padre de mi padre
Persona * Persona::abuelo_paterno() {
  if (this->padre_ != NULL)
    return this->padre()->padre();
}

Persona * Persona::abuelo_materno() {}

bool Persona::es_hermano_de(Persona * p) {
  if (this->padre() != NULL and p->padre() != NULL
      and p->padre() == this->padre())
    return true;
  else
    return false;
}

void Persona::mostrar() {
  cout << this->nombre() << " " << this->sexo();
}
