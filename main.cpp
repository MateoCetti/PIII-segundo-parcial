/* Imprimir en consola - leer archivos - procesar streams - tiempo */

#include <iostream>

#include "rsc/Caso.h"
#include "rsc/ArgumentsManagement.h"
#include "rsc/ReadCSV.h"
#include "rsc/p_casos_muertes.h"
using namespace std;

int main(int argc, char **argv) {
    printf("\033c");
    int* myArguments = readArguments(argc, argv);
    if(hasError(myArguments)){
        cout<<"\n\nHubo un error en el pasaje de argumentos! \n"
              "Por favor ingrese los argumentos correctamente.\n\n\n";
    }
    else{
        cout<<"\n** Procesando datos **\n\n";
        int casos = getCases();
        Caso *misCasos = new Caso[casos];

        Estad *estad = new Estad;
        exploreCSV(myArguments[0], estad, misCasos, casos);

        if(myArguments[1] != -1){
            cout<<"\n\n** Mostrando contagios por provincia **\n\n";
            Provincia misProvincias[24];
            p_casos_muertes(misProvincias, misCasos, casos, 'c');
            int n = myArguments[1] == 0 ? 24 : myArguments[1];
            printP(misProvincias, n);
        }
        if(myArguments[2] != -1){
            cout<<"\n\n** Mostrando fallecidos por provincia **\n\n";
            Provincia misProvincias[24];
            p_casos_muertes(misProvincias, misCasos, casos, 'f');
            int n = myArguments[2] == 0 ? 24 : myArguments[2];
            printP(misProvincias, n);
        }
    }
    return 0;
}
