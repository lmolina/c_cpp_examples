#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <cstring>

#include "estudiante.h"

ostream & operator<<(ostream & out, const Estudiante & e) {
  out << left << setw(16) << e.nombre_ << right << setw(8) 
      << fixed << setprecision(2) << e.nota1_ << setw(8) 
      << e.nota2_ << setw(8) << e.nota3_
      << setw(10) << e.promedio();
  return out;
}

istream & operator>>(istream & in, Estudiante & e) {
  in >> e.nombre_ >> e.nota1_ >> e.nota2_ >> e.nota3_;
  return in;
}

Estudiante::Estudiante(string nom, int n1, int n2, int n3) {
  nombre(nom);
  nota1_ = n1;
  nota2_ = n2;
  nota3_ = n3;
}

string Estudiante::nombre() const {
  return string(nombre_);
}
void Estudiante::nombre(string nom) {
  int tam = nom.size() < 31 ? nom.size() : 31;
  strncpy(nombre_, nom.c_str(), tam);
  nombre_[31] = '\0';
}

int Estudiante::nota1() const {
  return nota1_;
}

void Estudiante::nota1(int n) {
  nota1_ = n >= 0 ? n : -1; 
}

int Estudiante::nota2() const {
  return nota2_;
}

void Estudiante::nota2(int n) {
  nota2_ = n >= 0 ? n : -1; 
}

int Estudiante::nota3() const {
  return nota3_;
}

void Estudiante::nota3(int n) {
  nota3_ = n >= 0 ? n : -1;
}

float Estudiante::promedio() const {
  return float(nota1() + nota2() + nota3()) / 3.0;
}

bool Estudiante::operator==(const Estudiante & e) {
  return nombre_ == e.nombre_;
}

bool Estudiante::operator==(const string & e) {
  return nombre_ == e;
}
