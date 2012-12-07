#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED

#include "string.h"

typedef struct {
    long cedula;
    string nombre;
    string apellido;
    string domicilio;
    int telefono;
} paciente;

long darCedula(paciente info);

void ingresar_paciente(paciente &nuevo_paciente);

void mostrar_paciente(paciente paciente_a_mostrar);

#endif // PACIENTE_H_INCLUDED
