#ifndef INC_2_PARCIAL_PCASOSMUERTES_H
#define INC_2_PARCIAL_PCASOSMUERTES_H

#include "Provincia.h"

void quickSort(Provincia *arr, int first, int last){
    int i, j, middle;
    Provincia pivot, aux;

    middle = (first+last)/2;
    pivot = arr[middle];
    i=first;
    j=last;

    do{
        while(arr[i].getCounter()>pivot.getCounter())i++;
        while(arr[j].getCounter()<pivot.getCounter())j--;
        if(i<=j){
            aux= arr[i];
            arr[i]=arr[j];
            arr[j]= aux;
            i++;
            j--;
        }
    }while(i<=j);
    if(j>first) quickSort(arr, first, j);
    if(i< last) quickSort(arr, i, last);
}

void p_casos_muertes(Provincia *misProvincias,Caso *misCasos, int casos, char p){
    string provincias[24] = {
            "Buenos Aires", "CABA", "Catamarca", "Chaco", "Chubut", "Córdoba", "Corrientes",
            "Entre Ríos", "Formosa", "Jujuy", "La Pampa", "La Rioja", "Mendoza", "Misiones",
            "Neuquén", "Río Negro", "Salta", "San Juan", "San Luis", "Santa Cruz", "Santa Fe",
            "Santiago del Estero", "Tierra del Fuego", "Tucumán"};
    for(int i=0; i<24;i++){
        misProvincias[i].setName(provincias[i]);
    }
    if(p=='c'){
        for (int i = 0; i<casos; i++){
            for(int j=0;j<24;j++){
                if(misCasos[i].getClasifResumen().compare("Confirmado")==0){
                    if(misCasos[i].getProvincia().compare(provincias[j])==0){
                        misProvincias[j].IncrementCounter();
                        break;
                    }
                }
            }
        }
    }else if(p=='f'){
        for (int i = 0; i<casos; i++){
            for(int j=0;j<24;j++){
                if(misCasos[i].getFallecido().compare("SI")==0){
                    if(misCasos[i].getProvincia().compare(provincias[j])==0){
                        misProvincias[j].IncrementCounter();
                        break;
                    }
                }
            }
        }
    }
}

void printP(Provincia *misProvincias, int n){
    quickSort(misProvincias, 0,23);
    for(int i=0; i<n; i++){
        misProvincias[i].toString();
    }
}

#endif //INC_2_PARCIAL_PCASOSMUERTES_H
