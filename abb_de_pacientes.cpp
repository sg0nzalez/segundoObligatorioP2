#include "abb_de_pacientes.h"

void abb_crear(abb_de_pacientes &arbol)
{
    arbol = NULL;
}

void abb_insertar_paciente(abb_de_pacientes &arbol, paciente info)
{
    if (arbol == NULL)
    {
        arbol = new nodo_paciente;
        arbol->info = info;
        arbol->hIzq = NULL;
        arbol->hDer = NULL;
    }
    else
    {
        if (darCedula(info) < darCedula(arbol->info))
        {
            abb_insertar_paciente(arbol->hIzq, info);
        }
        else
        {
            abb_insertar_paciente(arbol->hDer, info);
        }
    }
}

paciente abb_buscar_paciente(abb_de_pacientes arbol, long cedula)
{
    if (cedula == darCedula(arbol->info))
    {
        return arbol->info;
    }
    else
    {
        if (cedula < darCedula(arbol->info))
        {
            return abb_buscar_paciente(arbol->hIzq, cedula);
        }
        else
        {
            return abb_buscar_paciente(arbol->hDer, cedula);
        }
    }
}

void abb_mostrar_pacientes(abb_de_pacientes arbol)
{
    if (arbol != NULL)
    {
        abb_mostrar_pacientes(arbol->hIzq);

        mostrar_paciente(arbol->info);

        abb_mostrar_pacientes(arbol->hDer);
    }
}

boolean abb_es_vacio(abb_de_pacientes arbol)
{
    return (boolean)(arbol == NULL);
}

boolean abb_existe_paciente(abb_de_pacientes arbol, long cedula)
{
    if (cedula == darCedula(arbol->info))
    {
        return TRUE;
    }
    else
    {
        if (cedula < darCedula(arbol->info))
        {
            return abb_existe_paciente(arbol->hIzq, cedula);
        }
        else
        {
            return abb_existe_paciente(arbol->hDer, cedula);
        }
    }

    return FALSE;
}

void paciente_menor_y_mayor_cedula(abb_de_pacientes arbol, paciente &paciente_menor_cedula, paciente &paciente_mayor_cedula){

    abb_de_pacientes arbol_aux = arbol;

    while(arbol != NULL)
    {
        paciente_menor_cedula = arbol->info;
        arbol = arbol->hIzq;
    }
    while(arbol_aux != NULL)
    {
        paciente_mayor_cedula = arbol_aux->info;
        arbol_aux = arbol_aux->hDer;
    }
}

int cantidad_pacientes_por_apellido(abb_de_pacientes arbol, string apellido)
{
    if (arbol == NULL)
    {
        return 0;
    }
    else
    {
        string apellido_info;
        dar_apellido(arbol->info, apellido_info);

        if (comparar_2_strings(apellido_info, apellido))
        {
            return 1 + cantidad_pacientes_por_apellido(arbol->hIzq, apellido) + cantidad_pacientes_por_apellido(arbol->hDer, apellido);
        }

        return cantidad_pacientes_por_apellido(arbol->hIzq, apellido) + cantidad_pacientes_por_apellido(arbol->hDer, apellido);
    }
}
