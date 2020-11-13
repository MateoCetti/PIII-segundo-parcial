#ifndef INC_2_PARCIAL_READCSV_H
#define INC_2_PARCIAL_READCSV_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "cstring"
#include "ctime"
#include "math.h"

#include "Caso.h"

int parseToDate(string word){
    if(word.empty()) return 0;
    word = word.substr(1, word.size()-2);
    word.replace(4,1,"");
    word.replace(6,1,"");
    return stoi(word);
}

string parseToString(string word){
    if(!word.empty()) word = word.substr(1, word.size()-2);
    else word = "NA";
    return word;
}

int parseToInt(string word){
    if(!word.empty()) word = word.substr(1, word.size()-2);
    else return 0;
    return stoi(word);
}

void fillCase(string word, int parsedWord, int j, Caso *casoP){
    switch (j) {
        case(0):
            parsedWord = parseToInt(word);
            casoP->setID(parsedWord);
            break;
        case(2):
            parsedWord = parseToInt(word);
            casoP->setEdad(parsedWord);
            break;
        case(3):
            word = parseToString(word);
            casoP->setEdadAñosMeses(word);
            break;
            /*case(7): printear la provincia
                if(!word.empty()) word = word.substr(1, word.size()-2);
                else word = "NA";
                cout<<"\n"<<word<<"\n";
                break;
            */
        case(12):
            word = parseToString(word);
            casoP->setCuiIntensivo(word);
            break;
        case(13):
            parsedWord = parseToDate(word);
            casoP->setFechaCuiIntensivo(parsedWord);
            break;
        case(14):
            word = parseToString(word);
            casoP->setFallecido(word);
            break;
        case(17):
            parsedWord = parseToInt(word);
            casoP->setProvinciaID(parsedWord);
            break;
        case(20):
            word = parseToString(word);
            casoP->setClasifResumen(word);
            break;
    }
}

int getCases(){
    fstream fin;
    string line;
    fin.open("./Covid19Casos.csv", ios::in);
    int casos = 0;
    getline(fin, line);
    while (getline(fin, line)){
        casos+=1;
    }
    return casos;
}

void exploreCSV(){

    time_t start = time(NULL);

    int casos = getCases();

    fstream fin;
    fin.open("./Covid19Casos.csv", ios::in);
    string line, word;
    Caso *misCasos = new Caso[casos];
    getline(fin, line);

    int infectados = 0;
    int fallecidos = 0;
    int mayorEdad = 0;
    int aux = 0;
    //cout<<"-------------------------------------------------------\n";
    while (getline(fin, line)){
        /* para las fechas y los enteros */
        int parsedWord = 0;
        stringstream s(line);
        for (int j = 0; j <= 20; j++){
            getline(s, word, ',');
            fillCase(word, parsedWord, j, &misCasos[aux]);
        }
        //misCasos[aux].toString();
        if(misCasos[aux].getFallecido().compare("SI") == 0) fallecidos+=1;
        if(misCasos[aux].getClasifResumen().compare("Confirmado") == 0) infectados+=1;
        if(misCasos[aux].getEdad() > mayorEdad && misCasos[aux].getEdad()<200) mayorEdad = misCasos[aux].getEdad();
        aux+=1;
    }
    mayorEdad = ceil((double)mayorEdad/10);
    int infPorRango[mayorEdad] = {};
    int fallPorRango[mayorEdad] = {};
    for(int i = 0; i< casos; i++){
        if(misCasos[i].getClasifResumen().compare("Confirmado") == 0){
            infPorRango[misCasos[i].getEdad()/10]+=1;
        }
        if(misCasos[i].getFallecido().compare("SI") == 0){
            fallPorRango[misCasos[i].getEdad()/10]+=1;
        }
    }
    //cout<<"-------------------------------------------------------\n";
    time_t end = time(NULL);
    cout<<"\nSe tarda "<<end-start<<" segundos en leer y guardar el archivo\n\n";
    cout<<"hay: "<<casos<<" muestras\n";
    cout<<"hay: "<<infectados<<" infectados\n";
    cout<<"hay: "<<fallecidos<<" fallecidos\n";
    cout<<"hay: "<<((double)infectados/casos)*100<<" % de infectados\n";
    cout<<"hay: "<<((double)fallecidos/casos)*100<<" % de fallecidos\n";
    cout<<"Rango etario infectados:";
    for(int i = 0; i<mayorEdad; i++){
        cout<<" "<<infPorRango[i]<<" ";
    }
    cout<<"\n\nRango etario fallecidos:";
    for(int i = 0; i<mayorEdad; i++){
        cout<<" "<<fallPorRango[i]<<" ";
    }
}

#endif //INC_2_PARCIAL_READCSV_H
