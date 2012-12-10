#ifndef ABB_DE_PACIENTES_H_INCLUDED
#define ABB_DE_PACIENTES_H_INCLUDED

#include "paciente.h"

// ABB

typedef struct nodo_paciente2 {
    paciente info;
    nodo_paciente2 *hIzq;
    nodo_paciente2 *hDer;
} nodo_paciente;

typedef nodo_paciente *abb_de_pacientes;

// Metodos

void abb_crear(abb_de_pacientes &arbol);

// precondicion no existe dicho paciente
void abb_insertar_paciente(abb_de_pacientes &arbol, paciente info);

// precondicion no es vacio y debe existir
paciente abb_buscar_paciente(abb_de_pacientes arbol, long cedula);

// precondicion no es vacio
// void abb_borrar_paciente(abb_de_pacientes arbol, long cedula);

void abb_mostrar_pacientes(abb_de_pacientes arbol);

boolean abb_es_vacio(abb_de_pacientes arbol);

// precondicion no es vacio
boolean abb_existe_paciente(abb_de_pacientes arbol, long cedula);

void paciente_menor_y_mayor_cedula(abb_de_pacientes arbol, paciente &paciente_menor_cedula, paciente &paciente_mayor_cedula);

int cantidad_pacientes_por_apellido(abb_de_pacientes arbol, string apellido);

//long cedula_paciente_con_mas_consultas(abb_de_pacientes arbol);

#endif // ABB_DE_PACIENTES_H_INCLUDED
