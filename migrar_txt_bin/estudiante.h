#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>
using namespace std;

class Estudiante {
  friend ostream & operator<<(ostream &, const Estudiante &);
 public:
  Estudiante(
      string nom="",
      string ape="",
      string nac="",
      long cedula=-1,
      long f_ing=-1,
      string carr=""
      );
  string nombre() const;
  void nombre(string);
  string apellido() const;
  void apellido(string);
  string nacionalidad() const;
  void nacionalidad(string);
  long cedula() const;
  void cedula(long);
  long fecha_ingreso() const;
  void fecha_ingreso(long);
  string carrera() const;
  void carrera(string);

  bool operator==(const Estudiante &);
  bool operator==(const string &);
  bool operator<(const Estudiante &);

 private:
  char nombre_[32];
  char apellido_[32];
  char nacionalidad_[32];
  long cedula_;
  long fecha_ingreso_;
  char carrera_[32];
};

#endif
