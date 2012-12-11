#include "abb_de_pacientes.h"
#include "lista_de_consultas.h"

void sub_menu_de_consultas(abb_de_pacientes &abb_pacientes, lista_de_consultas &lista_consultas, boolean &cerrar_menu)
{
    int opcion_ingresada;

    printf("\nOpciones:\n");
    printf("\n\t1)- Consultas mayores a una fecha");
    printf("\n\t2)- Cantidad consultas de cada tipo");
    printf("\n\t3)- Salir");

    printf("\n\nIngrese la opcion deseada: ");
    scanf("%d", &opcion_ingresada);

    switch (opcion_ingresada)
    {
        case 1:
        {
            fecha fecha_a_consultar;
            cargar_fecha(fecha_a_consultar);

            int cantidad_consultas = contar_consultas_despues_de_fecha(lista_consultas, fecha_a_consultar);

            printf("\nHay %d consultas luego del ", cantidad_consultas);
            mostrar_fecha(fecha_a_consultar);
            printf("\n");
            break;
        }
        case 2:
            cantidad_consultas_de_cada_tipo(lista_consultas);
            break;
        case 3:
            cerrar_menu = TRUE;
            break;
    }
}

void sub_menu_de_pacientes(abb_de_pacientes &abb_pacientes, lista_de_consultas &lista_consultas, boolean &cerrar_menu)
{
    int opcion_ingresada;

    printf("\nOpciones:\n");
    printf("\n\t1)- Lista de todos los pacientes");
    printf("\n\t2)- Buscar Pacientes por apellido");
    printf("\n\t4)- Cedula paciente con mas consultas");
    printf("\n\t5)- Pacientes con mayor y menor cantidad de consultas");
    printf("\n\t6)- Salir");

    printf("\n\nIngrese la opcion deseada: ");
    scanf("%d", &opcion_ingresada);

    switch (opcion_ingresada)
    {
        case 1:
            printf("\nPacientes: \n\n");

            abb_mostrar_pacientes(abb_pacientes);
            break;
        case 2:
        {
            string apellido_a_buscar;
            int cantidad_pacientes;

            getchar();

            printf("\n\tApellido: ");
            cargar_string(apellido_a_buscar);

            cantidad_pacientes = cantidad_pacientes_por_apellido(abb_pacientes, apellido_a_buscar);

            printf("\n\tHay %d pacientes de apellido ", cantidad_pacientes);
            desplegar_string(apellido_a_buscar);
            printf("\n");
            break;
        }
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:
            cerrar_menu = TRUE;
            break;
    }
}

void menu_principal(abb_de_pacientes &abb_pacientes, lista_de_consultas &lista_consultas, boolean &cerrar_menu)
{
    int opcion_ingresada;

    printf("\nOpciones:\n");
    printf("\n\t1)- Ingrese un Paciente");
    printf("\n\t2)- Ingrese una Consulta");
    printf("\n\t3)- SubMenu de Consultas");
    printf("\n\t4)- SubMenu de Pacientes");
    printf("\n\t5)- Salir");

    printf("\n\nIngrese la opcion deseada: ");
    scanf("%d", &opcion_ingresada);

    switch (opcion_ingresada)
    {
        case 1:
            paciente nuevo_paciente;

            ingresar_paciente(nuevo_paciente);

            abb_insertar_paciente(abb_pacientes, nuevo_paciente);
            break;
        case 2:
            consulta nueva_consulta;

            ingresar_consulta(nueva_consulta);

            lista_insertar_consulta(lista_consultas, nueva_consulta);
            break;
        case 3:
            while (cerrar_menu == FALSE)
                sub_menu_de_consultas(abb_pacientes, lista_consultas, cerrar_menu);

            cerrar_menu = FALSE;
            break;
        case 4:
            while (cerrar_menu == FALSE)
                sub_menu_de_pacientes(abb_pacientes, lista_consultas, cerrar_menu);

            cerrar_menu = FALSE;
            break;
        case 5:
            cerrar_menu = TRUE;
            break;
    }
}

int main()
{
    // FALTA CARGAR LOS DATOS DE UN ARCHIVO PREVIAMENTE CARGADO
    abb_de_pacientes abb_pacientes = NULL;
    lista_de_consultas lista_consultas = NULL;

    boolean cerrar_menu = FALSE;

    while (cerrar_menu == FALSE)
        menu_principal(abb_pacientes, lista_consultas, cerrar_menu);




   /*
    abb_de_pacientes abb_pacientes = NULL;

    for(int i = 0; i < 1; i++)
    {
        paciente nuevo_paciente;

        ingresar_paciente(nuevo_paciente);

        abb_insertar_paciente(abb_pacientes, nuevo_paciente);
    }

    printf("Mostrar todos los pacientes ordenados: \n\n");
    abb_mostrar_pacientes(abb_pacientes);

    lista_de_consultas lista_consultas = NULL;

    for(int i = 0; i < 3; i++)
    {
        consulta nueva_consulta;

        ingresar_consulta(nueva_consulta);

        lista_insertar_consulta(lista_consultas, nueva_consulta);
    }

    printf("%ld", cedula_paciente_con_mas_consultas(lista_consultas));

    long cedula;

    printf("Ingrese una cedula para mostrar las consultas: ");
    scanf("%ld", &cedula);

    consultas_por_cedula(lista_consultas, cedula);

/*
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

paciente paciente_menor_cedula;
paciente paciente_mayor_cedula;

paciente_menor_y_mayor_cedula(abb_pacientes, paciente_menor_cedula, paciente_mayor_cedula);

printf("\nPaciente menor cedula:\n");
mostrar_paciente(paciente_menor_cedula);
printf("\nPaciente mayor cedula:\n");
mostrar_paciente(paciente_mayor_cedula);*/
}
