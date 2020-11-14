#ifndef INC_2_PARCIAL_PILA_H
#define INC_2_PARCIAL_PILA_H

#include "iostream"
#include "Nodo.h"
/**
 * Clase que implementa una Pila generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T> class Pila {
private:
  Node<T> *topNode;
public:
  Pila();

  ~Pila();

  void push(T dato);

  T pop();

  bool esVacia();

  T peek();

  bool insertAfter2(T, int, T );
};

/**
 * Constructor de la clase Pila
 * @tparam T
 */
template <class T> Pila<T>::Pila() {
  topNode = nullptr;
}

/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los
 * nodos utilizados en la lista
 * @tparam T
 */
template <class T> Pila<T>::~Pila() {
  while(!esVacia()){
    pop();
  }
}

/**
 * Inserta un dato en la pila
 * @tparam T
 * @param dato  dato a insertar
 */
template <class T> void Pila<T>::push(T dato) {
  Node<T> *newNode = new Node<T>;
  newNode->setDato(dato);
  newNode->setSiguiente(topNode);
  topNode = newNode;
}

/**
 * Obtener el dato de la pila
 * @tparam T
 * @return dato almacenado en el nodo
 */
template <class T> T Pila<T>::pop() {
  T data;
  Node<T> *toErase = topNode;
  if(esVacia()) throw 404;

  data = topNode->getDato();
  topNode = topNode->getSiguiente();
  delete toErase;
  return data;
}

/**
 * Responde si la pila se encuentra Vacía
 * @tparam T
 * @return
 */
template <class T> bool Pila<T>::esVacia() {
  if(topNode == nullptr) return true;
  return false;
}

template <class T> T Pila<T>::peek() {
  return topNode->getDato();
}

template <class T>
bool Pila<T>::insertAfter2(T oldValue, int n, T newValue) {
  int ocurrences = 0;
  Node<T> *auxNode = topNode;

  while(auxNode != nullptr && ocurrences <n){
    if(auxNode->getDato() == oldValue){
      ocurrences++;
    }
    if(ocurrences < n){
      auxNode = auxNode->getSiguiente();
    }
  }

  if(ocurrences == n){
    Node<T> *newNode = new Node<T>;
    newNode->setDato(newValue);
    newNode->setSiguiente(auxNode->getSiguiente());
    auxNode->setSiguiente(newNode);
    return 1;
  }
  return 0;
}

#endif // INC_2_PARCIAL_PILA_H
