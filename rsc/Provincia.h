#ifndef INC_2_PARCIAL_PROVINCIA_H
#define INC_2_PARCIAL_PROVINCIA_H

#include "cstring"

class Provincia{
private:
    int ID;
    string name;
    int infected;
    int dead;
public:
    Provincia(){
        this->name="";
        this->infected=0;
        this->dead=0;
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
    void IncrementInfected(){
        this->infected+=1;
    }
    void IncrementDead(){
        this->dead+=1;
    }
    void printInfected(){
        std::cout<<name<<": "<<infected<<"\n";
    }
    void printDead(){
        std::cout<<name<<": "<<dead<<"\n";
    }
};

#endif //INC_2_PARCIAL_PROVINCIA_H
