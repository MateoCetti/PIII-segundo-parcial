#ifndef INC_2_PARCIAL_ESTAD_H
#define INC_2_PARCIAL_ESTAD_H

#include "iostream"

class Estad{
private:
    int muestras;
    int infectados;
    int fallecidos;
    double infPorMuestras;
    double fallPorInfectados;
    int *infecRangoEtario;
    int *fallrangoEtario ;
public:
    Estad(){
        this->muestras = 0;
        this->infectados = 0;
        this->fallecidos = 0;
        this->infPorMuestras = 0;
        this->fallPorInfectados = 0;
    }
    void setMuestras(int m){
        this->muestras = m;
    }
    void setInfectados(int i){
        this->infectados = i;
    }
    void setFallecidos(int f){
        this->fallecidos = f;
    }
    void setInfPorMuestras(double ipm){
        this->infPorMuestras = ipm;
    }
    void setFallporInfectados(double fpi){
        this->fallPorInfectados = fpi;
    }
    void setInfecRange(int *inf, int r){
        std::cout<<"hola\n";
        this->infecRangoEtario = new int[r]{};
        for(int i=0; i<r; i++){
            this->infecRangoEtario[i] = inf[i];
        }
    }
    void setFallRange(int *fall, int r){
        this->fallrangoEtario = new int [r]{};
        for(int i=0; i<r; i++){
            this->fallrangoEtario[i] = fall[i];
        }
    }

    void toString(){
        std::cout<<"\nCantidad de muestras: "<<muestras
        <<"\nCantidad de infectados: "<<infectados
        <<"\nCantidad de fallecidos: "<<fallecidos
        <<"\nPorcentaje de infectados por muestras: "<<infPorMuestras
        <<"\nPorcentaje de fallecidos por infectados"<<fallPorInfectados<<"\n";
    }
};

#endif //INC_2_PARCIAL_ESTAD_H
