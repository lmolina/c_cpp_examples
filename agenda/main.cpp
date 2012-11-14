# include <iostream>
using std::cout;
using std::cin;
using std::endl;

# include "persona.h"
# include "agenda.h"
//# include "corregir.h"

enum Opciones {mostrar = 0, agregar, eliminar, buscar_nombre, buscar_apellido,
    buscar_telefono, salir};

int menu(Agenda & agenda);
void buscar_nombre(Agenda & agenda);
void buscar_apellido(Agenda & agenda);
void buscar_telefono(Agenda & agenda);
void mostrar_agenda(Agenda & agenda);
void agregar_entrada(Agenda & agenda);

int main() {
    Agenda agenda;

    cargar_agenda(agenda);
    menu(agenda);
    //int nota = corregir(agenda);
    //cout << nota << endl;

    return 0;
}


int menu(Agenda & agenda) {
    int opc;
    do {
        cout << "****************" << endl
            << "Agenda" << endl
            << "Buscar nombre" << nombre << endl
            << "Buscar apellido" << apellido << endl
            << "Buscar telefono" << telefono << endl
            << "Mostrar agenda" << mostrar << endl
            << "Agregar entrada" << agregar << endl
            << endl
            << "Salir" << salir << endl;
        cin >> opc;

        switch(opc) {
            case nombre:
                buscar_nombre(agenda);
                break;
            case apellido
                buscar_apellido(agenda);
                break;
            case telefono:
                buscar_telefono(agenda);
                break;
            case mostrar:
                mostrar_agenda(agenda);
                break;
            case agregar:
                agregar_entrada(agenda);
                break;
            case salir:
                cout << "Ciao!" << endl;
                break;
            default:
                cerr << "Opcion no valida" << endl;
        }
    } while (opc != salir);
}

void buscar_nombre(Agenda & agenda) {
    string nombre;

    cout << "Nombre? ";
    cin >> nombre;
    vector< Persona > r = agenda.buscar_nombre(nombre);
    vector< Persona >::iterator it;

    for(it = r.begin(); it < r.end(); ++it) {
        it->mostrar();
        cout << endl;
    }
}

void buscar_apellido(Agenda & agenda) {
    string apellido;

    cout << "Apellido? ";
    cin >> apellido;
    vector< Persona > r = agenda.buscar_apellido(apellido);
    vector< Persona >::iterator it;

    for(it = r.begin(); it < r.end(); ++it) {
        it->mostrar();
        cout << endl;
    }
}

void buscar_telefono(Agenda & agenda) {
    long telefono;
    cout << "Telefono? ";
    cin >> telefono;

    Persona r = agenda.buscar_telefono(telefono);
    if (r.telefono() > 0)
        r.mostrar();
    else
        cout << "Registro no encontrado" << endl;
    cout << endl;
}

void mostrar_agenda(Agenda & agenda) {
    agenda.mostrar();
}

void agregar_entrada(Agenda & agenda) {
    string nombre;
    string apellido;
    long telefono;

    cout << "Ingresar datos:" << endl;
    cout << "Nombre? ";
    cin >> nombre;
    cout << "Apellido? ";
    cin >> apellido;
    cout << "Telefono? ";
    cin >> telefono;

    agenda.agregar_persona(Persona(nombre, apellido, telefono));
}
 
