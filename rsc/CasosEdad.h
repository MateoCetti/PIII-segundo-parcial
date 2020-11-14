#ifndef INC_2_PARCIAL_CASOSEDAD_H
#define INC_2_PARCIAL_CASOSEDAD_H

#include "iostream"
#include "string.h"
#include "Caso.h"
#include "Pila.h"

using namespace std;

void casosEdad(Caso *misCasos, int casos, int edad){
	Caso *casosPorEdad;
	Pila<Caso> casosAux;
	int contador = 0;
	for (int i = 0; i < casos; i++){
		if(misCasos[i].getEdadAniosMeses().compare("Años") == 0){
			if (misCasos[i].getEdad() == edad){
				contador += 1;
				casosAux.push(misCasos[i]);
			}
		}
	}
	casosPorEdad = new Caso[contador];
	for (int j = 0; j < contador; j++){
		casosPorEdad[j] = casosAux.pop();
	}
	for (int i = 0; i < contador; i++){
		casosPorEdad[i].toString();
	}
}
#endif //INC_2_PARCIAL_CASOSEDAD_H