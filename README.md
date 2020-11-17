<p align="center">

  <h3 align="center">Programacion III - Parcial 2</h3>

  <p align="center">
    Este es el proyecto de la materia Programacion III, para el Segundo Parcial de la misma, desarrollado por los alumnos Antonel Gino y Cetti Mateo. A continuacion, mostraremos un breve resumen acerca de la informacion que consideramos mas relevante del proyecto.
    <br />
  </p>
</p>



<!-- Indice -->
## Indice

* [Acerca del proyecto](#acerca-del-proyecto)
  * [Desarrollado con](#desarrollado-con)
* [Primeros Pasos](#primeros-pasos)
  * [Requisitos previos](#requisitos-previos)
  * [Instalacion](#instalacion)
* [Uso](#uso)
* [Contactanos](#contactanos)




<!-- Acerca del proyecto -->
## Acerca del proyecto

Debido al caso de pandemia del año 2020, deseamos hacer un visualizador de datos de los casos
de Argentina. Para esto se quiere poder mostrar datos ordenados y agrupados en distintas categorías.
Como así también hacer un procesado simple de los datos y mostrar alguna información extra


### Desarrollado con

* [C++](http://www.cplusplus.com/)



<!-- Primeros Pasos -->
## Primeros Pasos

Aqui se mostraran unas pequeñas instrucciones acerca de como obtener una copia local del repositorio y poder correrla (en Linux).


### Requisitos previos

El requisito previo esencial para el buen funcionamiento del codigo es tener el archivo Covid19Casos.CSV brindado por el el Ministerio de salud de la Argentina, el cual se puede obtener [aqui](http://datos.salud.gob.ar/dataset/covid-19-casos-registrados-en-la-republica-argentina)

### Instalacion

1. Clonar el repositorio
```sh
git clone https://github.com/MateoCetti/PIII-segundo-parcial.git
```
2. mover el archivo Covid19Casos.CSV al directorio del proyecto
```sh
mv Covid19Casos.CSV ./PIII-segundo-parcial/
```
3. moverse al directorio del proyecto
```sh
cd PIII-segundo-parcial/
```
4. compilar el codigo
```sh
g++ *.cpp *.h -o covid19
```

<!-- Uso -->
## Uso
Para un correcto uso del comando, se deberán seguir las siguientes indicaciones. Primero, suponemos que el codigo ya esta correctamente compilado y este se llama “covid19”. Luego, podemos introducir por consola el siguiente comando, siempre y cuando estemos en el directorio del proyecto:

```sh
covid19 [argumentos] [Base de datos]
```

Cabe destacar que la base de datos debera estar en el mismo directorio
 que el proyecto. Los argumentos que se aceptan son los siguientes:

Argumentos | Devuelve
------------ | -------------
-estad | Cantidad total de muestras,<br/> Cantidad total de infectados, Cantidad de fallecidos, <br/> % de infectado por muestras, % de fallecidos por infectados, <br/> Cantidad de infectados por rango etario ( rango de 10 años), <br/> Cantidad de muertes por rango etario ( rango de 10 años)
-p_casos [n] | Mostrará las n primeras provincias con más contagios ordenadas de más a menos. Si n no es pasado, se mostrarán todas las provincias.
-p_muertes [n] | Mostrará las n provincias con más muertes ordenadas de más a menos. Si n no es pasado, se mostrarán todas las provincias.
-casos_edad[años] | Mostrará los datos de los casos donde la edad sea ‘años’ (ordenados por nombre de provincia).
-casos_cui [fecha] | Mostrará los datos de los casos que estuvieron en cuidados intensivos ordenados por fecha de cuidados intensivos, si fecha está indicada, se mostrarán solo las fechas mayores a esta.
***

Para mas informacion, visita la 
[Documentacion](https://docs.google.com/document/d/1CxsKLt2K9ZAEqB5bbsYQTNhIOhaODKXgXaw-z-IXA4k/edit?usp=sharing).


<!-- Contactanos -->
## Contactanos

Gino Antonel - [Cuenta de github](https://github.com/GinoAntonel) - ginoantonel.ga@gmail.com

Mateo Cetti - [Cuenta de github](https://github.com/MateoCetti) - mateocetti2000@gmail.com

Link del proyecto: [https://github.com/MateoCetti/PIII-segundo-parcial](https://github.com/MateoCetti/PIII-segundo-parcial)



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/github_username/repo.svg?style=flat-square
[contributors-url]: https://github.com/github_username/repo/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/github_username/repo.svg?style=flat-square
[forks-url]: https://github.com/github_username/repo/network/members
[stars-shield]: https://img.shields.io/github/stars/github_username/repo.svg?style=flat-square
[stars-url]: https://github.com/github_username/repo/stargazers
[issues-shield]: https://img.shields.io/github/issues/github_username/repo.svg?style=flat-square
[issues-url]: https://github.com/github_username/repo/issues
[license-shield]: https://img.shields.io/github/license/github_username/repo.svg?style=flat-square
[license-url]: https://github.com/github_username/repo/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=flat-square&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/github_username
[product-screenshot]: images/screenshot.png