#ifndef INC_2_PARCIAL_P_CASOS_MUERTES_H
#define INC_2_PARCIAL_P_CASOS_MUERTES_H

/*

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


    if(p=='c'){
        for (int i = 0; i<casos; i++){
            for(int j=0;j<24;j++){
                if(misCasos[i].getClasifResumen().compare("Confirmado")==0){
                    if(misCasos[i].getProvinciaID()==provinciasID[j]){
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
                    if(misCasos[i].getProvinciaID()==provinciasID[j]){
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
*/
#endif //INC_2_PARCIAL_P_CASOS_MUERTES_H
