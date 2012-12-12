#include "archivos.h"

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
            lista_mostrar_consultas(lista_consultas);
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
    printf("\n\t3)- Cedula paciente con mas consultas");
    printf("\n\t4)- Pacientes con mayor y menor cantidad de consultas");
    printf("\n\t5)- Salir");

    printf("\n\nIngrese la opcion deseada: ");
    scanf("%d", &opcion_ingresada);

    switch (opcion_ingresada)
    {
        case 1:
            printf("\nPacientes: \n\n");

            if (abb_es_vacio(abb_pacientes) == FALSE)
            {
                abb_mostrar_pacientes(abb_pacientes);
            }
            else
            {
                printf("\tNo hay pacientes para mostrar\n");
            }

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
        {
            if (lista_es_vacia(lista_consultas) == FALSE)
            {
                long ci_paciente = cedula_paciente_con_mas_consultas(lista_consultas);

                printf("\n\tEl paciente con mas consultas es %ld\n", ci_paciente);
            }
            else
            {
                printf("\n\tNo hay consultas para buscar\n");
            }
            break;
        }
        case 4:
            if (abb_es_vacio(abb_pacientes) == FALSE)
            {
                paciente menor_paciente;
                paciente mayor_paciente;

                paciente_menor_y_mayor_cedula(abb_pacientes, menor_paciente, mayor_paciente);

                printf("\n\tEl paciente menor es:\n");
                mostrar_paciente(menor_paciente);
                printf("\n\tEl paciente mayor es:\n");
                mostrar_paciente(mayor_paciente);
                printf("\n");
            }
            else
            {
                printf("\n\tNo hay pacientes para mostrar\n");
            }

            break;
        case 5:
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
        {
            paciente nuevo_paciente;

            ingresar_paciente(nuevo_paciente);

            abb_insertar_paciente(abb_pacientes, nuevo_paciente);

            bajar_abb(abb_pacientes);
            break;
        }
        case 2:
        {
            consulta nueva_consulta;

            ingresar_consulta(nueva_consulta);

            lista_insertar_consulta(lista_consultas, nueva_consulta);

            bajar_lista_consulta(lista_consultas);
            break;
        }
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
    printf("UNO");
    abb_de_pacientes abb_pacientes = NULL;
    lista_de_consultas lista_consultas = NULL;

    if (existe_archivo(ARCHIVO_PACIENTES) == FALSE)
        bajar_abb(abb_pacientes);

    printf("DOS");

    if (existe_archivo(ARCHIVO_CONSULTAS) == FALSE)
        bajar_lista_consulta(lista_consultas);

    printf("TRES");

    levantar_abb(abb_pacientes);

    printf("CUATRO");

    levantar_lista_consulta(lista_consultas);

    printf("CINCO");

    boolean cerrar_menu = FALSE;

    while (cerrar_menu == FALSE)
        menu_principal(abb_pacientes, lista_consultas, cerrar_menu);

/*
//USADO PARA TESTING

    //USADO PARA PROBAR EL INGRESO Y EL LISTADO DE PACIENTES
    abb_de_pacientes abb_pacientes = NULL;

    for(int i = 0; i < 1; i++)
    {
        paciente nuevo_paciente;

        ingresar_paciente(nuevo_paciente);

        abb_insertar_paciente(abb_pacientes, nuevo_paciente);
    }

    printf("Mostrar todos los pacientes ordenados: \n\n");
    abb_mostrar_pacientes(abb_pacientes);

    //USADO PARA PROBAR EL INGRESO DE CONSULTAS
    lista_de_consultas lista_consultas = NULL;

    for(int i = 0; i < 3; i++)
    {
        consulta nueva_consulta;

        ingresar_consulta(nueva_consulta);

        lista_insertar_consulta(lista_consultas, nueva_consulta);
    }

    //USADO PARA CORROBAR EL PACIENTE CON MAYOR CONSULTAS
    printf("%ld", cedula_paciente_con_mas_consultas(lista_consultas));

    long cedula;

    //USADO PARA MOSTRAR LAS CONSULTAS POR CEDULA
    printf("Ingrese una cedula para mostrar las consultas: ");
    scanf("%ld", &cedula);

    consultas_por_cedula(lista_consultas, cedula);

    //USADO PARA PROBAR EL MOSTRAR TODAS LAS CONSULTAS
    printf("Mostrar todas las consultas: \n\n");
    lista_mostrar_consultas(lista_consultas);

    //USADO PROBAR EL MOSTRAR TODAS LAS CONSULTAS POR EVALUACION
    printf("Consultas por evaluacion: \n");
    consultas_por_evaluacion(lista_consultas, SALUDABLE);

    //USADO PARA PROBAR EL CARGAR FECHA
    fecha fec_pertenece;
    fecha fec_inicio;
    fecha fec_fin;
    fecha fec_despues;


    printf("Ingrese la fecha a buscar: \n");
    cargar_fecha(fec_pertenece);

    printf("Ingrese la fecha de inicio: \n");
    cargar_fecha(fec_inicio);

    printf("Ingrese la fecha de fin: \n");
    cargar_fecha(fec_fin);

    //USADO PARA PROBAR SI UNA FECHA PERTENECE A UN RANGO DE FECHAS
    boolean pertenece = fecha_pertenece_al_rango(fec_pertenece, fec_inicio, fec_fin);

    if(pertenece){
        printf("PERTENECE");
    } else {
        printf("NO PERTENECE");
    }

    //USADO PARA PROBAR EL MOSTRAR LAS CONSULTAS ENTRE 2 FECHAS
    printf("\nConsultas realizadas en el periodo ");
    printf("del ");
    mostrar_fecha(fec_inicio);
    printf(" al ");
    mostrar_fecha(fec_fin);
    printf("\n\n");
    mostrar_consultas_entre_2_fechas(lista_consultas, fec_inicio, fec_fin);

    //USADO PARA PROBAR LA CUENTA DE CONSULTAS POSTERIORES A UNA FECHA
    printf("Ingrese la fecha para contar las consultas posteriores a la misma: \n");
    cargar_fecha(fec_despues);
    int contador_consultas;
    contador_consultas = contar_consultas_despues_de_fecha(lista_consultas, fec_despues);
    printf("Cantidad de consultas = %d", contador_consultas);

    //USADO PARA PROBAR QUE LOS PACIENTES CON MENOR Y MAYOR CEDULA SON DEVEULTOS CORRECTAMENTE
    paciente paciente_menor_cedula;
    paciente paciente_mayor_cedula;

    paciente_menor_y_mayor_cedula(abb_pacientes, paciente_menor_cedula, paciente_mayor_cedula);

    printf("\nPaciente menor cedula:\n");
    mostrar_paciente(paciente_menor_cedula);
    printf("\nPaciente mayor cedula:\n");
    mostrar_paciente(paciente_mayor_cedula);
*/
}
