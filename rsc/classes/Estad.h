#ifndef INC_2_PARCIAL_ESTAD_H
#define INC_2_PARCIAL_ESTAD_H

#include "iostream"

/* Estructura para los datos estadisticos */
class Estad{
private:
    int muestras;
    int infectados;
    int fallecidos;
    double infPorMuestras;
    double fallPorInfectados;
    int *infecRangoEtario;
    int *fallrangoEtario ;
    int rangoEtario;
public:
    Estad(){
        this->muestras = 0;
        this->infectados = 0;
        this->fallecidos = 0;
        this->infPorMuestras = 0;
        this->fallPorInfectados = 0;
        this->rangoEtario=0;
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
        if(this->rangoEtario==0)this->rangoEtario=r;
        this->infecRangoEtario = new int[rangoEtario]{};
        for(int i=0; i<rangoEtario; i++){
            this->infecRangoEtario[i] = inf[i];
        }
    }
    void setFallRange(int *fall, int r){
        if(this->rangoEtario==0)this->rangoEtario=r;
        this->fallrangoEtario = new int [rangoEtario]{};
        for(int i=0; i<rangoEtario; i++){
            this->fallrangoEtario[i] = fall[i];
        }
    }

    void toString(){
        std::cout<<"\n Muestras: "<<muestras
        <<" \n Infectados: "<<infectados
        <<" \n Fallecidos: "<<fallecidos
        <<" \n Porcentaje de infectados por muestras: "<<infPorMuestras<< " %"
        <<" \n Porcentaje de fallecidos por infectados: "<<fallPorInfectados<<" % \n";
        std::cout<<"-----------------------------------------------\n";
        std::cout<<"Infectados por rango etario: \n";
        for (int i = 0; i<rangoEtario; i++){
            std::cout<<"["<<i*10<<"-"<<(i+1)*10<<" Años]: "<<infecRangoEtario[i]<<"\n";
        }
        std::cout<<"-----------------------------------------------\n";
        std::cout<<"\nFallecidos por rango etario: \n";
        for (int i = 0; i<rangoEtario; i++){
            std::cout<<"["<<i*10<<"-"<<(i+1)*10<<" Años]: "<<fallrangoEtario[i]<<"\n";
        }
        std::cout<<"\n";
    }
};

#endif //INC_2_PARCIAL_ESTAD_H
