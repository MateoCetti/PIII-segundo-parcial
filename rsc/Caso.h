#ifndef INC_2_PARCIAL_CASO_H
#define INC_2_PARCIAL_CASO_H
#include "string.h"

using namespace std;

class Caso{

public:
		int id;
		int edad;
		string edad_anios_meses;
		string cuidado_intensivo;
		string fecha_cui_intensivo;
		string fallecido;
		int carga_provincia_id;
		string clasificacion_resumen;

		Caso(){
			this->id = 0;
			this->edad = 0;
			this->edad_anios_meses = "";
			this->cuidado_intensivo = "";
			this->fecha_cui_intensivo = "";
			this->fallecido = "";
			this->carga_provincia_id = 0;
			this->clasificacion_resumen = "";
		};
		void toString(){
		    cout<<"| "<<this->id <<" | "<<this->edad <<" | "<<this->edad_anios_meses <<" | "<<this->cuidado_intensivo
		    <<" | "<<this->fecha_cui_intensivo <<" | "<<this->fallecido <<" | "<<this->carga_provincia_id <<" | "
		    <<this->clasificacion_resumen <<" | \n";
		};
};

#endif //INC_2_PARCIAL_CASO_H