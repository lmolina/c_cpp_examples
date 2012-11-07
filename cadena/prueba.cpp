# include <iostream>
using namespace std;

# include "cadena.h"

int main() {
  Cadena cad1;
  Cadena cad2("Hola");
  Cadena cad3(" Ingenieros");

  cout << cad2 << endl;
  cout << cad2.tam() << endl;
  cout << cad2.extraer(1, 2) << endl;

  cad1.asignar(cad2);
  cout << cad1 << endl;
  cout << cad1.extraer(0, 3) << endl;

  cad2.concatenar(cad3);
  cout << cad2 << endl;

  cin >> cad3;
  cad2.concatenar(cad3);
  cout << cad2 << endl;

  return 0;
}
