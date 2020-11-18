#ifndef INC_2_PARCIAL_ARGUMENTSMANAGEMENT_H
#define INC_2_PARCIAL_ARGUMENTSMANAGEMENT_H

#include "iostream"

using namespace std;

/* Verificar si el parametro es un archivo .csv */
bool verifyCSV(string arg){
    if(arg.find(".csv") == string::npos){
        return false;
    }
    return true;
}

void verifyAux(int* myArguments, string arg, int pos){
    try {
        myArguments[pos] = stoi(arg);
    } catch (std::invalid_argument e) {
        myArguments[0] = -2;
    }
}

/* Verifica si el argumento pasado por
 * parametro es un "auxiliar" o no */
bool hasAuxiliar(char *nextArg){
    string arg = nextArg;
    if(arg[0] == '-' || verifyCSV(arg)){
        return false;
    }
    return true;
}



int parseParToDate(string par){
    if(par.length() == 10){
        par.replace(4,1,"");
        par.replace(6,1,"");
        return stoi(par);
    }
    return -2;
}

/*
 * Lee los argumentos pasados en la ejecucion del codigo
 * y devuelve un array de 5 enteros. cada posicion
 * significa un argumento (Pos: 0->estad, 1->p_casos,
 * 2->p_muertes, 3->casos_edad, 4->casos_cui)
*/
int *readArguments(int argc, char **argv){
    int *myArguments = new int[5]{-1, -1, -1, -1, -1};
    string lastArgument = argv[argc-1];
    for (int i = 1; i < argc-1; i++){
        /* Verify flag */
        if(argv[i][0] == '-'){
            /* Verificar cada argumento */
            if (strcmp(argv[i], "-estad") == 0) {
                myArguments[0] = 0;
            }
            else if(strcmp(argv[i], "-p_casos")  == 0) {
                if(i < argc-2 && hasAuxiliar(argv[i+1])){
                    i+=1;
                    verifyAux(myArguments, argv[i], 1);

                }else{
                    myArguments[1] = 0;
                }
            }
            else if(strcmp(argv[i], "-p_muertes")  == 0) {
                if(i < argc-2 && hasAuxiliar(argv[i+1])){
                    i+=1;
                    verifyAux(myArguments, argv[i], 2);
                }else{
                    myArguments[2] = 0;
                }
            }
            else if(strcmp(argv[i], "-casos_edad")  == 0) {
                if(i < argc-2 && hasAuxiliar(argv[i+1])){
                    i+=1;
                    verifyAux(myArguments, argv[i], 3);
                }else{
                    myArguments[3] = 0;
                }
            }
            else if(strcmp(argv[i], "-casos_cui")  == 0) {
                if(i < argc-2 && hasAuxiliar(argv[i+1])){
                    i+=1;
                    myArguments[4] = parseParToDate(argv[i]);
                    myArguments[0] = myArguments[4] == -2 ? -2 : myArguments[0];
                }else{
                    myArguments[4] = 0;
                }
            }
            else{
                myArguments[0] = -2;
                break;
            }
        }
        else{
            myArguments[0] = -2;
        }
        if(!verifyCSV(lastArgument)){
            myArguments[0] = -2;
        }
    }
    return myArguments;
}

/* Verifica si hay error en el array de int de argumentos,
 * o si todos son -1 */
bool hasError(int *myArguments){
    if(myArguments[0] == -2) return true;
    if(myArguments[1]>24 || myArguments[2]>24){
        return true;
    }
    for(int i=0;i<5; i++){
        if(myArguments[i] != -1){
            return false;
        }
    }
    return true;
}

#endif //INC_2_PARCIAL_ARGUMENTSMANAGEMENT_H
