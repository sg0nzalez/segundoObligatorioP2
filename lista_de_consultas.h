#ifndef LISTA_DE_CONSULTAS_H_INCLUDED
#define LISTA_DE_CONSULTAS_H_INCLUDED

#include "consulta.h"

// Lista

typedef struct _nodo_consulta {
    consulta info;
    _nodo_consulta *sig;
} nodo_consulta;

typedef nodo_consulta *lista_de_consultas;

// Metodos

void crear_lista(lista_de_consultas &lista);

void lista_insertar_consulta(lista_de_consultas &lista, consulta info);

void lista_mostrar_consultas(lista_de_consultas lista);

boolean lista_es_vacia(lista_de_consultas lista);

consulta lista_primer_consulta(lista_de_consultas lista);

void mostrar_consultas_entre_2_fechas(lista_de_consultas lista, fecha fecha_inicio, fecha fecha_fin);

void consultas_por_evaluacion(lista_de_consultas lista, evaluacion evaluacion_a_buscar);

int contar_consultas_despues_de_fecha(lista_de_consultas lista, fecha fecha_despues);

void consultas_por_cedula(lista_de_consultas lista, long cedula);

int cantidad_consultas_por_cedula(lista_de_consultas lista, long cedula);

int cantidad_consultas_por_evaluacion(lista_de_consultas lista, evaluacion evaluacion_a_buscar);

#endif // LISTA_DE_CONSULTAS_H_INCLUDED
