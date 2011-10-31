#include<iostream>
using namespace std;

#include<cstring>

struct persona {
	char nombre[32];
	int edad;
	char sexo;
};


void leer(persona * p);
void imprimir(persona *p);

int main() {
	int y = 10, b = 2, n[14], *ptr;

	ptr = &y;           // ptr apunta ahora a la variable y
	cout << "Valor de y: " << y << endl;
	cout << "Dirección de y: " << &y << endl;
	cout << "Valor de ptr: " << ptr << endl;
	cout << "Dirección de ptr: " << &ptr << endl;
	cout << "Desreferencia de ptr: " << *ptr << endl;
	b = *ptr;     // b contiene ahora el valor de 10
	*ptr = 0;     // y es asignada con un valor de cero a través del apuntador ptr
	ptr = &n[2];  // apunta ahora a n[2]
	ptr = ptr + 2;// incrementa en dos lo apuntado por ptr
	n[5] = 5;
	++(*ptr);     // incrementa en uno lo apuntado por ptr
	(*ptr)++;     // incrementa en uno los puntado por ptr. Los paréntesis son
                // necesarios para que no incremente a p. 

	/*
	 * Registros y punteros
	 */

	persona *estudiante;
	estudiante = new persona;

	// Los datos de la persona pueden ser leidos de la siguiente manera
	strcpy((*estudiante).nombre, "Laudin");
	estudiante->sexo = 'm';
	estudiante->edad = 20;
	
	// Y si necesito leer mas de una persona?
	// Idea: crear una funcion :)
	leer(estudiante);
	imprimir(estudiante);
	
	return(0);
}

void leer(persona * p) 
{
	char sexo;
	cin.getline(p->nombre, 80);
	cin >> p->sexo;
	cin >> p->edad;
}

void imprimir(persona *p)
{
	cout << "Nombre: " << p->nombre << endl
		<< "Sexo: " << p->sexo << endl
		<< "Edad: " << p->edad << endl;
}
