#include <iostream>
using namespace std;

#include "complejo.h"

int main() {
  Complejo c1, c2, resultado;

  c1 = crea_complejo(1, 2);
  c2 = crea_complejo();
  resultado = crea_complejo();

  imprimir(c1);
  cout << endl;
  imprimir(c2);
  cout << endl;
  
  cout << "Introduzca la parte real e imaginaria de un numero complejo" << endl;
  leer(c1);
  cout << "Introduzca la parte real e imaginaria de un numero complejo" << endl;
  leer(c2);

  if(igual(c1, c2) == true) {
    imprimir(c1);
    cout << " igual a ";
    imprimir(c2);
    cout << endl;
  }
  else {
    imprimir(c1);
    cout << " distinto a ";
    imprimir(c2);
    cout << endl;
  }

  resultado = sumar(c1, c2);
  imprimir(resultado);
  cout << endl;

  resultado = multiplicar(c1, c2);
  imprimir(resultado);
  cout << endl;
  cout << endl;

  return 0;
}
