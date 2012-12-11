#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include "abb_de_pacientes.h"
#include "lista_de_consultas.h"

//controlar que exista
boolean Existe_archivo (string nomArch);

//Escribir string en Archivo
void Bajar_String (string s, FILE * f);

//Cargar string en Archivo
void Levantar_String (string &s, FILE * f);

//Escribe paciente en Archivo
void Bajar_Paciente (paciente p, FILE * f );

//Lee paciente del Archivo
void Levantar_Paciente (paciente &p, FILE * f );

//Abre el archivo y llama a la funcion que Baja el ABB a un archivo y luego lo cierra
void Bajar_ABB (abb_de_pacientes a);

//Baja el archivo
void Bajar_ABB_Aux (abb_de_pacientes a, FILE * f);

void Levantar_ABB (abb_de_pacientes &a);

// escribe fecha en archivo
void bajar_fecha(fecha fe,FILE *f);

// lee fecha en un archivo
void levantar_fecha(fecha fe,FILE *f);

//Escribe consulta en Archivo
void Bajar_consulta (consulta c, FILE * f );

//Leeconsulta del Archivo
void Levantar_consulta (consulta &c, FILE * f );

/*//Baja el archivo
void Bajar_lista_consula_Aux (lista_consulta l, FILE * f)
{



if (l != NULL)
{
Bajar_consulta(l->info_consulta,f);
Bajar_lista_consula_Aux(l->sig_consulta,f);
}
}
//Abre el archivo y llama a la funcion que Baja la lista de consultas a un archivo y luego lo cierra
void Bajar_lista_consulta (lista_consulta l)
{
FILE * f = fopen ("d:\\consulta.txt","wb");
Bajar_lista_consula_Aux(l, f);
fclose(f);
}*/
//Abre el archivo y llama a la funcion que Baja la lista de consultas a un archivo y luego lo cierra
void Bajar_lista_consulta (lista_de_consultas l);

// levantar archivo lista de consultas
void Levantar_lista_consulta (lista_de_consultas &l);

#endif // ARCHIVOS_H_INCLUDED
