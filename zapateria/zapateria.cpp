/*
============================
Zapatería *Los dos juanetes*
============================

Copyright 2011 Laudin Alessandro Molina <laudin.molina@gmail.com>

La zapatería *Los dos juanetes* maneja 5 modelos muy exclusivos.
Los modelos con sus respectivos precios son:

==========  ===========
Modelo      Precio (Bs)
==========  ===========
Alpargata   290
Zapatico    500
Chancleta   360
Hill        700
Big Hill    800
==========  ===========

Cada mañana, antes de abrir el local el gerente se asegura que hayan 20 unidades de
cada modelo.

Se le pide a que diseñe un programa que permita registrar las ventas
de los distintos modelos. Antes de salir del programa debe indicar:

* El monto total de las ventas;
* El número de artículos vendidos;
* El artículo más vendido.

 */

#include <iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;
using std::left;
using std::right;
using std::fixed;
using std::setprecision;

#include <cstring>

const int kTamCadena = 16;
const int kNumArticulos = 5;

enum Modelos {
    ALPARGATA = 0,
    ZAPATICO,
    CHANCLETA,
    HILL,
    BIGHILL
};

enum Opciones {
    CERRAR = 0,
    VENDER
};

struct Zapato {
    char modelo[kTamCadena];
    float precio;
    int stock;
};


void revisar_inventario(Zapato inventario[]);
int menu_ventas(Zapato inventario[], int num_articulos);
bool vender(Zapato zapatos[], int num_articulos, int modelo);
int mostrar_opciones();
void mostrar_resumen_ventas(Zapato inventario[], int num_articulos);

int main() {
    int seleccion;
    int articulo_vendido;
    Zapato zapatos[kNumArticulos];

    // El gerente revisa el inventario cada manian
    revisar_inventario(zapatos);

    do {
        // Se abre la caja y se muestran las opciones disponibles
        seleccion = mostrar_opciones();
        switch (seleccion) {
            case VENDER:
                articulo_vendido = menu_ventas(zapatos, kNumArticulos);

                // Si se pudo vender el articulo indicarlo??
                if (vender(zapatos, kNumArticulos, articulo_vendido) == true)
                    cout << "Excelente seleccion, que disfrute su calzado"
                        << endl;
                else
                    cout << "Disculpe, no hay disponibilidad de ese modelo"
                        << endl;
                break;
            case CERRAR:
                cout << "Preparando resumen ..." << endl;
                mostrar_resumen_ventas(zapatos, kNumArticulos);
                cout << endl;
                break;
            default:
                cerr << "Seleccion incorrecta!!" << endl;
                break;
        }
    } while (seleccion != CERRAR);
}


void revisar_inventario(Zapato inventario[]) {
    // Asegurar que haya 20 articulos de cada modelo
    strcpy(inventario[0].modelo, "Alpargata");
    inventario[0].precio = 290;
    inventario[0].stock = 20;
    strcpy(inventario[1].modelo, "Zapatico");
    inventario[1].precio = 500;
    inventario[1].stock = 20;
    strcpy(inventario[2].modelo, "Chancleta");
    inventario[2].precio = 360;
    inventario[2].stock = 20;
    strcpy(inventario[3].modelo, "Hill");
    inventario[3].precio = 700;
    inventario[3].stock = 20;
    strcpy(inventario[4].modelo, "BigHill");
    inventario[4].precio = 800;
    inventario[4].stock = 20;
}

int menu_ventas(Zapato inventario[], int num_articulos) {
    int seleccion;
    int i;

    do {
        cout << endl
            << "Articulos disponibles" << endl;
        for (i = 0; i < num_articulos; ++i)
            cout << setw(3) << i << ": " << inventario[i].modelo << endl;

        cout << endl << "Su seleccion ? ";
        cin >> seleccion;
    } while (seleccion < 0 or seleccion >= num_articulos);

    return seleccion;
}

bool vender(Zapato zapatos[], int num_articulos, int modelo) {
    bool vendido = false;
    if (modelo >= 0 and modelo <= num_articulos) {
        if (zapatos[modelo].stock > 0) {

            // Vender un zapato implica descontar 1 al stock del modelo
            // vendido
            --(zapatos[modelo].stock);
            vendido = true;
        }
    }

    return vendido;
}

int mostrar_opciones() {
    int seleccion;

    cout << endl
        << "Zapateria *Los dos juanetes*" << endl
        << setw(3) << VENDER << ": Vender" << endl
        << setw(3) << CERRAR << ": Cerrar caja" << endl
        << endl
        << "Su seleccion? ";
    cin >> seleccion;

    return seleccion;
}

void mostrar_resumen_ventas(Zapato inventario[], int num_articulos) {
    int i = 0;
    int articulos_vendidos = 0;
    int total_articulos_vendidos = 0;
    int articulo_mas_vendido = 0;
    float total_ventas = 0;

    for (i = 0; i < num_articulos; ++i) {
        // El numero total de articulos vendidos es la cantidad inicial (20)
        // menos el numero de articulos en el inventario
        total_articulos_vendidos += 20 - inventario[i].stock;

        // Las ventas de un articulo es el numero de articulos vendidos por el
        // precio. El total de ventas es la suma de las ventas de cada
        // articulo
        total_ventas += (20 - inventario[i].stock) * inventario[i].precio;

        if (20 - inventario[i].stock > articulos_vendidos) {
            articulos_vendidos = 20 - inventario[i].stock;
            articulo_mas_vendido = i;
        }
    }

    cout << endl
        << "Resumen de ventas" << endl;
    cout << setw(28) << left << "Monto total de las ventas"
        << setw(16) << right << fixed << setprecision(2) << total_ventas
        << " Bs." << endl;
    cout << setw(32) << left << "Numero de articulos vendidos"
        << setw(16) << right << total_articulos_vendidos << endl;
    cout << setw(32) << left << "Articulo mas vendido"
        << setw(16) << right << inventario[articulo_mas_vendido].modelo << endl;
    cout << endl;
}
