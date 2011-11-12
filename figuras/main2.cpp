#include <iostream>
using namespace std;

#include "circulo.h"

int main() {
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
