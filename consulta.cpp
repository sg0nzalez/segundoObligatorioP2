#include "consulta.h"

void ingresar_consulta(consulta &nueva_consulta)
{
    printf("Ingrese una nueva consulta:\n");

    printf("\tFecha: ");
    cargar_fecha(nueva_consulta.realizacion);

    getchar();

    printf("\tDescripcion: ");
    cargar_string(nueva_consulta.descripcion);

    printf("\tCedula Paciente: ");
    scanf("%ld", &nueva_consulta.cedula_paciente);

    printf("\tEvaluacion: ");
    cargar_evaluacion(nueva_consulta.evaluacion_paciente);
}

void mostrar_consulta(consulta consulta_a_mostrar)
{
    printf("\tFecha: ");
    mostrar_fecha(consulta_a_mostrar.realizacion);

    printf("\n\tDescripcion: ");
    desplegar_string(consulta_a_mostrar.descripcion);

    printf("\n\tCedula paciente: ");
    printf("%ld", consulta_a_mostrar.cedula_paciente);

    printf("\n\tEvaluacion: ");
    mostrar_evaluacion(consulta_a_mostrar.evaluacion_paciente);

    printf("\n\n");
}

evaluacion dar_evaluacion(consulta c)
{
   return c.evaluacion_paciente;
}

long dar_cedula(consulta c)
{
    return c.cedula_paciente;
}
