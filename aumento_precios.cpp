/*
 * ¿Cuánto aumentó?
 *
 * El precio de venta al público (P.V.P.) de algunos productos es fijado por
 * el Estado. Este precio es revisado cada cierto tiempo para ser ajustado.
 * Escriba un programa que tome como entrada el precio de venta de un producto
 * dado antes y después de la revisión, calcula la variación absoluta y la
 * variación porcentual.
 *
 * Toma el siguiente ejemplo hipotético:
 * Suponga que el P.V.P. para kilo de azúcar antes de ser revisado era de 10
 * Bs y luego de la revisión es de 11 Bs.
 *
 * Variación absoluta: 1 Bs
 * Variación porcentual: 10%
 *
 * Laudin Alessandro Molina <laudin.molina@gmail.com>
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::fixed;

#include <cmath>
using std::abs;

#include <iomanip>
using std::setprecision;

int main() {
    float pvp_inicial = 0;
    float pvp_final = 0;
    float variacion_absoluta = 0;
    float variacion_porcentual = 0;

    cout << "P.V.P. en bolivares antes de la revision? ";
    cin >> pvp_inicial;

    cout << "P.V.P. en bolivares luego de la revision? ";
    cin >> pvp_final;

    if (pvp_inicial < 0) {
        cout << "El P.V.P. inicial no puede ser negativo" << endl;
        return 1;
    }

    if (pvp_final < 0) {
        cout << "El P.V.P. final no puede ser negativo" << endl;
        return 1;
    } 

    variacion_absoluta = abs(pvp_final - pvp_inicial);

    if (pvp_final > 0) {
        variacion_porcentual = variacion_absoluta / pvp_inicial * 100;
    }
    else {
        variacion_porcentual = 100;
    }

    cout << endl << endl;
    cout << "P.V.P. inicial: " << fixed << setprecision(2)
        << pvp_inicial << " Bs." << endl;

    cout << "P.V.P. final: " << fixed << setprecision(2)
        << pvp_final << " Bs." << endl;

    cout << "Variacion absoluta: "  << fixed << setprecision(2)
        << variacion_absoluta << " Bs." << endl;

    cout << "Variacion porcentual: " << fixed << setprecision(2)
        << variacion_porcentual << "%" << endl;

    return 0;
}
