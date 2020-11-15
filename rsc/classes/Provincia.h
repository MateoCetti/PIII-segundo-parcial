#ifndef INC_2_PARCIAL_PROVINCIA_H
#define INC_2_PARCIAL_PROVINCIA_H

#include "cstring"

/* Structura para provincias */
class Provincia{
private:
    string name;
    int infected;
    int deaths;

public:
    Provincia(){
        this->name="";
        this->infected=0;
        this->deaths=0;
    }
    void setName(string n){
        this->name = n;
    }
    string getName(){
        return this->name;
    }
    int getInfected(){
        return this->infected;
    }
    int getDeads(){
        return this->deaths;
    }
    void IncrementInfected(){
        this->infected+=1;
    }
    void IncrementDeads(){
        this->deaths+=1;
    }
    void printInfected(){
        std::cout<<"| Provincia: "<<name<<" | Infectados: "<<infected<<" |\n";
    }
    void printDeads(){
        std::cout<<"| Provincia: "<<name<<" | Fallecidos: "<<deaths<<" |\n";
    }
};

#endif //INC_2_PARCIAL_PROVINCIA_H
