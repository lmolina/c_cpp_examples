#ifndef ANUARIO_SRC_FECHA_
#define ANUARIO_SRC_FECHA_

class Fecha {
  friend ostream & operator<<(ostream &, const Fecha &);
  friend istream & operator>>(istream &, Fecha &);
 public:
  // Interfaz (metodos publicos)

  // Constructor parametrico y por defecto (gracias al uso de parametros por
  // defecto)
  Fecha(int mi_dia=0, int mi_mes=0, int mi_anyo=0);

  // Constructor por copia
  Fecha(const Fecha & fecha);

  // Destructor
  ~Fecha();

  // Metodos de acceso a atributos
  int dia();
  void dia(int mi_dia);
  int mes();
  void mes(int mi_mes);
  int anyo();
  void anyo(int mi_anyo);
  bool fecha_valida();
  bool operator==(const Fecha &) const;
  void operator=(const Fecha &);

 private:
  // Metodos privados
  bool fecha_valida(int mi_dia, int mi_mes, int mi_anyo);

  // Atributos
  int dia_;
  int mes_;
  int anyo_;
};

#endif // ANUARIO_SRC_FECHA_
