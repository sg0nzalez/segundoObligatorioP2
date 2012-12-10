#include "paciente.h"

long darCedula(paciente info)
{
    return info.cedula;
}

void dar_apellido(paciente info, string &apellido) {
    copiar_string(apellido, info.apellido);
}

void ingresar_paciente(paciente &nuevo_paciente)
{
    printf("Ingrese un nuevo paciente:\n");

    printf("Cedula: ");
    scanf("%ld", &nuevo_paciente.cedula);

    getchar();

    printf("Nombre: ");
    cargar_string(nuevo_paciente.nombre);

    printf("Apellido: ");
    cargar_string(nuevo_paciente.apellido);

    printf("Domicilio: ");
    cargar_string(nuevo_paciente.domicilio);

    printf("Telefono: ");
    scanf("%d", &nuevo_paciente.telefono);
}

void mostrar_paciente(paciente paciente_a_mostrar)
{
    printf("\tMostrar paciente:\n");

    printf("\tCedula: %ld\n", paciente_a_mostrar.cedula);

    printf("\tNombre: ");
    desplegar_string(paciente_a_mostrar.nombre);
    printf("\n");

    printf("\tApellido: ");
    desplegar_string(paciente_a_mostrar.apellido);
    printf("\n");

    printf("\tDomicilio: ");
    desplegar_string(paciente_a_mostrar.domicilio);
    printf("\n");

    printf("\tTelefono: %d \n\n", paciente_a_mostrar.telefono);
}
