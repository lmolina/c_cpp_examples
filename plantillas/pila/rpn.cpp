/* 
 * Programa que toma una expresion en Notacion Polaca Inversa y retorna el
 * resultado.
 *
 * El programa asume que solo se van a introducir numeros y los operadores
 * validos + - x / (note que la multiplicacion se realiza con x)
 *
 * Laudin Alessandro Molina <laudin.molina@gmail.com>
 * 2011-01-16
 *
 */

#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

#include <string>
using std::string;

using namespace std;

#include <cstdlib>
#include <cstring>

#include "pila.h"

// Numero maximo de operandos que puede tener la expresion
const int kMaxOperandos = 100;

// Tamanio maximo de la operacion (en caracteres)
const int kTamMax = 255;

const string operadores = "+-*/";

int main(int argv, char ** argc)
{
  char * token;
  float op1 = 0, op2 = 0, resultado = 0;
  int i = 0;
  Pila< float > operandos(kMaxOperandos);

  if ( argv < 1)
  {
    cerr << "Operacion incorrecta" << endl;
    exit(1);
  }

  for(i = 1; i < argv; ++i)
  {
    token = argc[i];

    if (strcmp(token, "+") == 0 or strcmp(token, "-") == 0 or
        strcmp(token, "x") == 0 or strcmp(token, "/") == 0)
    {
      if (operandos.tam() >= 2)
      {
        operandos.desapilar(op1);
        operandos.desapilar(op2);
        if (strcmp(token, "+") == 0)
        {
          resultado = op2 + op1;
        }
        else if (strcmp(token, "-") == 0)
        {
          resultado = op2 - op1;
        }
        else if (strcmp(token, "x") == 0)
        {
          resultado = op2 * op1;
        }
        else if (strcmp(token, "/") == 0)
        {
          if (op1 == 0)
          {
            cerr << "Division por cero no permitida" << endl;
          }
          else
          {
            resultado = op2 / op1;
          }
        }
        else
        {
          cerr << "Operacion no implementada" << endl;
          exit(3);
        }
        operandos.apilar(resultado);
      }
      else
      {
        cerr << "Operacion incorrecta" << endl;
        exit(4);
      }
    }
    else
    {
      resultado = atof(token);
      operandos.apilar(resultado);
    }
  }

  operandos.desapilar(resultado);
  cout << resultado << endl;

  return 0;
}
