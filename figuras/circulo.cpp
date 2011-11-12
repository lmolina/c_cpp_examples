#include<iostream>
using std::cout;
using std::endl;

#include"circulo.h"

int Circulo::contador_ = 0;

Circulo::Circulo(int xValor, int yValor, double radioValor) : Punto(xValor, yValor) {
		radio_ = radioValor;
		++contador_;
}

Circulo::~Circulo() {
	--contador_;
}
void Circulo::radio(double radioValor) {
	radio_ = radioValor;
}

void Circulo::imprimir() const {
	cout << "(" << x() << ", " << y() << "), r: " << radio() << endl;
}

double Circulo::radio() const {
	return radio_;
}

double Circulo::area() const {
	return (kPi * radio_ * radio_ / 2);
}

double Circulo::perimetro() const {
	return (2 * kPi * radio_);
}

int Circulo::contador() const {
	return contador_;
}
