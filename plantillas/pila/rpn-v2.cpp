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
  char buffer[kTamMax], * token;
  char espacio;
  float op1, op2, resultado;
  Pila< float > operandos(kMaxOperandos);

  cin.getline(buffer, 200);

  token = strtok(buffer, " ");

  while (token != NULL)
  {
    if (strcmp(token, "+") == 0 or strcmp(token, "-") == 0 or
        strcmp(token, "*") == 0 or strcmp(token, "/") == 0)
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
        else if (strcmp(token, "*") == 0)
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

    token = strtok(NULL, " ");
  }

  operandos.desapilar(resultado);
  cout << resultado << endl;

  return 0;
}
