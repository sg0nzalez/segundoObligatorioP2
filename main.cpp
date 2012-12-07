#include "abb_de_pacientes.h"
#include "lista_de_consultas.h"

int main()
{
    abb_de_pacientes abb_pacientes = NULL;

    /**for(int i = 0; i < 2; i++)
    {
        paciente nuevo_paciente;

        ingresar_paciente(nuevo_paciente);

        abb_insertar_paciente(abb_pacientes, nuevo_paciente);
    }

    printf("Mostrar todos los pacientes ordenados: \n\n");
    abb_mostrar_pacientes(abb_pacientes);**/

    lista_de_consultas lista_consultas = NULL;

    for(int i = 0; i < 2; i++)
    {
        consulta nueva_consulta;

        ingresar_consulta(nueva_consulta);

        lista_insertar_consulta(lista_consultas, nueva_consulta);
    }

    printf("Mostrar todas las consultas: \n\n");
    lista_mostrar_consultas(lista_consultas);

    printf("Consultas por evaluacion: \n");
    consultas_por_evaluacion(lista_consultas, SALUDABLE);
/*
    fecha fec_pertenece;
    fecha fec_inicio;
    fecha fec_fin;

    printf("Ingrese la fecha a buscar: \n");
    cargar_fecha(fec_pertenece);

    printf("Ingrese la fecha de inicio: \n");
    cargar_fecha(fec_inicio);

    printf("Ingrese la fecha de fin: \n");
    cargar_fecha(fec_fin);

    boolean pertenece = fecha_pertenece_al_rango(fec_pertenece, fec_inicio, fec_fin);

    if(pertenece==TRUE){
        printf("PERTENECE");
    } else {
        printf("NO PERTENECE");
    }
*/
}
