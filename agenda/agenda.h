# ifndef AGENDA_H
# define AGENDA_H

# include <vector>
using namespace std;

# include "persona.h"

class Agenda {
  public:
    Agenda();
    vector<Persona> buscar_nombre(string &);
    vector<Persona> buscar_apellido(string &);
    Persona buscar_telefono(long telefono);
    void agregar_persona(const Persona &);
    void eliminar_persona(Persona &);
    void mostrar();
    ~Agenda();
  private:
    vector<Persona> contenedor;
};

# endif
