#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include "abb_de_pacientes.h"
#include "lista_de_consultas.h"

const string ARCHIVO_PACIENTES = "/Users/sandant/Desktop/pacientes.txt";
const string ARCHIVO_CONSULTAS = "/Users/sandant/Desktop/consultas.txt";

//const string ARCHIVO_PACIENTES = "d:\\pacientes.txt";
//const string ARCHIVO_CONSULTAS = "d:\\consultas.txt";


boolean existe_archivo(string nomArch);

void bajar_string(string s, FILE * f);

void levantar_string(string &s, FILE * f);

// PROCEDIMIENTOS RELACIONADOS AL ABB DE PACIENTES
void bajar_paciente(paciente p, FILE *f);

void levantar_paciente(paciente &p, FILE * f );

void bajar_abb(abb_de_pacientes a);

void bajar_abb_aux(abb_de_pacientes a, FILE * f);

void levantar_abb(abb_de_pacientes &a);

// PROCEDIMIENTOS RELACIONADOS A LA LISTA DE CONSULTAS
void bajar_fecha(fecha fe,FILE *f);

void levantar_fecha(fecha fe,FILE *f);

void bajar_consulta(consulta c, FILE * f );

void levantar_consulta(consulta &c, FILE * f );

void bajar_lista_consulta(lista_de_consultas l);

void levantar_lista_consulta(lista_de_consultas &l);

#endif // ARCHIVOS_H_INCLUDED
