#ifndef INC_2_PARCIAL_CASOSEDAD_H
#define INC_2_PARCIAL_CASOSEDAD_H

#include "iostream"
#include "string.h"
#include "../classes/Caso.h"
#include "../classes/Pila.h"

using namespace std;

void quickSortEdad(Caso *arr, int first, int last){
    int i, j, middle;
    Caso pivot, aux;

    middle = (first+last)/2;
    pivot = arr[middle];
    i=first;
    j=last;
    arr[middle].toString();
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
    if(j>first) quickSortEdad(arr, first, j);
    if(i< last) quickSortEdad(arr, i, last);
}

/* Devuelve la mayor edad en el array (obviando el caso 1944) */
int getMaxEdad(Caso *misCasos, int casos){
    int maxEdad = 0;
    for(int i=0; i<casos; i++){
        if(misCasos[i].getEdad()>maxEdad && misCasos[i].getEdad()<200){
            maxEdad = misCasos[i].getEdad();
        }
    }
    return maxEdad;
}

/* Llenar la pila con los datos requeridos | Devuelve el contador */
int fillPila(Caso *misCasos, int casos, Pila<Caso> *casosAux, int edad){
    int contador = 0;
    for (int i = 0; i < casos; i++){
        if(misCasos[i].getEdadAniosMeses().compare("Años") == 0){
            if (misCasos[i].getEdad() == edad){
                contador += 1;
                casosAux->push(misCasos[i]);
            }
        }
    }
    return contador;
}

/* Pasar los datos de la pila al array */
void passData(int contador, Pila<Caso> *casosAux, Caso *casosPorEdad){
    for (int j = 0; j < contador; j++){
        if(casosAux->peek().getProvincia().compare("Córdoba") == 0){
            Caso aux = casosAux->pop();
            aux.setProvincia("Cordoba");
            casosAux->push(aux);
        }
        casosPorEdad[j] = casosAux->pop();
    }
}

/* Imprime los casos pedidos */
void printCasosEdad(int contador, Caso *casosPorEdad){
    cout<<"\n\n** Mostrando casos por la edad ingresada **\n\n";
    for (int i = 0; i < contador; i++){
        casosPorEdad[i].toString();
    }
}

/* Manage CasosEdad */
void casosEdad(Caso *misCasos, int casos, int edad){
    int maxEdad=getMaxEdad(misCasos, casos);
    if(edad > maxEdad){
        cout<<"La edad ingresada es erronea.\n";
        return;
    }

	Pila<Caso> *casosAux = new Pila<Caso>;

	int contador = 0;

	contador = fillPila(misCasos, casos, casosAux, edad);

	Caso *casosPorEdad = new Caso[contador];

	passData(contador, casosAux, casosPorEdad);

	quickSortEdad(casosPorEdad, 0, contador-1);

	printCasosEdad(contador, casosPorEdad);
}

#endif //INC_2_PARCIAL_CASOSEDAD_H