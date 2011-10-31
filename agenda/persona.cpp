#include <iostream>
#include <string>
using namespace std;

#include "persona.h"

Persona::Persona(string nombre, string cedula, long telefono,
                 long fecha_nacimiento) {
    this->nombre = nombre;
    this->cedula = cedula;
    this->telefono = telefono;
    this->fecha_nacimiento = fecha_nacimiento;
}

void Persona::set_nombre(string nombre_actual) {
  // this no es necesario, aunque se podria usar, porque los identificadores
  // estan claramente diferenciados
  nombre = nombre_actual;
}

void Persona::set_cedula(string cedula_actual) {
  cedula = cedula_actual;
}

void Persona::set_telefono(long telefono_actual) {
  if (telefono_actual >= 1000000)
    telefono = telefono_actual;
}
void Persona::set_fecha_nacimiento(long fecha) {
    if (fecha_valida(fecha))
    fecha_nacimiento = fecha;
}

void Persona::set_fecha_nacimiento(int dia, int mes, int anyo) {
  // Los parametros del objeto pueden ser de tipo diferente al parametro
  // recibido
  long fecha = anyo * 10000 + mes * 100 + dia;
  if (fecha_valida(fecha))
    fecha_nacimiento = fecha;
}

string Persona::get_nombre() {
  return this->nombre;
}
string Persona::get_cedula(){}
long Persona::get_telefono(){}
long Persona::get_fecha_nacimiento(){}
int Persona::edad(){}

void Persona::imprimir() const {
    cout << "Nombre: " << this->nombre << endl
        << "Telefono: " << this->telefono << endl
        << "Fecha de nacimiento: " << this->fecha_nacimiento << endl;
}

Persona::~Persona(){}

bool Persona::fecha_valida(long){}
