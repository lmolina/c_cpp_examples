# include <iostream>
using namespace std;

# include <cstdlib>

unsigned short int dado();

int main() {
  unsigned short int opcion = 0;
  unsigned short int dado1 = 0;
  unsigned short int dado2 = 0;
  unsigned short int suma = 0;

  cout << "Jugar craps? (0 = salir, otro = jugar): ";
  cin >> opcion;
  while (opcion != 0)
  {
    dado1 = dado();
    dado2 = dado();
    suma = dado1 + dado2;

    cout << dado1 << "  +  "  << dado2 << " = " << suma << endl;
    if (suma == 7 or suma == 11)
      cout << "Felicidades! Gana el jugador" << endl;
    else
      cout << "La casa gana" << endl;

    cout << "Jugar otra vez? (0 = salir, otro = jugar): ";
    cin >> opcion;

    cout << endl;
  }

  return 0;
}

unsigned short int dado() {
  return rand() % 6 + 1;
}
