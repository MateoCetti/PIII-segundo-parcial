#ifndef INC_2_PARCIAL_CASOSEDAD_H
#define INC_2_PARCIAL_CASOSEDAD_H

#include "iostream"
#include "string.h"
#include "Caso.h"
#include "Pila.h"

using namespace std;

void quickSortEdad(Caso *arr, int first, int last){
    int i, j, middle;
    Caso pivot, aux;

    middle = (first+last)/2;
    pivot = arr[middle];
    i=first;
    j=last;
    do{
        while(arr[i].getEdad()<pivot.getEdad())i++;
        while(arr[j].getEdad()>pivot.getEdad())j--;
        if(i<=j){
            aux= arr[i];
            arr[i]=arr[j];
            arr[j]= aux;
            i++;
            j--;
        }
    }while(i<=j);
    if(j>first) quickSortEdad(arr, first, j);
    if(i< last) quickSortEdad(arr, i, last);
}

Pila<Caso> *binarySearch(Caso *misCasos, int inf, int sup, int edad){
    int mitad, aux;
    Pila<Caso> *res = new Pila<Caso>;
    mitad = (inf+sup)/2;
    misCasos[mitad].toString();
    cout<<misCasos[mitad].getEdad();
        if(misCasos[mitad].getEdad()==edad){
            res->push(misCasos[mitad]);
            aux = mitad-1;
            while (misCasos[aux].getEdad()==edad){
                res->push(misCasos[aux]);
                aux--;
            }
            aux = mitad+1;
            while (misCasos[aux].getEdad()==edad){
                res->push(misCasos[aux]);
                aux++;
            }
            return res;
        }
    if(misCasos[mitad].getEdad()>edad) binarySearch(misCasos, inf, mitad, edad);
    else if(misCasos[mitad].getEdad()<edad) binarySearch(misCasos,mitad,sup,edad);
}

void quickSortProvincia(Caso *arr, int first, int last){
    int i, j, middle;
    Caso pivot, aux;

    middle = (first+last)/2;
    pivot = arr[middle];
    i=first;
    j=last;
    pivot.toString();
    do{
        while(arr[i].getProvincia()<pivot.getProvincia())i++;
        while(arr[j].getProvincia()>pivot.getProvincia())j--;
        if(i<=j){
            aux= arr[i];
            arr[i]=arr[j];
            arr[j]= aux;
            i++;
            j--;
        }
    }while(i<=j);
    if(j>first) quickSortProvincia(arr, first, j);
    if(i< last) quickSortProvincia(arr, i, last);
}

void casosEdad(Caso *misCasos, int casos, int edad){
	Pila<Caso> casosAux;

    quickSortEdad(misCasos,0, casos-1);
    Pila<Caso> *anda;
	anda = binarySearch(misCasos, 0, casos, edad);
	while (!anda->esVacia()){
	    anda->pop().toString();
	}
}

#endif //INC_2_PARCIAL_CASOSEDAD_H