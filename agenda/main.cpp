#include <iostream>
#include <string>
using namespace std;

#include "persona.h"

int main() {
  Persona ej1;
  Persona ej2("Laudin", "V0123123", 555555, 20111031);


  ej1.imprimir();
  ej1.set_nombre("Alessandro");
  ej1.set_cedula("V0123123");
  ej1.set_fecha_nacimiento(20111030);
  ej1.imprimir();

  ej2.imprimir();

  return 0;
}
