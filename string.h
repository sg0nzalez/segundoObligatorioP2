#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "boolean.h"

// String

const int LARGO_STRING = 80;

typedef char string[LARGO_STRING];

// Metodos

//Carga string
void cargar_string(string &texto);

//Muestra en pantalla el string
void desplegar_string(string texto);

//Copia un string en otro
void copiar_string(string texto, string &texto2);

//Comparar dos strings si son iguales
boolean comparar_2_strings(string s1,string s2);

#endif // STRING_H_INCLUDED
