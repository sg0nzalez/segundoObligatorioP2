#include "abb_de_pacientes.h"
#include "lista_de_consultas.h"
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
    abb_de_pacientes abb_pacientes = NULL;
    lista_de_consultas lista_consultas = NULL;

    if (existe_archivo(ARCHIVO_PACIENTES) == FALSE)
        bajar_abb(abb_pacientes);

    if (existe_archivo(ARCHIVO_CONSULTAS) == FALSE)
        bajar_lista_consulta(lista_consultas);

    levantar_abb(abb_pacientes);
    levantar_lista_consulta(lista_consultas);

    boolean cerrar_menu = FALSE;

    while (cerrar_menu == FALSE)
        menu_principal(abb_pacientes, lista_consultas, cerrar_menu);
}
