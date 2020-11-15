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
    Pila<Caso> *res;
        mitad = (inf+sup)/2;
        if(misCasos[mitad].getEdad()==edad){
            res->push(misCasos[mitad]);
            aux = mitad;
            while (misCasos[aux].getEdad()==edad){
                aux--;
                res->push(misCasos[aux]);
            }
            aux = mitad;
            while (misCasos[aux].getEdad()==edad){
                aux++;
                res->push(misCasos[aux]);
            }
            return res;
        }
    misCasos[mitad].toString();
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
	int contador = 0;

    quickSortEdad(misCasos,0, casos-1);
	Pila<Caso> *anda = binarySearch(misCasos, 0, casos, edad);
	while (!anda->esVacia()){
	    anda->pop().toString();
	}
	/*
	for (int i = 0; i < casos; i++){
		if(misCasos[i].getEdadAniosMeses().compare("Años") == 0){
			if (misCasos[i].getEdad() == edad){
				contador += 1;
				casosAux.push(misCasos[i]);
			}
		}
	}
	Caso *casosPorEdad = new Caso[contador];
	for (int j = 0; j < contador; j++){
		if(casosAux.peek().getProvincia().compare("Córdoba") == 0){
			Caso aux = casosAux.pop();
			aux.setProvincia("Cordoba");
			casosAux.push(aux);
		}
		casosPorEdad[j] = casosAux.pop();
	}
	//quickSortEdad(casosPorEdad, 0, contador-1);
	for (int i = 0; i < contador; i+=100){
		casosPorEdad[i].toString();
	}*/
}

#endif //INC_2_PARCIAL_CASOSEDAD_H