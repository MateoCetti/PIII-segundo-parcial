/* Imprimir en consola - leer archivos - procesar streams - tiempo */

#include <iostream>

#include "rsc/Caso.h"
#include "rsc/ArgumentsManagement.h"
#include "rsc/readCSV.h"

using namespace std;

int main(int argc, char **argv) {
    Caso c1;
    int* myArguments = readArguments(argc, argv);
    if(hasError(myArguments)){
        cout<<"\n\nHubo un error en el pasaje de argumentos! \n"
              "Por favor ingrese los argumentos correctamente.\n\n\n";
    }
    else{
        cout<<"\n\n** PROCESANDO DATOS **\n\n";
        /* TODO manage data */
        exploreCSV();
    }
    return 0;
}
