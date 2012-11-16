#ifndef AGENDA_PERSONA_H_
#define AGENDA_PERSONA_H_

#include <string>
using std::string;

class Persona {
  public:
    Persona(string nombre= "-1", string apellido= "-1", long telefono= -1);
    void nombre(const string &);
    string nombre() const;
    void apellido(const string &);
    string apellido() const;
    void telefono(const long &);
    long telefono() const;
    // void fecha_nacimiento(long);
    // void fecha_nacimiento(int, int, int);
    // long fecha_nacimiento() const;
    // int edad() const;
    void mostrar() const;
    ~Persona();
  private:
    // bool fecha_valida(long) const;
    // long fecha_nacimieno_;
    string nombre_;
    string apellido_;
    long telefono_;
};

#endif  // AGENDA_PERSONA_H_
