/* Imprimir en consola - leer archivos - procesar streams - tiempo */

#include <iostream>

#include "rsc/Caso.h"
#include "rsc/ArgumentsManagement.h"
#include "rsc/ReadCSV.h"
#include "rsc/Provincia.h"
using namespace std;

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

int main(int argc, char **argv) {
    int* myArguments = readArguments(argc, argv);
    if(hasError(myArguments)){
        cout<<"\n\nHubo un error en el pasaje de argumentos! \n"
              "Por favor ingrese los argumentos correctamente.\n\n\n";
    }
    else{
        cout<<"\n\n** Procesando datos **\n\n";
        /* TODO manage data */
        int casos = getCases();
        Caso *misCasos = new Caso[casos];
        Estad *estad = new Estad;
        exploreCSV(myArguments[0], estad, misCasos, casos);
        /* 0.Buenos Aires 1.CABA 2.Catamarca 3.Chaco 4.Chubut 5.Córdoba 6.Corrientes 7.Entre Ríos
        8.Formosa 9.Jujuy 10.La Pampa 11.La Rioja 12.Mendoza 13.Misiones 14. Neuquén
        15.Río Negro 16.Salta 17.San Juan 18.San Luis 19.Santa Cruz 20.Santa Fe
        21.Santiago del Estero 22.Tierra del Fuego 23.Tucumán*/
        if(myArguments[1] != -1){
            cout<<"\n\n** Mostrando casos por provincia **\n\n";
            string provincias[24] = {
                    "Buenos Aires", "CABA", "Catamarca", "Chaco", "Chubut", "Córdoba", "Corrientes",
                    "Entre Ríos", "Formosa", "Jujuy", "La Pampa", "La Rioja", "Mendoza", "Misiones",
                    "Neuquén", "Río Negro", "Salta", "San Juan", "San Luis", "Santa Cruz", "Santa Fe",
                    "Santiago del Estero", "Tierra del Fuego", "Tucumán"};
            Provincia misProvincias[24];
            for(int i=0; i<24;i++){
                misProvincias[i].setName(provincias[i]);
            }
            for (int i = 0; i<casos; i++){
                for(int j=0;j<24;j++){
                    if(misCasos[i].getProvincia().compare(provincias[j])==0){
                        misProvincias[j].IncrementCounter();
                    }
                }
            }
            int n = myArguments[1] == 0 ? 24 : myArguments[1];
            quickSort(misProvincias, 0,23);
            for(int i=0; i<n; i++){
                misProvincias[i].toString();
            }
        }
    }
    return 0;
}
