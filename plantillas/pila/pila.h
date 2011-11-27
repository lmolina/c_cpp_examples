#ifndef PILA_H
#define PILA_H

template< class T >
class Pila {
  public:
   Pila(int = 0);
   ~Pila();
   bool apilar(const T&);
   bool desapilar(T&);
   bool vacia() const;
   bool llena() const;
  private:
   int tam;
   int tope;
   T * ptr;
};

template< class T >
Pila< T >::Pila(int tam) {
  // Por defecto se crea una pila de tamanio 10
  this->tam = tam > 0 ? : 10;

  // Pila vacia, tope es el elemento -1
  tope = -1;

  // Habilitar memoria para un arreglo de tamanio this->tam de elementos
  // de tipo T 
  ptr = new T[ this->tam ];
}

template< class T >
Pila< T >::~Pila() {
  delete[] ptr;
}

template< class T >
bool Pila< T >::apilar(const T & valor) {
  if (not llena()) {
    ++tope;

    // El tipo de dato T debe implementar el operador =
    ptr[tope] = valor;

    return true;
  }
  else
    return false;
}

template< class T >
bool Pila< T >::desapilar(T & valor) {
  if (not vacia()) {
    valor = ptr[tope];

    // Actualizar valor del tope
    --tope;

    return true;
  }
  else
    return false;
}

template< class T >
bool Pila< T >::vacia() const {
  return tope == -1;
}

template< class T >
bool Pila< T >::llena() const {
  return tope == tam - 1;
}

#endif // PILA_H
