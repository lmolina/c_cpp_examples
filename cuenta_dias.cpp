/*
 *
 */

#include <iostream>
using namespace std;

bool es_anyo_bisiesto(int anyo, int mes, int dia);
bool es_fecha_valida(int anyo, int mes, int dia);
int dias_desde_inicio_de_anyo(int anyo, int mes, int dia);

int main() {
    int dia, mes, anyo;

    cout << "Introduzca una fecha separada en dia, mes y anyo: " << endl;
    cout << "dia? ";
    cin >> dia;
    cout << "mes? ";
    cin >> mes;
    cout << "anyo? ";
    cin >> anyo;

    if (es_fecha_valida(anyo, mes, dia)) {
      cout << "Dias transcurridos desde el 1/1/" << anyo
          << " hasta el " << dia << "/" << mes << "/" << anyo << ": "
          << dias_desde_inicio_de_anyo(anyo, mes, dia) << endl;
    }
    else {
      cerr << "Fecha invalida" << endl;
    }
    
    return 0;
}

bool es_anyo_bisiesto(int anyo) {
}


bool es_fecha_valida(int anyo, int mes, int dia) {
}

int dias_desde_inicio_de_anyo(int anyo, int mes, int dia) {
  int enero, febrero, marzo, abril, mayo, junio, julio, agosto, septiembre,
      octubre, noviembre, diciembre; 

  // Dias que tiene cada mes
  enero = 31;

  // Febrero es especial, puede tener 28 o 29 dias
  if (es_anyo_bisiesto(anyo)) 
    febrero = 29;
  else
    febrero = 28;

  marzo = 31;
  abril = 30;
  mayo = 31;
  junio = 30;
  julio = 31;
  agosto = 31;
  septiembre = 30;
  octubre = 31;
  noviembre = 30;
  diciembre = 31;

  int dias_transcurridos = 0;
  switch (mes) {
    case 1: 
      dias_transcurridos = dia;
      break;
    case 2: 
      dias_transcurridos = enero + dia;
      break;
    case 3: 
      dias_transcurridos = enero + febrero + dia;
      break;
    case 4:
      dias_transcurridos = enero + febrero + marzo + dia;
      break;
    case 5: 
      dias_transcurridos = enero + febrero + marzo + abril + dia;
      break;
    case 6:
      dias_transcurridos = enero + febrero + marzo + abril + mayo + dia;
      break;
    case 7:
      dias_transcurridos = enero + febrero + marzo + abril + mayo + junio + dia;
      break;
    case 8:
      dias_transcurridos = enero + febrero + marzo + abril + mayo + junio + julio + dia;
      break;
    case 9:
      dias_transcurridos = enero + febrero + marzo + abril + mayo + junio + julio + agosto + dia;
      break;
    case 10:
      dias_transcurridos = enero + febrero + marzo + abril + mayo + junio + julio + agosto + septiembre + dia;
      break;
    case 11:
      dias_transcurridos = enero + febrero + marzo + abril + mayo + junio + julio + agosto + septiembre + octubre + dia;
      break;
    case 12:
      dias_transcurridos = enero + febrero + marzo + abril + mayo + junio + julio + agosto + septiembre + octubre + noviembre + dia;
      break;
  }

  return dias_transcurridos - 1;
}
