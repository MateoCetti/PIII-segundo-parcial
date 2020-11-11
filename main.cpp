#include <iostream>
#include <fstream>
#include <sstream>
#include "string.h"

using namespace std;

void readArguments(int argc, char **argv){
    cout << "Cantidad de argumentos: " << argc-1 << "\n";
    for (int i = 1; i < argc; i++){
        if(argv[i][0] == '-'){
            cout << "Argumento " << i << " " << argv[i];
            if(i < argc-1){
                if(argv[i+1][0] != '-'){
                    cout<< " Auxiliar: "<< argv[i+1]<<"\n";
                    i++;
                }
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
