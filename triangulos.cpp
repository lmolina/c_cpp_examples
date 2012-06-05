#include <iostream>
using namespace std;

int menu();
void triangulo_izq(int h, char c = '*');
void triangulo_der(int h, char c = '*');
void triangulo_izq_inv(int h, char c = '*');
void triangulo_der_inv(int h, char c = '*');

int main (){
  int opc = -1;
  int altura = 0;

  do {
    opc = menu();

    switch (opc) {
      case 1:
        cout << "Altura? ";
        cin >> altura;
        cout << endl;
        triangulo_izq(altura);
        break;
      case 2:
        cout << "Altura? ";
        cin >> altura;
        cout << endl;
        triangulo_der(altura);
        break;
      case 3:
        cout << "Altura? ";
        cin >> altura;
        cout << endl;
        triangulo_izq_inv(altura);
        break;
      case 4:
        cout << "Altura? ";
        cin >> altura;
        cout << endl;
        triangulo_der_inv(altura);
        break;
      case 0:
        cout << "Ciao!!!" << endl;
        break;
    }

  } while (opc != 0);
  return 0;
}

int menu() {
  bool error = false;
  int opc = -1;

  do {
    cout << endl 
        << "********************************************************" << endl
        << "******************  Dibujar figura  ********************" << endl
        << endl
        << "1) Triangulo a la izquierda" << endl
        << "2) Triangulo a la derecha" << endl
        << "3) Triangulo a la izquierda invertido" << endl
        << "4) Triangulo a la derecha invertido" << endl
        << endl
        << "0) Salir" << endl
        << endl
        << "Seleccion? ";

    cin >> opc;

    if (opc != 1 and opc != 2 and opc != 3 and opc != 4 and opc != 0) {
      error = true;

      cout << endl << "Debe indicar una opcion valida!" << endl;
    }
  } while (error);

  cout << endl;

  return opc;
}

void triangulo_izq(int h, char c){

  int i;
  int j;
  for (i = 1; i <= h; i++){
    for (j = 1; j <= i; j++){
      cout << c;
    }
    cout << endl;
  }
}

void triangulo_der(int h, char c){

  int i;
  int j;
  for (i = 1; i <= h; i++){
    for (j = 1; j <= h - i; j++){
      cout << " ";
    }
    for (j = 1; j <= i; j++){
      cout << c;
    }
    cout << endl;
  }
}

void triangulo_izq_inv(int h, char c){

  int i;
  int j;
  for (i = h; i >= 1; i--){
    for (j = 1; j <= i; j++){
      cout << c;
    }
    cout << endl;
  }
}

void triangulo_der_inv(int h, char c){

  int i;
  int j;
  for (i = h; i >= 1; i--){
    for (j = 1; j <= h - i; j++){
      cout << " ";
    }
    for (j = 1; j <= i; j++){
      cout << c;
    }
    cout << endl;
  }
}
