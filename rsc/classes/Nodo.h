#ifndef INC_2_PARCIAL_NODO_H
#define INC_2_PARCIAL_NODO_H

/* Estructura para un nodo */
template <class T> class Node{
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

#endif // INC_2_PARCIAL_NODO_H
