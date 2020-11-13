#ifndef U02_LISTAS_LISTA_LISTA_H_
#define U02_LISTAS_LISTA_LISTA_H_

/**
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */

#include "Nodo.h"
#include "iostream"
template <class T> class Lista {
private:
  Node<T> *inicio;
public:
  void print();

  Lista();

  Lista(const Lista<T> &li);

  ~Lista();

  bool esVacia();

  int getTamanio();

  void insertar(int pos, T dato);

  void insertarPrimero(T dato);

  void insertarUltimo(T dato);

  void remover(int pos);

  T getDato(int pos);

  void reemplazar(int pos, T dato);

  void vaciar();

  int insertAfter2(T oldValue, int n, T newValue);
};

/**
 * Constructor de la clase Lista
 * @tparam T
 */
template <class T> Lista<T>::Lista() {
  this->inicio = nullptr;
}

/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 */
template <class T> Lista<T>::Lista(const Lista<T> &li) {
  this->inicio = li.inicio;
}

/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los
 * nodos utilizados en la lista
 * @tparam T
 */
template <class T> Lista<T>::~Lista() {
  vaciar();
}

/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */
template <class T> bool Lista<T>::esVacia() {
  return inicio == nullptr;
}

/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template <class T> int Lista<T>::getTamanio() {
  Node<T> *aux = inicio;
  int size = 0;
  while(aux != nullptr){
    aux = aux->getSiguiente();
    size++;
  }
  return size;
}

/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 */
template <class T> void Lista<T>::insertar(int pos, T dato) {
  Node<T> *aux = inicio, *nuevo;
  nuevo = new Node<T>;
  nuevo->setDato(dato);
  int posActual = 0;
  if(pos == 0){
    nuevo->setSiguiente(inicio);
    inicio = nuevo;
  }
  else{
    while(aux != nullptr && posActual < pos-1){
      aux = aux->getSiguiente();
      posActual++;
    }

    if (aux == nullptr){
      throw 404;
    }

    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);
  }
}

/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 */
template <class T> void Lista<T>::insertarPrimero(T dato) {
  insertar(0,dato);
}

/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */
template <class T> void Lista<T>::insertarUltimo(T dato) {
  Node<T> *aux = inicio, *nuevo = new Node<T>;
  nuevo->setDato(dato);
  if(esVacia()){
    nuevo->setSiguiente(inicio);
    inicio = nuevo;
    return;
  }
  while(aux->getSiguiente() != nullptr){
    aux = aux->getSiguiente();
  }
  nuevo->setSiguiente(aux->getSiguiente());
  aux->setSiguiente(nuevo);
}

/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template <class T> void Lista<T>::remover(int pos) {
  Node<T> *aux = inicio, *aBorrar;
  int posActual = 0;

  if(pos == 0){
    inicio = inicio->getSiguiente();
    delete aux;
    return;
  }

  while(aux != nullptr && posActual < pos-1){
    aux = aux->getSiguiente();
    posActual++;
  }

  if (aux == nullptr){
    throw 404;
  }
  aBorrar = aux->getSiguiente();
  aux->setSiguiente(aBorrar->getSiguiente());
  delete aBorrar;
}

/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template <class T> T Lista<T>::getDato(int pos) {
  Node<T> *aux = inicio;
  int posActual = 0;
  while(aux != nullptr && posActual < pos){
    aux = aux->getSiguiente();
    posActual++;
  }

  if (aux == nullptr){
    throw 404;
  }

  return aux->getDato();
}

/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 */
template <class T> void Lista<T>::reemplazar(int pos, T dato) {
  Node<T> *aux = inicio;
  int posActual = 0;
  while(aux != nullptr && posActual < pos){
    aux = aux->getSiguiente();
    posActual++;
  }

  if (aux == nullptr){
    throw 404;
  }
  aux->setDato(dato);
}

/**
 * Función que vacia la lista enlazada
 * @tparam T
 */
template <class T> void Lista<T>::vaciar() {
  Node<T> *aux = inicio, *aBorrar;

  while (aux != nullptr){
    aBorrar = aux;
    aux = aux->getSiguiente();
    delete aBorrar;
  }
  inicio = nullptr;
}

template <class T>
void Lista<T>::print() {
  Node<T> *aux = inicio;

  while (aux != nullptr) {
    std::cout << aux->getDato() << "->";
    aux = aux->getSiguiente();
  }
  std::cout << "NULL" << std::endl;
}

template <class T>
int Lista<T>::insertAfter2(T oldValue, int n, T newValue) {
  Node<T> *aux = inicio;
  int ocurrences  = 0;
  int curPos = 0;

  if(n == 0){
    insertarPrimero(newValue);
    return 0;
  }

  while(aux->getSiguiente() != nullptr && ocurrences < n){
    if(oldValue == aux->getDato()){
      ocurrences++;
    }
    aux = aux->getSiguiente();
    curPos++;
  }

  if(ocurrences == n){
    insertar(curPos, newValue);
    return curPos;
  }
  else{
    return -1;
  }
}

#endif // U02_LISTAS_LISTA_LISTA_H_


/*
 * Test
 *

#include "iostream"

using namespace std;

int main(){
  Lista<int> test;

  for(int i = 0; i<5; i++){
    test.insertar(i, i*2);
  }

  test.print();

  cout<<"Tamanio:"<<test.getTamanio()<<"\n";

  cout<<"-------------------------\n";

  test.insertarPrimero(11);
  test.insertarUltimo(99);

  test.print();

  cout<<"-------------------------\n";
  test.remover(0);
  test.remover(5);
  test.print();

  cout<<"-------------------------\n";

  cout<<"Dato pos 2:"<<test.getDato(2)<<"\n";

  cout<<"-------------------------\n";

  test.reemplazar(2,33);

  cout<<"Dato pos 2:"<<test.getDato(2)<<"\n";

  cout<<"-------------------------\n";
  test.vaciar();
  test.print();

  return 0;
}
 *
 * */