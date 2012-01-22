#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ios;

#include <fstream>
using std::ofstream;

#include <string>
using std::string;

#include <cstdlib>
// prototipo de exit

int main() {
    ofstream archivo_notas("notas.dat", ios::app);

    if( !archivo_notas ) {
        cerr << "No se pudo abrir el archivo";
        exit(1);
    }

    int nota1, nota2, nota3, codigo = 0;
    string nombre;

    cout << "Ingrese los datos en el siguiente orden: nombre, nota1, nota2, " 
        << "nota3" << endl << "Escriba fin de archivo para terminar la entrada"
        << endl << "? ";

    while(cin >> nombre >> nota1 >> nota2 >> nota3) {
        archivo_notas << codigo++ << ' ' << nombre << ' ' << nota1 << ' ' 
            << nota2 << ' ' << nota3 << endl;
        cout << "? ";
    }

    cout << endl;

    return 0;
}
