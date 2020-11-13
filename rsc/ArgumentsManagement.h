#ifndef INC_2_PARCIAL_ARGUMENTSMANAGEMENT_H
#define INC_2_PARCIAL_ARGUMENTSMANAGEMENT_H

/* Verifica si el argumento pasado por
 * parametro es un "auxiliar" o no */
bool hasAuxiliar(char *nextArg){
    if(nextArg[0] != '-'){
        return 1;
    }
    return 0;
}

/* Lee los argumentos pasados en la ejecucion del codigo
 * y devuelve un array de 5 enteros. cada entero en el array
 * significa un argumento (Pos: 0->estad, 1->p_casos,
 * 2->p_muertes, 3->casos_edad, 4->casos_cui)
*/
int *readArguments(int argc, char **argv){
    int *myArguments = new int[5]{-1, -1, -1, -1, -1};
    for (int i = 1; i < argc; i++){
        if(argv[i][0] == '-'){
            if (strcmp(argv[i], "-estad") == 0) {
                myArguments[0] = 0;
            }
            else if(strcmp(argv[i], "-p_casos")  == 0) {
                if(i < argc-1){
                    bool x = hasAuxiliar(argv[i+1]);
                    i+=x;
                    myArguments[1] = stoi(argv[i]);
                }else{
                    myArguments[1] = 0;
                }
            }
            else if(strcmp(argv[i], "-p_muertes")  == 0) {
                if(i < argc-1){
                    bool x = hasAuxiliar(argv[i+1]);
                    i+=x;
                    myArguments[2] = stoi(argv[i]);
                }else{
                    myArguments[2] = 0;
                }
            }
            else if(strcmp(argv[i], "-casos_edad")  == 0) {
                if(i < argc-1){
                    bool x = hasAuxiliar(argv[i+1]);
                    i+=x;
                    myArguments[3] = stoi(argv[i]);
                }else{
                    myArguments[3] = 0;
                }
            }
            else if(strcmp(argv[i], "-casos_cui")  == 0) {
                if(i < argc-1){
                    bool x = hasAuxiliar(argv[i+1]);
                    i+=x;
                    myArguments[4] = stoi(argv[i]);
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
    }
    return myArguments;
}

/* Verifica si error en el array de int de argumentos,
 * o si todos son -1 */
bool hasError(int *myArguments){
    if(myArguments[0] == -2) return 1;
    bool notEmpty = false;
    for(int i=0;i<5; i++){
        if(myArguments[i] != -1){
            return 0;
        }
    }
    return 1;
}

#endif //INC_2_PARCIAL_ARGUMENTSMANAGEMENT_H
