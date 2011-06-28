/*
 * Almacena el seno, coseno y tangente para distintos valores de grado en una
 * matriz, para luego imprimirla.
 *
 * Copyright 2011 Laudin Alessandro Molina <laudin.molina@gmail.com>
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setw;
using std::left;
using std::right;
using std::setprecision;

#include <cmath>
// Prototipos de sin, cos y tan

const float kPi = 3.1459;
const int kAngulos = 6;

int main() {
    double trigonometrica[kAngulos][4];
    double angulo = 0;
    int i = 0;
    int j = 0;

    // El 1er indice de un arreglo es 0, por lo que el ultimo indice es
    // tamanio - 1
    for(i = 0; i <= kAngulos - 1; ++i) {

        // Va ajustando el valor del angulo: pi/4, 2*pi/4, 3*pi/4, ...
        angulo += kPi / 4.0;

        // Columna 0 el angulo
        trigonometrica[i][0] = angulo;

        // Columna 1 el seno del angulo
        trigonometrica[i][1] = sin(angulo);

        // Columna 2 el cos del angulo
        trigonometrica[i][2] = cos(angulo);
    }

    // Imprime una cabecera para la matriz
    cout << left << setw(14) << "Ang (rad)"
        << setw(14) << " Seno"
        << setw(14) << " Coseno" << endl;

    // Imprime el contenido de la matriz con un formato adecuado
    for(i = 0; i <= kAngulos -1; ++i) {
        for(j = 0; j <= 3 - 1; ++j) {
            cout << fixed << right << setprecision(6);
            cout << setw(14) << trigonometrica[i][j];
        }
        cout << endl;
    }

    return 0;
}
