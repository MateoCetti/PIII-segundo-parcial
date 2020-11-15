/* Imprimir en consola - leer archivos - procesar streams - tiempo */

#include <iostream>
#include "ctime"

#include "rsc/classes/Caso.h"
#include "rsc/functions/ArgumentsManagement.h"
#include "rsc/functions/ReadCSV.h"
#include "rsc/functions/PCasosMuertes.h"
#include "rsc/functions/CasosEdad.h"
#include "rsc/functions/casosCui.h"

using namespace std;

void manageData(int *myArguments, Caso *misCasos, int casos, char **argv, int argc){

    exploreCSV(myArguments[0], misCasos, casos, argv[argc-1]);

    /* procesar -p_casos  y p_muertes*/
    if(myArguments[1] != -1 || myArguments[2] != -1){
        Provincia misProvincias[24];
        p_casos_muertes(misProvincias, misCasos, casos);
        /* Imprimir p_casos */
        if(myArguments[1] != -1){
            int n = myArguments[1] == 0 ? 24 : myArguments[1];
            printP(misProvincias, n, 'c');
        }
        /* Imprimir p_casos */
        if(myArguments[2] != -1){
            int n = myArguments[2] == 0 ? 24 : myArguments[2];
            printP(misProvincias, n, 'f');
        }
    }
    /* ejecutar -casos_edad */
    if(myArguments[3] != -1){
        int edad = myArguments[3];
        casosEdad(misCasos, casos, edad);
    }
    /* ejecutar -casos_cui */
    if(myArguments[4] != -1){
        int fecha = myArguments[4];
        casosCui(misCasos, casos, fecha);
    }
}

int main(int argc, char **argv) {

    time_t start = time(NULL);

    /* -2 ERROR | -1 Not requested | n Requested (n>=0) */
    int* myArguments = readArguments(argc, argv);

    fstream fin;
    fin.open(argv[argc-1], ios::in);

    if(hasError(myArguments) || !fin.is_open()){
        cout<<"\n\nHubo un error en el pasaje de argumentos! \n"
              "Por favor ingrese los argumentos correctamente.\n\n\n";
        return 0;
    }

    printf("\033c");
    cout<<"\n** Procesando datos **\n\n";

    int casos = getCases(argv[argc-1]);
    Caso *misCasos = new Caso[casos];

    manageData(myArguments, misCasos, casos, argv, argc);

    time_t end = time(NULL);
    cout<<"\nSegundos para correr el/los parametros: "<<end-start<<" \n\n";
    return 0;
}
