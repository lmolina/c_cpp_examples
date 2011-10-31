#ifndef PERSONA_H
#define PERSONA_H

class Persona {
  public:
    Persona(string="NA", string="NA", long=-1, long=-1);
    void set_nombre(string);
    void set_cedula(string);
    void set_telefono(long);
    void set_fecha_nacimiento(long);
    void set_fecha_nacimiento(int, int, int);
    string get_nombre();
    string get_cedula();
    long get_telefono();
    long get_fecha_nacimiento();
    int edad();
    void imprimir() const;
    ~Persona();
  private:
    bool fecha_valida(long);
    string nombre;
    string cedula;
    long fecha_nacimiento;
    long telefono;
};

#endif
