#ifndef CONSULTA_H_INCLUDED
#define CONSULTA_H_INCLUDED

#include "evaluacion.h"
#include "fecha.h"
#include "string.h"

typedef struct {
    fecha realizacion;
    string descripcion;
    long cedula_paciente;
    evaluacion evaluacion_paciente;
} consulta;

void ingresar_consulta(consulta &nueva_consulta);

void mostrar_consulta(consulta consulta_a_mostrar);

evaluacion dar_evaluacion(consulta c);



#endif // CONSULTA_H_INCLUDED
