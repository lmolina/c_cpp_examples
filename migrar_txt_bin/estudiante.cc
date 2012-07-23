#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <cstring>

#include "estudiante.h"

ostream & operator<<(ostream & out, const Estudiante & e) {
  out << left << setw(32) << e.nombre_ << right << setw(8) 
      << left << setw(32) << e.apellido_ << right << setw(8) 
      << left << setw(16) << e.nacionalidad_ << right << setw(8) 
      << left << setw(16) << e.cedula_ << right << setw(8) 
      << left << setw(10) << e.fecha_ingreso_ << right << setw(8) 
      << left << setw(16) << e.carrera_;
  return out;
}

Estudiante::Estudiante(string nom,
                       string ape,
                       string nac,
                       long cedula,
                       long f_ing,
                       string carr
                      ) {
  nombre(nom);
  apellido(ape);
  cedula_ = cedula;
  f_ing = fecha_ingreso_;
  carrera(carr);
}

string Estudiante::nombre() const {
  return string(nombre_);
}
void Estudiante::nombre(string nom) {
  int tam = nom.size() < 31 ? nom.size() : 31;
  strncpy(nombre_, nom.c_str(), tam);
  nombre_[tam] = '\0';
}

string Estudiante::apellido() const {
  return string(apellido_);
}
void Estudiante::apellido(string ape) {
  int tam = ape.size() < 31 ? ape.size() : 31;
  strncpy(apellido_, ape.c_str(), tam);
  apellido_[tam] = '\0';
}

string Estudiante::nacionalidad() const {
  return string(nacionalidad_);
}
void Estudiante::nacionalidad(string nac) {
  int tam = nac.size() < 31 ? nac.size() : 31;
  strncpy(nacionalidad_, nac.c_str(), tam);
  nacionalidad_[tam] = '\0';
}

long Estudiante::cedula() const {
  return cedula_;
}

void Estudiante::cedula(long n) {
  cedula_ = n >= 0 ? n : -1;
}

long Estudiante::fecha_ingreso() const {
  return fecha_ingreso_;
}

void Estudiante::fecha_ingreso(long n) {
  fecha_ingreso_ = n >= 0 ? n : -1;
}

string Estudiante::carrera() const {
  return string(carrera_);
}
void Estudiante::carrera(string carr) {
  int tam = carr.size() < 31 ? carr.size() : 31;
  strncpy(carrera_, carr.c_str(), tam);
  carrera_[tam] = '\0';
}

bool Estudiante::operator==(const Estudiante & e) {
  return nombre_ == e.nombre_;
}

bool Estudiante::operator==(const string & e) {
  return nombre_ == e;
}

bool Estudiante::operator<(const Estudiante & e) {
  return cedula_ < e.cedula_;
}
