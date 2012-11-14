#ifndef PERSONA_H
#define PERSONA_H

class Persona {
  public:
    Persona(string = "-1", string = "-1", long = -1);
    void nombre(const string &);
    string nombre() const;
    void apellido(const string &);
    string apellido() const;
    void telefono(const long &);
    long telefono() const;
    // void fecha_nacimiento(long);
    // void fecha_nacimiento(int, int, int);
    //long fecha_nacimiento() const;
    //int edad() const;
    void mostrar() const;
    ~Persona();
  private:
    //bool fecha_valida(long) const;
    string nombre_;
    string apellido_;
    long telefono_;
};

#endif
