#ifndef CIRCUL03_H
#define CIRCULO3_H

#include <iostream>
using std::ostream;

#include "punto.h"

class Circulo : public Punto {
	public:
		Circulo(int=0, int=0, double=0);
		~Circulo();
		void imprimir() const;
		double radio() const;
		void radio(double);
		double area() const;
		double perimetro() const;
		int contador() const;
	private:
		double radio_;
		static int contador_;
		static const double kPi = 3.14159;
};

#endif
