# Ejemplo de TAD

## Que es un TAD (aka ADT)?

Actualmente, para muchos desarrolladores, existen lenguajes de programacion orientados a objetos en el que existen abstracciones (clases, objetos, herencia) que permiten ocultar los detalles de implementacion al usuario. Desgraciadamente en la cursada al ver C, que es un lenguaje procedural, sin soporte del paradigma de objetos, no tenemos estas caracteristicas ni abstracciones. 

Sin embargo existen algo conocido como Tipos abstractos de datos (TADs o mas bien ADTs en ingles (Abstract data types)), que son tipos de datos cuyos detalles de implementación están ocultos a la vista del usuario para la estructura de datos.

En este pequeño abstracto vamos a ver un poco como crear un ADT simple, de una estructura de datos que nos puede ayudar para construir otras cosas, y que nos de algunas funciones que nos permitan utilizar dicha estructura de manera facil, sin tener que preocuparse por los pormenores de dicha estructura.

## Ejemplo: Stack

Vamos a ver el caso simple de crear una pila como TAD, antes que nada vamos a definir en el `stack.h` la estructura y las funciones que expondremos para que 

