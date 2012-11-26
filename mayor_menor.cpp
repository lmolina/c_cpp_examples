#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int mayor(int n1, int n2);
int menor(int n1, int n2);
int mayor(int n1, int n2, int n3);
int menor(int n1, int n2, int n3);

int main() {
  int a;
  int b;
  int c;

  cout << "Introduzca dos numeros enteros ";
  cin >> a >> b;
  cout << "El mayor de los numeros introducidos es " << mayor(a, b) << endl;

  /*
  cout << " el menor es " << menor(a, b) << endl;

  cout << "Introduzca tres numeros enteros ";
  cin >> a >> b >> c;
  cout << "El mayor de los numeros introducidos es " << mayor(a, b, c)
      << " y el menor es " << menor(a, b, c) << endl;
  */

  return 0;
}

int mayor(int n1, int n2) {
  int tmp = n1;

  if (n2 > tmp)
    tmp = n2;

  return tmp;
}

int menor(int n1, int n2) {
}

int mayor(int n1, int n2, int n3) {
}

int menor(int n1, int n2, int n3) {
}


