#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "pila.h"

int main() {
  Pila< int > pila_enteros;

  if (pila_enteros.vacia())
    cout << "pila_enteros vacia" << endl;
  else
    cout << "pila_enteros no esta vacia" << endl;

  int entero = 0;
  while(not pila_enteros.llena()) {
    pila_enteros.apilar(entero);
    ++entero;
  }

  while(not pila_enteros.vacia()) {
    pila_enteros.desapilar(entero);
    cout << entero << endl;
  }

  Pila< double > pila_dobles;

  if (pila_dobles.vacia())
    cout << "pila_dobles vacia" << endl;
  else
    cout << "pila_dobles no esta vacia" << endl;

  double doble = 0.1;
  while(not pila_dobles.llena()) {
    pila_dobles.apilar(doble);
    doble += 0.1;
  }

  while(not pila_dobles.vacia()) {
    pila_dobles.desapilar(doble);
    cout << doble << endl;
  }

  return 0;
}
