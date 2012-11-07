# include <iostream>
//using std::cout;
//using std::cin;
//using std::endl;

# include <cstring>
// prototipo de strncpy

# include "cadena.h"

void Cadena::cambiar_tamanio(int nuevo_tam) {
  // Exception if act_tam <= 0 
  char * tmp = new char[nuevo_tam];

  int num_elementos = nuevo_tam < tam_? nuevo_tam : tam_;

  if (ptr != NULL) {
    if (tmp != NULL) {
      for (int i = 0; i < num_elementos; ++i) {
        tmp[i] = ptr[i];
      }
    }
    
    delete [] ptr;
  }

  ptr = tmp;
  tam_arreglo = nuevo_tam;
}

Cadena::Cadena(size_t act_tam) {
  tam_arreglo = act_tam > 0 ? act_tam : 32;
  ptr = new char[tam_arreglo];
  tam_ = 0;
  ptr[0] = '\0';
};

Cadena::Cadena(const char * cad) {
  if (cad == NULL) {
    // TODO
    // Throw an exception!!!!
    tam_arreglo = 32;
    ptr = new char[tam_arreglo];
    tam_ = 0;
    ptr[0] = '\0';

    return;
  }

  ptr = NULL;
  tam_ = strlen(cad);
  tam_arreglo = tam_ + 1;
  cambiar_tamanio(tam_arreglo);
  strncpy(ptr, cad, tam_);

  return;
}

Cadena::~Cadena() {
  tam_arreglo = tam_ = 0;
  if (ptr != NULL) {
    delete [] ptr; 
  }
}

long Cadena::tam() const {
  return tam_; 
}

Cadena Cadena::extraer(size_t indice, size_t cantidad) const {
  // Exception indice >= 0 and cantidad > 0

  Cadena subcadena(cantidad + 1);

  // Exception indice + cantidad must be less than tam_
  int i, j;
  for (i = 0, j = indice; i < cantidad; ++i, ++j)
    subcadena.ptr[i] = this->ptr[j];

  subcadena.ptr[i] = '\0';

  return subcadena;
} 

void Cadena::asignar(const Cadena & cad) {
  tam_ = cad.tam_;
  tam_arreglo= cad.tam_arreglo;

  this->cambiar_tamanio(tam_arreglo);

  strncpy(this->ptr, cad.ptr, tam_);
}

int Cadena::subcadena(const Cadena & cad) const {

}

void Cadena::concatenar(const char & c) {
  if (tam_ + 1 >= tam_arreglo) {
    tam_arreglo = tam_arreglo * 2;
    cambiar_tamanio(tam_arreglo);
  }

  ptr[tam_] = c;
  ptr[++tam_] = '\0';
}

void Cadena::concatenar(const Cadena & cad) {
  if (tam_ + cad.tam() >= tam_arreglo) {
    tam_arreglo = (tam_arreglo + cad.tam()) * 2;
    cambiar_tamanio(tam_arreglo);
  }

  for (int i = 0, j = tam_; i < cad.tam(); ++i, ++j) {
    ptr[j] = cad.ptr[i];
    ++tam_;
  }
  ptr[tam_] = '\0';
}

ostream & operator<<(ostream & out, const Cadena & cad) {
  out << cad.ptr;

  return out; 
}

istream & operator>>(istream & in, Cadena & cad) {
  
  cad.cambiar_tamanio(1);
  cad.ptr[0] = '\0';
  cad.tam_ = 0;

  char entrada;

  entrada = in.get();
  while(entrada != '\n') {
    cad.concatenar(entrada); 
    entrada = in.get();
  }

  return in;
}

Cadena::Cadena(const Cadena &) {}
  
int Cadena::subcadena(const Cadena & cad, int pos) const {}

void Cadena::operator=(const Cadena & cad){}

void Cadena::operator=(const char * cad){}

Cadena Cadena::operator+(const Cadena & cad) const {}

Cadena Cadena::operator+(const char * cad) const {}

bool Cadena::operator==(const Cadena & cad) const {}

bool Cadena::operator==(const char * cad) const {}

bool Cadena::operator<(const Cadena & cad) const {}

bool Cadena::operator<(const char * cad) const {}

void Cadena::a_mayuscula() {}

void Cadena::a_minusculas() {}

void Cadena::a_titulo() {}

void Cadena::sustituir(const Cadena & a, const Cadena & b) {}

void Cadena::sustituir(const Cadena & a, const Cadena & b, const int & pos) {}
