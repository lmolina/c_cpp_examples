/* 
 * Llenar una matriz de 5 filas y 10 columnasa con los pirmeros 50
 * números primos
 *
 * Laudin Molina <laudin@ula.ve>
 * 2012-07-26
 */

# include <iostream>
using std::cout;
using std::endl;

# include <iomanip>
using std::setw;

# include <cmath>
// Prototipo de sqrt

const int kUltimaFila = 5;
const int kUltimaColumna = 10;

int es_primo(int n);

int main() {
  int numero = 3;
  int numero_de_primos = 0;
  int fila = 0;
  int columna = 0;
  int matriz_de_primos[kUltimaFila][kUltimaColumna] = {0};

  while (numero_de_primos < 50) {
    if (es_primo(numero)) {
      matriz_de_primos[fila][columna] = numero;
      ++columna;

      if (columna == kUltimaColumna) {
        columna = 0;
        ++fila;
      }
    }

    ++numero;
  }

  for (int fila = 0; fila < kUltimaFila; ++fila) {

    for (int columna = 0; columna < kUltimaColumna; ++columna) {
      cout << setw(4) << matriz_de_primos[fila][columna] << " ";
    }

    cout << endl;
  }

  return 0;
}


int es_primo(int n) {

  if (n < 2)
    return false;

  if (n == 2)
    return true;

  // Ningún número par es primo
  if (n % 2 == 0)
    return false;

  // Solo son posibles divisores los menores o iguales que la raiz cuadrada del
  // número
  int raiz = sqrt(n);

  // Ya se descartaron los divisores pares, solo se revisan los posibles
  // divisores impares
  for (int divisor = 3; divisor <= raiz; divisor += 2)
    if (n % divisor == 0)
      return false;

  return true;
}
