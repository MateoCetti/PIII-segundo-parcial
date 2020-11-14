#ifndef INC_2_PARCIAL_READCSV_H
#define INC_2_PARCIAL_READCSV_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "cstring"
#include "ctime"
#include "cmath"

#include "Caso.h"
#include "Estad.h"

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
        case(7): //printear la provincia
            if(!word.empty()) word = word.substr(1, word.size()-2);
            else word = "NA";
            casoP->setProvincia(word);
            break;
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
        /*case(17):
            parsedWord = parseToInt(word);
            casoP->setProvinciaID(parsedWord);
            cout<<"\n"<<word;
            break;
        */
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

void fillEstad(Estad *estad, int casos, int infectados,
               int fallecidos, int rangoEtario,
               int *infPorRango, int *fallPorRango){
    estad->setMuestras(casos);
    estad->setInfectados(infectados);
    estad->setFallecidos(fallecidos);
    estad->setInfPorMuestras(((double)infectados/casos)*100);
    estad->setFallporInfectados(((double)fallecidos/infectados)*100);
    estad->setInfecRange(infPorRango, rangoEtario);
    estad->setFallRange(fallPorRango, rangoEtario);
}

void exploreCSV(int doEstad, Estad *estad, Caso *misCasos, int casos){
    time_t start = time(NULL);

    fstream fin;
    fin.open("./Covid19Casos.csv", ios::in);
    string line, word;

    getline(fin, line);

    int infectados = 0;
    int fallecidos = 0;
    int mayorEdad = 0;
    int aux = 0;

    while (getline(fin, line)){
        /* para las fechas y los enteros */
        int parsedWord = 0;
        stringstream s(line);

        for (int j = 0; j <= 20; j++){
            getline(s, word, ',');
            fillCase(word, parsedWord, j, &misCasos[aux]);
        }

        if(doEstad != -1){
            if(misCasos[aux].getFallecido().compare("SI") == 0) fallecidos+=1;
            if(misCasos[aux].getClasifResumen().compare("Confirmado") == 0) infectados+=1;
            if(misCasos[aux].getEdad() > mayorEdad && misCasos[aux].getEdad()<200) mayorEdad = misCasos[aux].getEdad();
        }
        aux+=1;
    }

    if(doEstad != -1){
        cout<<"** Mostrando datos estadisticos **\n";
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
        fillEstad(estad, casos, infectados, fallecidos, mayorEdad, infPorRango, fallPorRango);
        estad->toString();
    }
    time_t end = time(NULL);
    //cout<<"\nSegundos de lectura y guardado del csv: "<<end-start<<" \n\n";

}

#endif //INC_2_PARCIAL_READCSV_H
