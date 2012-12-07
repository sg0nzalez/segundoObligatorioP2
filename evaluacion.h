#ifndef EVALUACION_H_INCLUDED
#define EVALUACION_H_INCLUDED

typedef enum { SALUDABLE, EN_TRATAMIENTO, NECESITA_PROTESIS } evaluacion;

void cargar_evaluacion(evaluacion &evaluacion_a_cargar);

void mostrar_evaluacion(evaluacion evaluacion_a_mostrar);

#endif // EVALUACION_H_INCLUDED
