#include <iostream>
#include <fstream>
using namespace std;

#include "estudiante.h"

int main() {
  Estudiante e;

  fstream entrada("salida.txt", ios::in);

  while(entrada >> e) {
    cout << e << endl;
  }

  cout << endl;

  return 0;
}
