#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include<stdio.h>
#include "string.h"

typedef struct {
    int dia;
    int mes;
    int anio;
} fecha;

void cargar_fecha(fecha &fec);

void mostrar_fecha(fecha fec);

int dar_dia(fecha fec);
int dar_mes(fecha fec);
int dar_anio(fecha fec);

boolean fecha_valida(fecha fec);

boolean fecha_pertenece_al_rango(fecha fecha_pertenece, fecha inicial, fecha fin);

boolean fecha_es_mayor(fecha fecha_info, fecha fecha_despues);
#endif // FECHA_H_INCLUDED
