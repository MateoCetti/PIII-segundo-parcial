#include <iostream>
#include <fstream>
#include <sstream>
#include "string.h"

using namespace std;

bool hasAuxiliar(char *nextArg){
    if(nextArg[0] != '-'){
        cout<< " Auxiliar: "<< nextArg<<"\n";
        return 1;
    }
    return 0;
}

void verifyAviliableParameter(int i, char **argv){

}

void readArguments(int argc, char **argv){
    for (int i = 1; i < argc; i++){
        if(argv[i][0] == '-'){
            if (strcmp(argv[i], "-estad") == 0) {
                cout << "Argumento " << i << " " << argv[i];
            }
            else if(strcmp(argv[i], "-p_casos")  == 0) {
                cout << "Argumento " << i << " " << argv[i];
                if(i < argc-1){
                    bool x = hasAuxiliar(argv[i+1]);
                    i+=x;
                }
            }
            else if(strcmp(argv[i], "-p_muertes")  == 0) {
                cout << "Argumento " << i << " " << argv[i];
                if(i < argc-1){
                    bool x = hasAuxiliar(argv[i+1]);
                    i+=x;
                }
            }
            else if(strcmp(argv[i], "-casos_edad")  == 0) {
                cout << "Argumento " << i << " " << argv[i];
                if(i < argc-1){
                    bool x = hasAuxiliar(argv[i+1]);
                    i+=x;
                }
            }
            else if(strcmp(argv[i], "-casos_cui")  == 0) {
                cout << "Argumento " << i << " " << argv[i];
                if(i < argc-1){
                    bool x = hasAuxiliar(argv[i+1]);
                    i+=x;
                }
            }
            else{
                cout<<"Ingrese un argumento valido.\n";
            }
            cout<< "\n\n";
        }
        else{
            cout<<"Ingrese un argumento valido.\n";
        }
    }
    cout << "\n";
}

int main(int argc, char **argv) {
    readArguments(argc, argv);
    return 0;
}
