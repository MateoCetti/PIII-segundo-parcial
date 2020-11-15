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

void casosCui(Caso *misCasos, int casos, int fecha){
    Pila<Caso> casosAux;
    int contador = 0;
    if(fecha==0){
        for (int i = 0; i < casos; i++){
            if(misCasos[i].getCuiIntensivo().compare("SI") == 0){
                contador += 1;
                casosAux.push(misCasos[i]);
            }
        }
    }else{
        for (int i = 0; i < casos; i++){
            if(misCasos[i].getCuiIntensivo().compare("SI") == 0){
                if (misCasos[i].getFechaCuiIntensivo() >= fecha){
                    contador += 1;
                    casosAux.push(misCasos[i]);
                }
            }
        }
    }
    Caso *casosPorFecha = new Caso[contador];
    for (int j = 0; j < contador; j++){
        if(casosAux.peek().getProvincia().compare("Córdoba") == 0){
            Caso aux = casosAux.pop();
            aux.setProvincia("Cordoba");
            casosAux.push(aux);
        }
        casosPorFecha[j] = casosAux.pop();
    }
    quickSortFecha(casosPorFecha, 0, contador-1);
    for (int i = 0; i < contador; i+=100){
        casosPorFecha[i].toString();
    }
}

#endif //INC_2_PARCIAL_CASOSCUI_H
