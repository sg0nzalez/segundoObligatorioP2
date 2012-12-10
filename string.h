#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "boolean.h"

// String

const int LARGO_STRING = 80;
typedef char *string;

// Metodos

//Carga string
void cargar_string(string &texto);

//Muestra en pantalla el string
void desplegar_string(string texto);

//Copia un string en otro
void copiar_string(string &s1, string s2);

void crear_string(string & s);

void destruir_string(string &s);

int largo_string(string s);

//Comparar dos strings si son iguales
boolean comparar_2_strings(string s1,string s2);

#endif // STRING_H_INCLUDED
