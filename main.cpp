/* Imprimir en consola - leer archivos - procesar streams - tiempo */
#include <iostream>
#include <fstream>
#include <sstream>
#include "string.h"
#include "time.h"

/* Lista enlazada */
#include "rsc/Lista.h"
#include "rsc/Caso.h"

using namespace std;

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
 * significa un argumento
 * Los valores del array pueden ser los siguientes:
 *      - -2: (solo aparece en la primera pocision) sifnifica que hubo un error
 *          al pasar algun argumento en la ejecucion del comando
 *
 *      - -1: No se paso dicho argumento
 *
 *      - n>=0 Se paso el argumento con el valor indicado (n)*/
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


void exploreCSV(){

    int contador = 0;

    int interest[] = { 0, 2, 3, 12, 13, 14, 17, 20 };

    int nColumns = sizeof(interest) / sizeof(interest[0]);

    fstream fin;
    fin.open("./Covid19Casos.csv", ios::in);

    int casos = 0;

    Lista<string> row;

    string line, word;

    time_t start = time(NULL);

    while (getline(fin, line) && contador < 2){
        Caso casoP;
        casos+=1;
        contador += 1;
        row.vaciar();

        stringstream s(line);

        for (int x = 0; x < nColumns; x++)
        {
            getline(s, word, ',');
            cout <<"| "<< row.getDato(interest[x]) << " | ";
        }

        while (getline(s, word, ',')){
            if(word.size() > 0) word = word.substr(1, word.size()-2);
            else word = "NA";

            casoP.id = stoi(word);
            //row.insertarUltimo(word);
        }
        /*
        for(int j=0; j<row.getTamanio(); j++){
            cout<<row.getDato(j);
        }*/

        /*if (row.getDato(20).compare("Confirmado") == 0){
            for (int j = 0; j < nColumns; j++)
            {
                cout <<"| "<< row.getDato(interest[j]) << " | ";
            }
            cout<<"\n";
        }*/
        for (int j = 0; j < nColumns; j++)
        {
            cout <<"| "<< row.getDato(interest[j]) << " | ";
        }
        cout<<"\n";

    }
    time_t end = time(NULL);
    cout<<"Se tarda "<<end-start<<" segundos en leer el archivo\n";
    cout<<"hay: "<<casos<<" casos\n";
}

int main(int argc, char **argv) {
    Caso c1;
    int* myArguments = readArguments(argc, argv);
    if(hasError(myArguments)){
        cout<<"\n\nHubo un error en el pasaje de argumentos! \nPor favor ingrese los argumentos correctamente.\n\n\n";
    }
    else{
        cout<<"** PROCESANDO DATOS **\n";
        /* TODO manage data */
        exploreCSV();
    }
    return 0;
}
