#include <iostream>
#include <fstream>
#include <sstream>
#include "string.h"
#include "rsc/Lista.h"

using namespace std;

bool hasAuxiliar(char *nextArg){
    if(nextArg[0] != '-'){
        return 1;
    }
    return 0;
}

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
                cout<<"Ingrese un argumento valido.\n";
                myArguments[0] = -2;
                break;
            }
        }
        else{
            cout<<"Ingrese un argumento valido.\n";
            myArguments[0] = -2;
        }
    }
    cout << "\n";
    return myArguments;
}

void exploreCSV()
{

    int interest[] = { 0, 2, 3, 12, 13, 14, 17, 20 };

    int nColumns = sizeof(interest) / sizeof(interest[0]);

    fstream fin;
    fin.open("./Covid19Casos.csv", ios::in);

    Lista<string> row;

    string line, word;

    for (int i = 0; i < 4; i++)
    {
        row.vaciar();
        getline(fin, line);

        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.insertarUltimo(word);
        }

        for(int j=0; j<row.getTamanio(); j++){
            cout<<row.getDato(j);
        }
        /*
        if (row.getDato(20).compare("Confirmado") == 0)
        {
            for (int j = 0; j < nColumns; j++)
            {
                cout << row.getDato(interest[j]) << " ";
            }
        }
        */
        cout << "\n";
    }
}

int main(int argc, char **argv) {
    int* myArguments = readArguments(argc, argv);
    for(int i = 0; i < 5; i++){
        cout << " " << myArguments[i]<<"\n";
    }
    //exploreCSV();
    return 0;
}
