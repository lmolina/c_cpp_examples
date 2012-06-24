#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>
using namespace std;

class Estudiante {
  friend ostream & operator<<(ostream &, const Estudiante &);
  friend istream & operator>>(istream &, Estudiante &);
 public:
  Estudiante(string="", long=-1, int=-1, int=-1, int=-1);
  Estudiante(const Estudiante &);
  string nombre() const;
  void nombre(const string &);
  long cedula() const;
  void cedula(const long &);
  int nota1() const;
  void nota1(const int &);
  int nota2() const;
  void nota2(const int &);
  int nota3() const;
  void nota3(const int &);
  float promedio() const;
  bool operator==(const Estudiante &);
  bool operator==(const string &);
  void operator=(const Estudiante &);

 private:
  char nombre_[32];
  long cedula_;
  int nota1_;
  int nota2_;
  int nota3_;
};

#endif
