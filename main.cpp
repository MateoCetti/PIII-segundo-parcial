/* Imprimir en consola - leer archivos - procesar streams - tiempo */

#include <iostream>
#include "ctime"

#include "rsc/Caso.h"
#include "rsc/ArgumentsManagement.h"
#include "rsc/ReadCSV.h"
#include "rsc/PCasosMuertes.h"
#include "rsc/CasosEdad.h"
#include "rsc/casosCui.h"

using namespace std;

int main(int argc, char **argv) {
    time_t start = time(NULL);
    int* myArguments = readArguments(argc, argv);
    fstream fin;
    fin.open(argv[argc-1], ios::in);
    if(hasError(myArguments) || !fin.is_open()){
        cout<<"\n\nHubo un error en el pasaje de argumentos! \n"
              "Por favor ingrese los argumentos correctamente.\n\n\n";
    }
    else{
        printf("\033c");
        cout<<"\n** Procesando datos **\n\n";
        int casos = getCases();
        Caso *misCasos = new Caso[casos];

        exploreCSV(myArguments[0], misCasos, casos, argv[argc-1]);

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
        if(myArguments[4] != -1){
            cout<<"\n\n** Mostrando casos por fecha de cuidados intensivos **\n\n";
            int fecha = myArguments[4];
            casosCui(misCasos, casos, fecha);
        }
    }
    time_t end = time(NULL);
    cout<<"\nSegundos para correr el/los parametros: "<<end-start<<" \n\n";
    return 0;
}
