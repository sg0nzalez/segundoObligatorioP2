#include "abb_de_pacientes.h"
#include "lista_de_consultas.h"

int main()
{
    abb_de_pacientes abb_pacientes = NULL;

    for(int i = 0; i < 4; i++)
    {
        paciente nuevo_paciente;

        ingresar_paciente(nuevo_paciente);

        abb_insertar_paciente(abb_pacientes, nuevo_paciente);
    }

    printf("Mostrar todos los pacientes ordenados: \n\n");
    abb_mostrar_pacientes(abb_pacientes);
/*
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

    fecha fec_pertenece;
    fecha fec_inicio;
    fecha fec_fin;
    fecha fec_despues;
*/
//   printf("Ingrese la fecha a buscar: \n");
//    cargar_fecha(fec_pertenece);
/*
    printf("Ingrese la fecha de inicio: \n");
    cargar_fecha(fec_inicio);

    printf("Ingrese la fecha de fin: \n");
    cargar_fecha(fec_fin);

    boolean pertenece = fecha_pertenece_al_rango(fec_pertenece, fec_inicio, fec_fin);

    if(pertenece){
        printf("PERTENECE");
    } else {
        printf("NO PERTENECE");
    }
 */

/*
    printf("\nConsultas realizadas en el periodo ");
    printf("del ");
    mostrar_fecha(fec_inicio);
    printf(" al ");
    mostrar_fecha(fec_fin);
    printf("\n\n");
    mostrar_consultas_entre_2_fechas(lista_consultas, fec_inicio, fec_fin);
*/
/*
printf("Ingrese la fecha para contar las consultas posteriores a la misma: \n");
cargar_fecha(fec_despues);
int contador_consultas;
contador_consultas = contar_consultas_despues_de_fecha(lista_consultas, fec_despues);
printf("Cantidad de consultas = %d", contador_consultas);
*/
paciente paciente_menor_cedula;
paciente paciente_mayor_cedula;

paciente_menor_y_mayor_cedula(abb_pacientes, paciente_menor_cedula, paciente_mayor_cedula);

printf("\nPaciente menor cedula:\n");
mostrar_paciente(paciente_menor_cedula);
printf("\nPaciente mayor cedula:\n");
mostrar_paciente(paciente_mayor_cedula);
}
