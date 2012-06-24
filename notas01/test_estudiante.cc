# include <iostream>
# include <string>

using namespace std;

# include <cstring>

# include "estudiante.h"

int main() {
  string nombre = "Laudin";
  long cedula = 12123123;
  int n1 = 1;
  int n2 = 2;
  int n3 = 3;

  char nombre_[32];
  string nom = "";
  int tam = nom.size() < 32 ? nom.size() : 31 ;
  strncpy(nombre_, nombre.c_str(), tam);
  //cout << t << endl;

  Estudiante e1;
  Estudiante e2(nombre, cedula, n1, n2, n3);
  cout << e1 << endl;
  cout << e2 << endl;

  e1 = e2;
  cout << e1 << endl;

  return 0;
}
