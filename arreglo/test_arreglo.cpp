/*
 * Programa de pueba para la clase parametrica Arreglo<T>
 *
 * Copyright 2011 Maria Jose Garcia Tami
 * Copyright 2011 Laudin Alessandro Molina T <laudin.molina@gmail.com>
 *
 */

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <cstdlib>

#include "arreglo.h"

int main() {
  Arreglo<int> edades;

  srand(time(0));

  edades.Insertar(10, 0);

  cout << edades.tam() << endl;
  cout << edades.Regresar(0) << endl;

  for (int i = 0; i < 16; ++i)
    edades.Insertar(rand() % 90, i);

  for (int i = 0; i < edades.tam(); ++i)
    cout << edades.Regresar(i) << endl;

  return 0;
}
