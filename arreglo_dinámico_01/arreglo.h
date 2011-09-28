/*
 * Implementacion de la clase Arreglo dinamico.
 * FIXME esta implementacion no es capaz de manejar datos invalidos
 *
 * Copyright 2011 Maria Jose Garcia Tami
 * Copyright 2011 Laudin Alessandro Molina T <laudin.molina@gmail.com>
 *
 */

// Incluir para evitar inclusion multiple de la libreria
#ifndef ARREGLO_H_
#define ARREGLO_H_

#include <iostream>
using std::cout;
using std::endl;

template <class T>
class Arreglo {
  public:
    explicit Arreglo(int tamanio = 0);
    ~Arreglo();
    void ImprimeArreglo();
    Arreglo<T> & Insertar(const T &dato, int pos);
    T Eliminar(int pos);
    T Regresar(int pos);
    int tam();
  private:
    bool CambiarTamanio(int nuevo_tamanio);
    int tam_;
    T *ptr_datos_;
};

template <class T>
bool Arreglo<T>::CambiarTamanio(int nuevo_tamanio) {
  // Caso 1
  if (tam_ == nuevo_tamanio)
    return true;
  // Caso 5
  else if (nuevo_tamanio == 0) {
    if (ptr_datos_ != NULL) {
      tam_ = 0;
      delete [] ptr_datos_;
      ptr_datos_ == NULL;
    }

    return true;
  } else if (nuevo_tamanio > 0) {
    T *tmp = new T[nuevo_tamanio];

    // Se pudo habiliar memoria?
    if (tmp != NULL) {

      // Si habian datos hay que copiarlos
      if (tam_ > 0) {

        // Caso 3
        if (nuevo_tamanio > tam_)
          for (int i = 0; i < tam_; ++i)
            tmp[i] = ptr_datos_[i];

        // Caso 2
        else
          for (int i = 0; i < nuevo_tamanio; ++i)
            tmp[i] = ptr_datos_[i];

        delete [] ptr_datos_;
      }

      ptr_datos_ = tmp;
      tam_ = nuevo_tamanio;

      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

template <class T>
Arreglo<T>::Arreglo(int tamanio) {
  tam_ = 0;
  ptr_datos_ = NULL;
  CambiarTamanio(tamanio);
}

template <class T>
Arreglo<T>::~Arreglo() {
  CambiarTamanio(0);
}

template <class T>
void Arreglo<T>::ImprimeArreglo() {
  for (int i = 0; i < tam_; i++)
    cout << ptr_datos_[i] << " ";
  cout << endl;
}

template <class T>
int Arreglo<T>::tam() {
  return tam_;
}

template <class T>
Arreglo<T> & Arreglo<T>::Insertar(const T &dato, int pos) {
  if (pos >= 0 && pos <= tam_) {
    CambiarTamanio(tam() + 1);

    for (int i = tam() - 1; i > pos; --i)
      ptr_datos_[i] = ptr_datos_[i - 1];

    ptr_datos_[pos] = dato;
  }

  return *this;
}

template <class T>
T Arreglo<T>::Regresar(int pos) {
  // Antes de acceder se debe verificar que la posicion solicitada es valida

  if (pos >= 0 and pos < tam()) {
    return ptr_datos_[pos];
  }  else {
    // Se debe retornar algo, no es lo mas apropiado, pero se retorna una
    // instancia recien creada
    T error;
    return error;
  }
}

template <class T>
T Arreglo<T>::Eliminar(int pos) {
  T elemento;

  if (pos >= 0 and pos < tam()) {
    elemento = ptr_datos_[pos];

    // Se corren corren los elementos para deja en la ultima posicion el
    // elemento a eliminar

    for (int i = pos; i < tam() - 1; i++)
      ptr_datos_[i] = ptr_datos_[i + 1];

    CambiarTamanio(tam() - 1);
  }
  return elemento;
}
#endif  // ARREGLO_H_
