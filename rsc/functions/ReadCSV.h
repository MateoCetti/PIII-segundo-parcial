#ifndef INC_2_PARCIAL_READCSV_H
#define INC_2_PARCIAL_READCSV_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "cstring"
#include "ctime"
#include "cmath"

#include "../classes/Caso.h"
#include "../classes/Estad.h"

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

/* Llenar un atributo de una instancia de la clase Caso */
void fillCase(string word, int j, Caso *casoP){
    int parsedWord;
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
            casoP->setEdadAniosMeses(word);
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

/* Obtener la cantidad de muestras en el CSV */
int getCases(string csv){
    fstream fin;
    fin.open(csv, ios::in);

    string line;
    int casos = 0;

    getline(fin, line);
    while (getline(fin, line)){
        casos+=1;
    }
    return casos;
}

/* Llenar una clase Estad con los datos correspondientes */
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

/* Llenar los atributos infPorRango y fallPorRango de estad */
void fillRangedEstadVars(Caso miCaso, int *infPorRango, int *fallPorRango){
    if(miCaso.getClasifResumen().compare("Confirmado") == 0){
        if(miCaso.getEdadAniosMeses().compare("Meses") == 0){
            infPorRango[0]+=1;
        }else{
            infPorRango[miCaso.getEdad()/10]+=1;
        }
    }

    if(miCaso.getFallecido().compare("SI") == 0){
        if(miCaso.getEdadAniosMeses().compare("Meses") == 0){
            fallPorRango[0]+=1;
        }else{
            fallPorRango[miCaso.getEdad()/10]+=1;
        }
    }
}

void manageEstad(int mayorEdad, Caso *misCasos, int casos, int infectados, int fallecidos){
    Estad *estad = new Estad;
    cout<<"** Mostrando datos estadisticos **\n";
    mayorEdad = ceil((double)mayorEdad/10);
    int infPorRango[mayorEdad] = {};
    int fallPorRango[mayorEdad] = {};

    for(int i = 0; i< casos; i++){
        fillRangedEstadVars(misCasos[i], infPorRango, fallPorRango);
    }
    fillEstad(estad, casos, infectados, fallecidos, mayorEdad, infPorRango, fallPorRango);
    estad->toString();
}

/* Leer y guardar el CSV en un array | ejecutar -estad de ser necesario */
void exploreCSV(int doEstad, Caso *misCasos, int casos, string csv){
    string line, word;

    fstream fin;
    fin.open(csv, ios::in);

    /* estad */
    int infectados = 0;
    int fallecidos = 0;
    int mayorEdad = 0;
    int aux = 0;

    getline(fin, line);

    while (getline(fin, line)){
        stringstream s(line);

        for (int j = 0; j <= 20; j++){
            getline(s, word, ',');
            fillCase(word, j, &misCasos[aux]);
        }

        /* estad */
        if(doEstad != -1){
            if(misCasos[aux].getFallecido().compare("SI") == 0) fallecidos+=1;
            if(misCasos[aux].getClasifResumen().compare("Confirmado") == 0) infectados+=1;
            if(misCasos[aux].getEdad() > mayorEdad && misCasos[aux].getEdad()<200) mayorEdad = misCasos[aux].getEdad();
        }
        aux+=1;
    }

    /* estad */
    printf("\033c");
    if(doEstad != -1){
        manageEstad(mayorEdad, misCasos, casos, infectados, fallecidos);
    }
}

#endif //INC_2_PARCIAL_READCSV_H
