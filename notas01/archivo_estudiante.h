# ifndef ARCHIVOESTUDIANTE_H
# define ARCHIVOESTUDIANTE_H

# include <fstream>
using std::fstream;

# include <list>
using std::list;

# include <string>
using std::string;

# include "estudiante.h"

class ArchivoEstudiante {

 public:
  ArchivoEstudiante(const string &, const char = '#');
  ArchivoEstudiante(const ArchivoEstudiante &);
  ~ArchivoEstudiante();
  void open(const string = "");
  void close();
  bool agregar(const Estudiante &) ;
  bool leer(Estudiante &);
  Estudiante eliminar(const long &);
  Estudiante modificar(const Estudiante &, const long &);
  Estudiante buscar_por_cedula(const long &);
  list<Estudiante> buscar_por_nombre(const string &);
  list<Estudiante> buscar_por_promedio(const float &);

  template< class Compare >
  list<Estudiante> buscar(const int &, const Compare & cmp);

  template< class Compare >
  list<Estudiante> & buscar(const string &, const Compare & cmp);

  void particion_por_nota(const string &, const float &);

  template< class Compare >
  void particion(const string &, const Compare & cmp);

  void mezclar(const string &);
  long cantidad_registros();
  string nombre() const;
  bool abierto() const;
  void mostrar();

 private:
  char delimitador;
  string nombre_;
  bool abierto_;
  fstream archivo;
};

# endif
