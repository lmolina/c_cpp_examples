#include <iostream>
using namespace std;

struct Complejo {
  double real;
  double imag;
};

Complejo crea_complejo(double real = 0, double imag = 0) {
  Complejo z;

  z.real = real;
  z.imag = imag;

  return z;
}

Complejo sumar(Complejo a, Complejo b) {
  Complejo z;

  z.real = a.real + b.real;
  z.imag = a.imag + b.imag;

  return z;
}

Complejo multiplicar(Complejo a, Complejo b) {
  Complejo z;

  z.real = a.real * b.real - a.imag * b.imag;
  z.imag = a.real * b.imag + a.real * b.real;
}

bool igual(Complejo a, Complejo b) {
  return a.real == b.real and a.imag == b.imag;
}

double real(Complejo a) {
  return a.real;
}

double imaginaria(Complejo a) {
  return a.imag;
}

void elimina_complejo(Complejo a) {
  /* vacio */
}

void imprimir(Complejo a) {
  cout << real(a);
  if (imaginaria(a) < 0)
    cout << imaginaria(a) << "i";
  else
    cout << "+" << imaginaria(a) << "i";
}

void leer(Complejo & a) {
  cin >> a.real;
  cin >> a.imag;
}
