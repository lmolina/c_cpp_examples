/*
 * Programa que indica si una carta, dados un número y un palo, es una carta
 * valida en un juego de con cartas de poquer.
 *
 * Laudin Alessandro Molina T <laudin@ula.ve> - 2011-09-27
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstring>

struct Carta {
  int numero;
  char palo[9]; // trebol, diamante, pica, corazon
};

bool valida_carta(const Carta & mi_carta);
Carta leer_carta(Carta & buffer);

int main() {
  Carta una_carta; 

  cout << "Introduzca una carta (primero el numero y luego el palo en " 
      << "minusculas y singular): " << endl;
  leer_carta(una_carta);
  if(valida_carta(una_carta) == true) {
    cout << "Carta valida!" << endl;
  }
  else {
    cout << "Esa carta es mas falsa que un billete de 3" << endl;
  }

  cout << endl;

  return 0;
}

bool valida_carta(const Carta & mi_carta) {
  bool numero_valido = false;
  bool palo_valido = false;

  // Primero se valida el numero unicamente
  if(mi_carta.numero >= 1 and mi_carta.numero <= 13)
    numero_valido = true;

  // ... luego se valida el palo unicamente
  if(strcmp(mi_carta.palo, "trebol") == 0 or
     strcmp(mi_carta.palo, "diamante") == 0 or
     strcmp(mi_carta.palo, "pica") == 0 or
     strcmp(mi_carta.palo, "corazon") == 0)
    palo_valido = true;

  // ... la carta es valida si el numero y el palo son validos
  return numero_valido and palo_valido;
}

Carta leer_carta(Carta & buffer) {
  cin >> buffer.numero;
  cin >> buffer.palo;

  return buffer;
}
