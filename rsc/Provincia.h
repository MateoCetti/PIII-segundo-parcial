#ifndef INC_2_PARCIAL_PROVINCIA_H
#define INC_2_PARCIAL_PROVINCIA_H

#include "cstring"

class Provincia{
private:
    string name;
    int counter;
public:
    Provincia(){
        this->name="";
        this->counter=0;
    }
    void setName(string n){
        this->name = n;
    }
    string getName(){
        return this->name;
    }
    int getCounter(){
        return this->counter;
    }
    void IncrementCounter(){
        this->counter+=1;
    }
    void toString(){
        std::cout<<name<<": "<<counter<<"\n";
    }
};

#endif //INC_2_PARCIAL_PROVINCIA_H
