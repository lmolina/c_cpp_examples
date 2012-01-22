#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ios;
using std::left;
using std::right;
using std::showpoint;
using std::noshowpoint;
using std::fixed;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <iomanip>
using std::setw;
using std::setprecision;

#include <cstdlib>
// prototipo de exit

int main() {
    ifstream archivo_notas("notas.dat", ios::in);

    if( !archivo_notas ) {
        cerr << "No se pudo abrir el archivo";
        exit(1);
    }

    float nota1, nota2, nota3, codigo, promedio;
    int num = 0;
    char sep;
    string nombre;

    cout << left << setw(4) << "Cod" << left << setw(16) << "Nombre" << right
        << setw(8) << "Nota 1" << setw(8) << "Nota 2" << setw(8) << "Nota 3"
        << setw(10) << "Promedio" << endl;

    while(archivo_notas >> codigo >> nombre >> nota1 >> nota2 >> nota3) {
        promedio = (nota1 + nota2 + nota3) / 3;
        cout << left << setw(4) << codigo << setw(16) << nombre 
            << right << setw(8) << fixed << setprecision(2) << nota1 << setw(8)
            << nota2 << setw(8) << nota3 << setw(10) << promedio << endl;
        ++num;
    }

    cout << endl << "Total notas procesadas: " << num << endl;

    return 0;
}
