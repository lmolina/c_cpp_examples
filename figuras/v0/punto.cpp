#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cmath>
#include "punto.h"

Punto::Punto(int xValor, int yValor) {
	x_ = xValor;
	y_ = yValor;
}

Punto::~Punto(){}

int Punto::x() const {
	return x_;
}

int Punto::y() const {
	return y_;
}

void Punto::x(int x) {
	this->x_ = x;
}

void Punto::y(int y) {
	this->y_ = y;
}

void Punto::imprimir() const {
	cout << "(" << x() << ", " << y() << ")" << endl;
}

bool Punto::igual(const Punto & der) const {
   return this->x() == der.x() and this->y() == der.y(); 
}

// El operando de la derecha es pasado como parametro del metodo
// El operando de la izquierda es el puntero this (el objeto mismo)
bool Punto::operator==(const Punto & der) const {
   return this->x() == der.x() and this->y() == der.y(); 
}


void Punto::operator=(const Punto & der){
    this->x(der.x());
    this->y(der.y());
}

Punto Punto::suma(const Punto & der) const {
    int mi_x;
    int mi_y;

    mi_x = this->x() + der.x();
    mi_y = this->y() + der.y();

    return Punto(mi_x, mi_y);
}

Punto Punto::operator+(const Punto & der) const {
    int mi_x;
    int mi_y;

    mi_x = this->x() + der.x();
    mi_y = this->y() + der.y();

    return Punto(mi_x, mi_y);
}

Punto &Punto::operator++() {
    this->x(x() + 1); 
    this->y(y() + 1); 

    return *this;
}

Punto Punto::operator++(int) {
    Punto temp = *this;

    this->x(x() + 1); 
    this->y(y() + 1); 

    return temp;
}


