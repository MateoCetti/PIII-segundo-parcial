#ifndef INC_2_PARCIAL_PCASOSMUERTES_H
#define INC_2_PARCIAL_PCASOSMUERTES_H

#include "../classes/Provincia.h"

void quickSortInfected(Provincia *arr, int first, int last){
    int i, j, middle;
    Provincia pivot, aux;

    middle = (first+last)/2;
    pivot = arr[middle];
    i=first;
    j=last;

    do{
        while(arr[i].getInfected()>pivot.getInfected())i++;
        while(arr[j].getInfected()<pivot.getInfected())j--;
        if(i<=j){
            aux= arr[i];
            arr[i]=arr[j];
            arr[j]= aux;
            i++;
            j--;
        }
    }while(i<=j);
    if(j>first) quickSortInfected(arr, first, j);
    if(i< last) quickSortInfected(arr, i, last);
}

void quickSortDeaths(Provincia *arr, int first, int last){
    int i, j, middle;
    Provincia pivot, aux;

    middle = (first+last)/2;
    pivot = arr[middle];
    i=first;
    j=last;

    do{
        while(arr[i].getDeads()>pivot.getDeads())i++;
        while(arr[j].getDeads()<pivot.getDeads())j--;
        if(i<=j){
            aux= arr[i];
            arr[i]=arr[j];
            arr[j]= aux;
            i++;
            j--;
        }
    }while(i<=j);
    if(j>first) quickSortDeaths(arr, first, j);
    if(i< last) quickSortDeaths(arr, i, last);
}

void p_casos_muertes(Provincia *misProvincias,Caso *misCasos, int casos){
    string provincias[24] = {
            "Buenos Aires", "CABA", "Catamarca", "Chaco", "Chubut", "Córdoba", "Corrientes",
            "Entre Ríos", "Formosa", "Jujuy", "La Pampa", "La Rioja", "Mendoza", "Misiones",
            "Neuquén", "Río Negro", "Salta", "San Juan", "San Luis", "Santa Cruz", "Santa Fe",
            "Santiago del Estero", "Tierra del Fuego", "Tucumán"};
    for(int i=0; i<24;i++){
        misProvincias[i].setName(provincias[i]);
    }
    for (int i = 0; i<casos; i++){
        for(int j=0;j<24;j++){
            /* Increment infected */
            if(misCasos[i].getClasifResumen().compare("Confirmado")==0){
                if(misCasos[i].getProvincia().compare(provincias[j])==0){
                    misProvincias[j].IncrementInfected();
                    break;
                }
            }
            /* Increment Deaths */
            if(misCasos[i].getFallecido().compare("SI")==0){
                if(misCasos[i].getProvincia().compare(provincias[j])==0){
                    misProvincias[j].IncrementDeads();
                    break;
                }
            }
        }
    }
}

void printP(Provincia *misProvincias, int n, char p){
    if(p=='c'){
        cout<<"\n\n** Mostrando contagios por provincia **\n\n";
        quickSortInfected(misProvincias, 0,23);
        for(int i=0; i<n; i++){
            misProvincias[i].printInfected();
        }
    }
    if(p=='f'){
        cout<<"\n\n** Mostrando fallecidos por provincia **\n\n";
        quickSortDeaths(misProvincias, 0,23);
        for(int i=0; i<n; i++){
            misProvincias[i].printDeads();
        }
    }
}

#endif //INC_2_PARCIAL_PCASOSMUERTES_H
