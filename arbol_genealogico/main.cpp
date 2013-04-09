#include <iostream>
using namespace std;

#include "persona.h"

int main() {

  Persona p1;

  p1.mostrar();
  cout << endl;

  p1.nombre("Adan");
  p1.sexo('m');
  p1.padre(NULL);
  p1.madre(NULL);

  p1.mostrar();
  cout << endl;

  Persona p2("Eva", 'f', 0, 0, NULL, NULL);
  p2.mostrar();
  cout << endl;

  Persona p3("Cain", 'm', 0, 0, &p1, &p2);
  p3.mostrar();
  cout << endl;

  cout << "Padres de p3:" << endl;
  cout << endl;
  p3.padre()->mostrar();
  cout << endl;
  p3.madre()->mostrar();
  cout << endl;
  
  //cout << "Padres de p1:" << endl;
  //p1.madre()->mostrar();
  return 0;
}
