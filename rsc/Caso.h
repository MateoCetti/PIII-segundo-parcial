#ifndef INC_2_PARCIAL_CASO_H
#define INC_2_PARCIAL_CASO_H
#include "string.h"

using namespace std;

class Caso{
	public: 
		int id;
		int edad;
		string edad_anios_meses;
		bool cuidado_intensivo;
		int fecha_cui_intensivo;
		bool fallecido;
		int carga_provincia_id;
		string clasificacion_resumen;

		Caso(){
			this->id = 0;
			this->edad = 0;
			this->edad_anios_meses = "";
			this->cuidado_intensivo = 0;
			this->fecha_cui_intensivo = 0;
			this->fallecido = 0;
			this->carga_provincia_id = 0;
			this->clasificacion_resumen = "";
		};

		Caso(int id, int edad, 
			string edad_anios_meses, 
			bool cuidado_intensivo, 
			int fecha_cui_intensivo,
			bool fallecido,
			int carga_provincia_id,
			string clasificacion_resumen);
		
};

Caso::Caso(int id, int edad, 
		string edad_anios_meses, 
		bool cuidado_intensivo, 
		int fecha_cui_intensivo,
		bool fallecido,
		int carga_provincia_id,
		string clasificacion_resumen){
			this->id = id;
			this->edad = edad;
			this->edad_anios_meses = edad_anios_meses;
			this->cuidado_intensivo = cuidado_intensivo;
			this->fecha_cui_intensivo = fecha_cui_intensivo;
			this->fallecido = fallecido;
			this->carga_provincia_id = carga_provincia_id;
			this->clasificacion_resumen = clasificacion_resumen;
		};

#endif //INC_2_PARCIAL_CASO_H