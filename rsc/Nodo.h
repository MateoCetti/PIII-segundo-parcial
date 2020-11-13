//
// Created by root on 19/8/20.
//

#ifndef PROGRAMACION3_NODO_H
#define PROGRAMACION3_NODO_H

template <class T>
class Node {
private:
  T dato;
  Node<T> *siguiente;
public:
  /*getDato, setDato, getSiguiente, setSiguiente*/
  T getDato(){
      return dato;
  };
  void setDato(T d){
      this->dato = d;
  };
  Node<T> *getSiguiente(){
      return siguiente;
  };
  void setSiguiente(Node<T> *s){
    this-> siguiente = s;
  };
};

#endif // PROGRAMACION3_NODO_H
