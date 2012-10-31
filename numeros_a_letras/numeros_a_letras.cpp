# include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

# include <string>
using std::string;

int main() {
  int numero, unidades, decenas;
  string letras;

  cout << "Introduzca el numero en el rango (-40, 40): ";
  cin >> numero;

  // Validar que el numero este en el rango valido, si no lo esta se debe pedir
  // el numero nuevamente
  while ((numero < -40) or (numero > 40)) {
    cerr << "Numero fuera del rango" << endl;
    cout << "Introduzca el numero en el rango (-40, 40): ";
    cin >> numero;
  }

  // Si el numero es negativo incluir la palabra "menos" y convertir en
  // positivo, asi los positivos y negativos pueden ser tratados de la misma
  // manera
  if (numero < 0) {
    letras = "menos ";
    numero = numero * -1;
  } else {
    letras = "";
  }

  // Casos especiales
  switch (numero) {
    case 0:
      letras = "cero";
      break; 
    case 10:
      letras = letras + "diez";
      break;
    case 11:
      letras = letras + "once";
      break;
    case 12:
      letras += "doce";
      break;
    case 13:
      letras += "trece";
      break;
    case 14:
      letras += "catorce";
      break;
    case 15:
      letras += "quince";
      break;
    case 16:
      letras += "dieciseis";
      break;
    case 17:
      letras += "diecisiete";
      break;
    case 18:
      letras += "dieciocho";
      break;
    case 19:
      letras += "diecinueve";
      break;
    case 20:
      letras += "veinte";
      break;

    default:
      unidades = numero % 10;
      decenas = numero / 10;

      switch (decenas) {
        case 2:
          letras += "veinti";
          break;
        case 3:
          letras += "treinta";
          break;
      }

      if (unidades != 0 and decenas != 0 and decenas != 2) {
        letras += " y "; 
      }

      switch (unidades) {
        case 1:
          letras += "uno";
          break;
        case 2:
          letras += "dos";
          break;
        case 3:
          letras += "tres";
          break;
        case 4:
          letras += "cuatro";
          break;
        case 5:
          letras += "cinco";
          break;
        case 6:
          letras += "seis";
          break;
        case 7:
          letras += "siete";
          break;
        case 8:
          letras += "ocho";
          break;
        case 9:
          letras += "nueve";
          break;
      }
  }

  cout << letras << endl;
  return 0;
}
