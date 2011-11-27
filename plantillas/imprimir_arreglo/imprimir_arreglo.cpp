#include <iostream>
using std::cout;
using std::endl;

void imprimir_arreglo_enteros(const int arreglo[], const int tam);
void imprimir_arreglo_flotantes(const float arreglo[], const int tam);

template<class T>
void imprimir_arreglo(T arreglo[], int tam);

int main() {
  int arreglo1[10];
  float arreglo2[12];
  double arreglo3[15];
  
  for(int i = 0; i < 10; ++i) 
    arreglo1[i] = i;

  for(int i = 0; i < 12; ++i)
    arreglo2[i] = i;

  for(int i = 0; i < 15; ++i)
    arreglo3[i] = i;

  imprimir_arreglo_enteros(arreglo1, 10);
  imprimir_arreglo_flotantes(arreglo2, 12);

  imprimir_arreglo(arreglo1, 10);
  imprimir_arreglo(arreglo2, 12);
  imprimir_arreglo(arreglo3, 15);
  return 0;
}

void imprimir_arreglo_enteros(const int arreglo[], const int tam) {
  for(int i = 0; i < tam; ++i)
    cout << arreglo[i] << ' ';
  cout << endl;
}

void imprimir_arreglo_flotantes(const float arreglo[], const int tam) {
  for(int i = 0; i < tam; ++i)
    cout << arreglo[i] << ' ';
  cout << endl;
}

template<class T>
void imprimir_arreglo(T arreglo[], int tam) {
  for(int i = 0; i < tam; ++i)
    cout << arreglo[i] << ' ';
  cout << endl;
}

