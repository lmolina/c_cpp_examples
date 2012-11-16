/*
 * Copyright 2012 Laudin Molina T <laudin@ula.ve>
 */

#ifndef AGENDA_AGENDA_H_
#define AGENDA_AGENDA_H_

#include <string>
using std::string;

#include <vector>
using std::vector;

# include "persona.h"

class Agenda {
  public:
    Agenda();
    vector<Persona> buscar_nombre(string & nombre);
    vector<Persona> buscar_apellido(string & apellido);
    Persona buscar_telefono(unsigned int telefono);
    void agregar_persona(const Persona & p);
    void eliminar_persona(const Persona & p);
    void mostrar();
    ~Agenda();
  private:
    vector<Persona> contenedor;
};

#endif  // AGENDA_AGENDA_H_
