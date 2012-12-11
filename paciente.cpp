#include "paciente.h"

long darCedula(paciente info)
{
    return info.cedula;
}

void dar_apellido(paciente info, string &apellido)
{
    copiar_string(apellido, info.apellido);
}

void dar_nombre(paciente info, string &nombre)
{
    copiar_string(nombre, info.nombre);
}

void ingresar_paciente(paciente &nuevo_paciente)
{
    printf("\nIngrese los datos del nuevo paciente:");
    printf("\n\tCedula: ");
    scanf("%ld", &nuevo_paciente.cedula);

    getchar();

    printf("\tNombre: ");
    cargar_string(nuevo_paciente.nombre);

    printf("\tApellido: ");
    cargar_string(nuevo_paciente.apellido);

    printf("\tDomicilio: ");
    cargar_string(nuevo_paciente.domicilio);

    printf("\tTelefono: ");
    scanf("%d", &nuevo_paciente.telefono);
}

void mostrar_paciente(paciente paciente_a_mostrar)
{
    printf("\t[Cedula: %ld | ", paciente_a_mostrar.cedula);

    printf("Nombre: ");
    desplegar_string(paciente_a_mostrar.nombre);

    printf(" | Apellido: ");
    desplegar_string(paciente_a_mostrar.apellido);

    printf(" | Domicilio: ");
    desplegar_string(paciente_a_mostrar.domicilio);

    printf(" | Telefono: %d] \n", paciente_a_mostrar.telefono);
}
