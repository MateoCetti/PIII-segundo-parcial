#ifndef INC_2_PARCIAL_CASOSCUI_H
#define INC_2_PARCIAL_CASOSCUI_H

#include "../classes/Caso.h"
#include "../classes/Pila.h"

void quickSortFecha(Caso *arr, int first, int last){
    int i, j, middle;
    Caso pivot, aux;

    middle = (first+last)/2;
    pivot = arr[middle];
    i=first;
    j=last;

    do{
        while(arr[i].getFechaCuiIntensivo()<pivot.getFechaCuiIntensivo())i++;
        while(arr[j].getFechaCuiIntensivo()>pivot.getFechaCuiIntensivo())j--;
        if(i<=j){
            aux= arr[i];
            arr[i]=arr[j];
            arr[j]= aux;
            i++;
            j--;
        }
    }while(i<=j);
    if(j>first) quickSortFecha(arr, first, j);
    if(i< last) quickSortFecha(arr, i, last);
}

/* Llenar la pila con los datos pedidos | Devuelve el contador */
int fillPilaCui(Caso *misCasos, int casos, Pila<Caso> *casosAux, int fecha){
    int contador = 0;
    if(fecha==0){
        for (int i = 0; i < casos; i++){
            if(misCasos[i].getCuiIntensivo().compare("SI") == 0){
                contador += 1;
                casosAux->push(misCasos[i]);
            }
        }
    }else{
        for (int i = 0; i < casos; i++){
            if(misCasos[i].getCuiIntensivo().compare("SI") == 0){
                if (misCasos[i].getFechaCuiIntensivo() >= fecha){
                    contador += 1;
                    casosAux->push(misCasos[i]);
                }
            }
        }
    }
    return contador;
}

/* Pasa los casos de la pila al array */
void passDataCui(Caso *casosPorFecha, Pila<Caso> *casosAux, int contador){
    for (int j = 0; j < contador; j++){
        casosPorFecha[j] = casosAux->pop();
    }
}

/* Printea los casos */
void printCasosCui(Caso *casosPorFecha, int contador){
    cout<<"\n\n** Mostrando casos por fecha de cuidados intensivos **\n\n";
    for (int i = 0; i < contador; i++){
        casosPorFecha[i].toString();
    }
}

/* Manage casos_cui */
void casosCui(Caso *misCasos, int casos, int fecha){
    Pila<Caso> *casosAux = new Pila<Caso>;
    int contador = fillPilaCui(misCasos, casos, casosAux, fecha);

    if (casosAux->esVacia()){
        cout<<"Fecha incorrecta\n";
        return;
    }

    Caso *casosPorFecha = new Caso[contador];

    passDataCui(casosPorFecha, casosAux, contador);

    quickSortFecha(casosPorFecha, 0, contador-1);

    printCasosCui(casosPorFecha, contador);
}

#endif //INC_2_PARCIAL_CASOSCUI_H
