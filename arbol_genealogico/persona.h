#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using std::string;

class Persona {
 public:
  Persona();
  Persona(string, char, unsigned int, unsigned int, Persona *, Persona *);
  Persona(string, char, unsigned int, unsigned int);
  Persona(Persona *, Persona *);
  Persona(const Persona &);
  string nombre();
  void nombre(const string &);
  char sexo();
  void sexo(const char &);

  Persona * padre();
  void padre(Persona *);
  Persona * madre();
  void madre(Persona *);
  Persona * abuelo_paterno();
  Persona * abuelo_materno();
  bool es_hermano_de(Persona *);
  void mostrar();

  //void mostrar_arbol_genealogico();

  // TODO:
  // fecha_nac
  // fecha_muerte
  // edad
  // madre

 private:
  string nombre_;
  char sexo_;
  //unsigned int fecha_nac_;
  //unsigned int fecha_muerte_;
  Persona * padre_;
  Persona * madre_;
};

#endif // PERSONA_H
