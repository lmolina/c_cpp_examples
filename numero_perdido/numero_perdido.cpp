/*
 * Titulo: Número Perdido
 * Descripcion: Intentar adivinar, en 10 intentos o menos, un número aleatorio
 *
 * Laudin Molina T <laudin@ula.ve>
 * 2012-11-07
 *
 */


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstdlib>
//prototipo de srand
//prototipo de rand

int main() {
  srand(time(0));
  int perdido = rand() % 99 + 1;
  bool encontrado=false;
  int intento = 0;
  int numero = 0;

  cout << "Encuentre el numero perdido" << endl
      << "Tiene 10 intentos" << endl;

  do {
    intento = intento + 1;

    cout << endl
        << "Intento "<< intento << endl
        << "Ingrese un numero: ";
    cin >> numero;

    if (numero < perdido) {
      cout << numero << " es menor que el numero perdido" << endl;
    }
    else {
      if (numero>perdido) {
        cout << numero << " es mayor que el numero perdido" << endl;
      }
      else {
        encontrado=true;
      }
    }
  } while (!encontrado && intento < 10);


  if (encontrado == true) {
    cout << endl
        << "Felicidades! Adivino en " << intento << " intentos" << endl;
  }
  else {
    cout << endl
        << "Lo sisnto, ha alcanzado el maximo de intentos fallidos" << endl
        << "El numero perdido era: " << perdido << endl;
  }

  return 0;
}
