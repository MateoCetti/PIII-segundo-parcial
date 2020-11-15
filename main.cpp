/* Imprimir en consola - leer archivos - procesar streams - tiempo */

#include <iostream>
#include "ctime"

#include "rsc/Caso.h"
#include "rsc/ArgumentsManagement.h"
#include "rsc/ReadCSV.h"
#include "rsc/p_casos_muertes.h"
#include "rsc/CasosEdad.h"

using namespace std;

int main(int argc, char **argv) {
    printf("\033c");
    time_t start = time(NULL);
    int* myArguments = readArguments(argc, argv);
    if(hasError(myArguments)){
        cout<<"\n\nHubo un error en el pasaje de argumentos! \n"
              "Por favor ingrese los argumentos correctamente.\n\n\n";
    }
    else{
        cout<<"\n** Procesando datos **\n\n";
        int casos = getCases();
        Caso *misCasos = new Caso[casos];

        exploreCSV(myArguments[0], misCasos, casos);

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
        if(myArguments[3] != -1){
            cout<<"\n\n** Mostrando casos por la edad ingresada **\n\n";
            int edad = myArguments[3];
            casosEdad(misCasos, casos, edad);
        }
    }
    time_t end = time(NULL);
    cout<<"\nSegundos para correr el/los parametros: "<<end-start<<" \n\n";
    return 0;
}
