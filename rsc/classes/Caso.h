#ifndef INC_2_PARCIAL_CASO_H
#define INC_2_PARCIAL_CASO_H
#include "cstring"

using namespace std;

/* Estructura para una muestra */
class Caso{
private:
		int id;
		int edad;
		string edad_anios_meses;
		string cuidado_intensivo;
		int fecha_cui_intensivo;
		string fallecido;
		string provincia;
		string clasificacion_resumen;
public:
		Caso(){
			this->id = 0;
			this->edad = 0;
			this->edad_anios_meses = "";
			this->cuidado_intensivo = "";
			this->fecha_cui_intensivo = 0;
			this->fallecido = "";
			this->provincia = "";
			this->clasificacion_resumen = "";
		};
		void setID(int i){
		    this->id = i;
		}
        void setEdad(int e){
                this->edad = e;
        }
        void setEdadAniosMeses(string eam){
                this->edad_anios_meses = eam;
        }
        void setCuiIntensivo(string cui){
                this->cuidado_intensivo = cui;
        }
        void setFechaCuiIntensivo(int fci){
                this->fecha_cui_intensivo = fci;
        }
        void setFallecido(string fa){
                this->fallecido = fa;
        }
        void setProvincia(string p){
                this->provincia = p;
        }
        void setClasifResumen(string cr){
                this->clasificacion_resumen = cr;
        }
        int getID(){
		    return this->id;
		}
        int getEdad(){
		    return this->edad;
        }
        string getEdadAniosMeses(){
		    return this->edad_anios_meses;
        }
        string getCuiIntensivo(){
		    return this->cuidado_intensivo;
        }
        int getFechaCuiIntensivo(){
		    return this->fecha_cui_intensivo;
        }
        string getFallecido(){
		    return this->fallecido;
        }
        string getProvincia(){
		    return this->provincia;
        }
        string getClasifResumen(){
		    return this->clasificacion_resumen;
        }
        void toString(){
		    cout<<"| "<<this->id <<" | "<<this->edad <<" | "<<this->edad_anios_meses <<" | "<<this->cuidado_intensivo
		    <<" | "<<this->fecha_cui_intensivo <<" | "<<this->fallecido <<" | "<<this->provincia <<" | "
		    <<this->clasificacion_resumen <<" | \n";
		};
};

#endif //INC_2_PARCIAL_CASO_H