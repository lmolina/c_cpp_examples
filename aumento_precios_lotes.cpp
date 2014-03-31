/*
 * ¿Cuánto aumentó?
 *
 * El precio de venta al público (P.V.P.) de algunos productos es fijado por
 * el Estado. Este precio es revisado y ajustado cada cierto tiempo.
 *
 * Este programa toma como entrada el nombre de un archivo que debe contener:
 * - El nombre del producto
 * - El P.V.P. antes del ajuste
 * - El P.V.P. luego del ajuste
 *
 * Luego, en función de los datos presentes en el archivo de entrada, cálcula
 * la variación absoluta y la variación porcentual por cada producto.
 
 * Suponga que el archivo de entrada contiene los siguientes datos:
 *
 * Azucar 7.5 10
 * Harina 6 9
 * Cafe 10 22.5
 *
 *
 * La salida del programa sería:
 *
 * Producto  P.V.P. inicial    P.V.P. final   Var. absoluta Var. porcentual
 * Azucar              7.50           10.00            2.50           33.33
 * Harina              6.00            9.00            3.00           50.00
 * Cafe               10.00           22.50           12.50          125.00
 *
 *
 * Realice los ajustes necesarios para para que, manteniendo la forma de la
 * entrada y la salida, el programa valide la entrada y emita un error en caso
 * de presentarse una entrada incorrecta.
 *
 * 2014-03-31
 * Laudin Alessandro Molina <laudin.molina@gmail.com>
 */

#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::fixed;

#include <cmath>
using std::abs;

#include <iomanip>
using std::setprecision;
using std::setw;
using std::left;
using std::right;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

int main(int argc, char *argv[]) {
    string producto = "";
    float pvp_inicial = 0;
    float pvp_final = 0;
    float variacion_absoluta = 0;
    float variacion_porcentual = 0;

    // Revisar que se tiene el número correcto de argumentos
    if (argc != 2) {
        cerr << "Debe indicar el archivo con los productos y precios" << endl;
        cerr << argv[0] << " <nombre_archivo>" << endl;
        return 1;
    }

    // Aperturar el archivo y chequear que se pudo abrir
    ifstream entrada(argv[1]);
    if (not entrada) {
        return 2;
    }



    /* 
     * Mostrar cabecera de la tabla resúmen con la información de los precios
     */
    cout << setw(16) << "Producto"
        << setw(16) << "P.V.P. inicial"
        << setw(16) << "P.V.P. final"
        << setw(16) << "Var. absoluta"
        << setw(16) << "Var. porcentual" << endl;

    /*
     * Leer desde el archivo el nombre del producto, el precio inicial y el
     * precio final
     */
    while (entrada >> producto >> pvp_inicial >> pvp_final) {

        if (pvp_inicial < 0) {
            cerr << "El P.V.P. inicial no puede ser negativo" << endl;
        }

        if (pvp_final < 0) {
            cerr << "El P.V.P. final no puede ser negativo" << endl;
        } 

        /* Cálculo de valor absoluto y porcentual */
        variacion_absoluta = abs(pvp_final - pvp_inicial);
        variacion_porcentual = variacion_absoluta / pvp_inicial * 100;

        cout << setw(16) << fixed << setprecision(2) << producto
            << setw(16) << fixed << setprecision(2) << pvp_inicial 
            << setw(16) << fixed << setprecision(2) << pvp_final
            << setw(16) << fixed << setprecision(2) << variacion_absoluta
            << setw(16) << fixed << setprecision(2) << variacion_porcentual
            << endl;
    }
    return 0;
}
