#include <iostream>
using std::cerr;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

#include "fecha.h"

Fecha::Fecha(int mi_dia, int mi_mes, int mi_anyo) {
  if (fecha_valida(mi_dia, mi_mes, mi_anyo)) {
    dia_ = mi_dia;
    mes_ = mi_mes;
    anyo_ = mi_anyo;
  }
  else {
    dia_ = 0;
    mes_ = 0;
    anyo_ = 0;
  }
}

Fecha::Fecha(const Fecha & mi_fecha) {
  *this = mi_fecha;
}

Fecha::~Fecha() { /* vacio */ }

int Fecha::dia() {
  return dia_;
}

void Fecha::dia(int mi_dia){

  // El dia indicado como parametro (mi_dia) mantiene la fecha valida?
  if(fecha_valida(mi_dia, this->mes_, this->anyo_))
    dia_ = mi_dia;
}

int Fecha::mes() {
  return mes_;
}

void Fecha::mes(int mi_mes){

  // El mes indicado como parametro (mi_dia) mantiene la fecha valida?
  if(fecha_valida(this->dia_, mi_mes, this->anyo_))
    mes_ = mi_mes;
}

int Fecha::anyo() {
  return anyo_;
}

void Fecha::anyo(int mi_anyo){
    anyo_ = mi_anyo;
}

bool Fecha::fecha_valida() {
  return fecha_valida(dia_, mes_, anyo_);
}

bool Fecha::operator==(const Fecha & otra_fecha) const{
  return dia_ == otra_fecha.dia_ and mes_ == otra_fecha.mes_ and
      anyo_ == otra_fecha.anyo_;
}

void Fecha::operator=(const Fecha & otra_fecha) {
  dia_ = otra_fecha.dia_;
  mes_ = otra_fecha.mes_;
  anyo_ = otra_fecha.anyo_;
}

bool Fecha::fecha_valida(int mi_dia, int mi_mes, int mi_anyo) {
  if (mi_mes < 1 or mi_mes > 31 or mi_dia < 1 or mi_dia > 31)
    return false;

  switch (mi_mes) {

    // Meses de 30 dias
    case 4:
    case 6:
    case 9:
    case 11:
      if (mi_dia > 30)
        return false;
      break;

      // Meses de 31 dias
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      if (mi_dia > 31)
        return false;

      // Febrero, bisiesto?
      // Bisiesto, febrero -> 29 dias
      if (mi_anyo % 400 == 0 or (mi_anyo % 4 == 0 and mi_anyo % 100 != 0)) {
        if (mi_dia > 29)
          return false;
      }
      // No bisiesto, febrero -> 28 dias
      else
        if (mi_dia > 28)
          return false;
  }

  return true;
}

ostream & operator<<(ostream & salida, const Fecha & fecha) {
  salida << fecha.dia_ << "/" << fecha.mes_ << "/" << fecha.anyo_;
}

istream & operator>>(istream & entrada, Fecha & fecha) {
  cerr << "Intruduzca la fecha de la forma: dd mm aaaa" << endl;
  entrada >> fecha.dia_ >> fecha.mes_ >> fecha.anyo_;
}
