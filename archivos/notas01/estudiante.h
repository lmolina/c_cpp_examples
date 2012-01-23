#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>
using namespace std;

class Estudiante {
  friend ostream & operator<<(ostream &, const Estudiante &);
  friend istream & operator>>(istream &, Estudiante &);
 public:
  Estudiante(string nom="", int n1=-1, int n2=-1, int n3=-1);
  string nombre() const;
  void nombre(string);
  int nota1() const;
  void nota1(int);
  int nota2() const;
  void nota2(int);
  int nota3() const;
  void nota3(int);
  float promedio() const;
  bool operator==(const Estudiante &);
  bool operator==(const string &);

 private:
  char nombre_[32];
  int nota1_;
  int nota2_;
  int nota3_;
};

#endif
