#include "lista_de_consultas.h"

void crear_lista(lista_de_consultas &lista)
{
    lista = NULL;
}

void lista_insertar_consulta(lista_de_consultas &lista, consulta info)
{
    if (lista == NULL)
    {
        lista = new nodo_consulta;

        lista->info = info;
        lista->sig = NULL;
    }
    else
    {
        lista_insertar_consulta(lista->sig, info);
    }
}

void lista_mostrar_consultas(lista_de_consultas lista)
{
    if (lista != NULL)
    {
        mostrar_consulta(lista->info);
        lista_mostrar_consultas(lista->sig);
    }
}

boolean lista_es_vacia(lista_de_consultas lista)
{
    return (boolean)(lista == NULL);
}

consulta lista_primer_consulta(lista_de_consultas lista)
{
    return lista->info;
}

void mostrar_consultas_entre_2_fechas(lista_de_consultas lista, fecha fecha_inicio, fecha fecha_fin){

    if (lista != NULL){
        if(fecha_pertenece_al_rango(lista->info.realizacion, fecha_inicio, fecha_fin)==TRUE){
            mostrar_consulta(lista->info);
        }
        lista = lista->sig;
        mostrar_consultas_entre_2_fechas(lista, fecha_inicio, fecha_fin);
    }
}

void consultas_por_evaluacion(lista_de_consultas lista, evaluacion evaluacion_a_buscar)
{

   if (lista != NULL)
   {
       if (dar_evaluacion(lista->info) == evaluacion_a_buscar)
       {
           mostrar_consulta(lista->info);
       }

       consultas_por_evaluacion(lista->sig, evaluacion_a_buscar);
   }
}
