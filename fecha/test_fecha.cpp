#include <iostream>
using namespace std;

#include "fecha.h"

int main() {
  Fecha a;
  Fecha b(20, 1, 2011);

  cout << a << endl;
  cout << b << endl;
  
  if(a == b)
    cout << a << " == " << b << endl;
  else
    cout << a << " != " << b << endl;

  cin >> a;

  if(a == b)
    cout << a << " == " << b << endl;
  else
    cout << a << " != " << b << endl;

  if(a.fecha_valida())
    cout << a << "  valida" << endl;
  else
    cout << a << "  invalida" << endl;

  cout << endl;

  return 0;
}
