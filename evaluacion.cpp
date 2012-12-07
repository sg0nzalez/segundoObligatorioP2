#include <stdio.h>
#include "evaluacion.h"

void cargar_evaluacion(evaluacion &evaluacion_a_cargar)
{
    int numero;

    printf("\nSaludable: 0, En Tratamiento: 1, Necesita Protesis: 2\n");
    scanf("%d", &numero);

    evaluacion_a_cargar = evaluacion(numero);
}

void mostrar_evaluacion(evaluacion evaluacion_a_mostrar)
{
    switch (evaluacion_a_mostrar)
    {
        case 0:
            printf("Saludable");
            break;
        case 1:
            printf("En tratamiento");
            break;
        case 2:
            printf("Necesita protesis");
            break;
    }
}
