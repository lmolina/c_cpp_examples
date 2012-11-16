/*
 * Copyright 2012 Laudin Molina T <laudin@ula.ve>
 */

# include <iostream>
# include <string>
using namespace std;

# include "persona.h"
# include "agenda.h"

int main() {
  Persona ej1;
  Persona ej2("Laudin", "Molina", 555555);


  ej1.mostrar();
  cout << endl;

  ej1.nombre("Alessandro");
  ej1.apellido("Troconis");
  ej1.telefono(111222444);
  ej1.mostrar();
  cout << endl;

  ej2.mostrar();
  cout << endl;

  cout << endl;
  cout << "XXXXXXXX Agenda XXXXXXXXXX" << endl;
  cout << endl;
  Agenda agenda;
  agenda.mostrar();

  agenda.agregar_persona(ej1);
  agenda.agregar_persona(ej2);
  agenda.mostrar();

  cout << endl;
  cout << "Buscar" << endl;
  string nombre = "Laudin";
  vector< Persona >::iterator it;
  vector< Persona > r = agenda.buscar_nombre(nombre);
  for (it = r.begin(); it < r.end(); ++it) {
    it->mostrar();
    cout << endl;
  }

  agenda.agregar_persona(Persona("Laudin", "Troconis", 123));
  cout << endl;
  cout << "Buscar" << endl;
  nombre = "Laudin";
  r = agenda.buscar_nombre(nombre);
  for (it = r.begin(); it < r.end(); ++it) {
    it->mostrar();
    cout << endl;
  }
    
  cout << endl << endl;
  agenda.eliminar_persona(ej2);
  agenda.mostrar();

  return 0;
}
