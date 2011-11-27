#include <iostream>
using namespace std;

#include "punto.h"
#include "circulo.h"

int main() {
  Punto p1(1, 2);
  Punto p2(10, 11);
  Punto p3;

  p1.imprimir();
  p2.imprimir();

  if(p1.igual(p2))
    cout << "p1 es igual a p2" << endl;
  else
    cout << "p1 es diferente de p2" << endl;

  if(p1 == p2)
    cout << "p1 es igual a p2" << endl;
  else
    cout << "p1 es diferente de p2" << endl;

  p1 = p2;

  if(p1 == p2)
    cout << "p1 es igual a p2" << endl;
  else
    cout << "p1 es diferente de p2" << endl;

  p3 = p1 + p2;
  p1.imprimir();
  p2.imprimir();
  p3.imprimir();

  p3++;
  p3.imprimir();

  ++p3;
  p3.imprimir();

  Circulo c(1, 2, 3);
  c.imprimir();
  cout << endl;
  cout << c.contador();
  cout << endl;

  {
      Circulo d(1, 2, 3);
      cout << d.contador();
      cout << endl;
      cout << c.contador();
      cout << endl;
  }
  cout << c.contador();
  cout << endl;
  return 0;
}
