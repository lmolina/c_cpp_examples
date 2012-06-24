#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <cstring>

#include "estudiante.h"

ostream & operator<<(ostream & out, const Estudiante & e) {
  out << left << setw(34) << e.nombre_ << setw(14) << e.cedula_ << right <<
      setw(8) << fixed << setprecision(2) << e.nota1_ << setw(8) << e.nota2_ <<
      setw(8) << e.nota3_ << setw(10) << e.promedio();
  
  return out;
}

istream & operator>>(istream & in, Estudiante & e) {
  in >> e.nombre_ >> e.cedula_ >> e.nota1_ >> e.nota2_ >> e.nota3_;

  return in;
}

Estudiante::Estudiante(string nom, long ci, int n1, int n2, int n3) {
  nombre(nom);
  cedula(ci);
  nota1_ = n1;
  nota2_ = n2;
  nota3_ = n3;
}

Estudiante::Estudiante(const Estudiante & e) {
  nombre(e.nombre());
  cedula_ = e.cedula_;
  nota1_ = e.nota1_;
  nota2_ = e.nota2_;
  nota3_ = e.nota3_;
}

string Estudiante::nombre() const {
  return string(nombre_);
}
void Estudiante::nombre(const string & nom) {
  int tam = nom.size() < 32 ? nom.size() : 31 ;

  if (tam > 0)
    strncpy(nombre_, nom.c_str(), tam);

  nombre_[tam] = '\0';
}

long Estudiante::cedula() const {
  return cedula_;
}

void Estudiante::cedula(const long & ci) {
  cedula_ = ci;
}

int Estudiante::nota1() const {
  return nota1_;
}

void Estudiante::nota1(const int & n) {
  nota1_ = n >= 0 ? n : -1; 
}

int Estudiante::nota2() const {
  return nota2_;
}

void Estudiante::nota2(const int & n) {
  nota2_ = n >= 0 ? n : -1; 
}

int Estudiante::nota3() const {
  return nota3_;
}

void Estudiante::nota3(const int & n) {
  nota3_ = n >= 0 ? n : -1;
}

float Estudiante::promedio() const {
  return float(nota1() + nota2() + nota3()) / 3.0;
}

bool Estudiante::operator==(const Estudiante & e) {
  return this->nombre() == e.nombre();
}

bool Estudiante::operator==(const string & e) {
  return this->nombre() == e;
}

void Estudiante::operator=(const Estudiante & e) {
  nombre(e.nombre());
  this->cedula_ = e.cedula_;
  this->nota1_ = e.nota1_;
  this->nota2_ = e.nota2_;
  this->nota3_ = e.nota3_;
}
