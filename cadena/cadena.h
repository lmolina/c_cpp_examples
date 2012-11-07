#ifndef CADENA_H
#define CADENA_H

# include <iostream>
using std::ostream;
using std::istream;

class Cadena {
  friend ostream & operator<<(ostream & out, const Cadena & cad);
  friend istream & operator>>(istream & in, Cadena & cad);
 public:
  Cadena(size_t act_tam=0);
  Cadena(const char *);
  Cadena(const Cadena &);
  ~Cadena();
  long tam() const;
  Cadena extraer(size_t indice, size_t cantidad) const;
  void asignar(const Cadena & cad);
  int subcadena(const Cadena & cad) const;
  int subcadena(const Cadena & cad, int pos) const;
  void concatenar(const char & c);
  void concatenar(const Cadena & cad);
  void operator=(const Cadena & cad);
  void operator=(const char * cad);
  Cadena operator+(const Cadena & cad) const;
  Cadena operator+(const char * cad) const;
  bool operator==(const Cadena & cad) const;
  bool operator==(const char * cad) const;
  bool operator<(const Cadena & cad) const;
  bool operator<(const char * cad) const;
  void a_mayuscula();
  void a_minusculas();
  void a_titulo();
  void sustituir(const Cadena & a, const Cadena & b);
  void sustituir(const Cadena & a, const Cadena & b, const int & pos);

 private:
  void cambiar_tamanio(int nuevo_tam);

  char * ptr;
  size_t tam_arreglo;
  size_t tam_;
};
#endif
