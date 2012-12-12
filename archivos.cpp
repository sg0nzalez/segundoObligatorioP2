#include "archivos.h"

boolean existe_archivo(string nomArch)
{
    boolean existeArchivo = TRUE;

    FILE *f = fopen(nomArch, "rb");

    if(f == NULL)
        existeArchivo = FALSE;

    fclose(f);

    return existeArchivo;
}

void bajar_string(string s, FILE *f)
{
    int i=0;

    while (s[i] != '\0')
    {
        fwrite(&s[i], sizeof(char), 1, f);
        i++;
    }

    fwrite(&s[i], sizeof(char), 1, f);
}

void levantar_string(string &s, FILE * f)
{
    int i=0;
    string aux;
    aux = new char[LARGO_STRING];
    fread (&aux[i], sizeof(char), 1, f);

    while (!feof(f) && (aux[i] != '\0'))
    {
        i++;
        fread (&aux[i], sizeof(char), 1, f);
    }
    copiar_string(s, aux);
    delete [] aux;
}

//
//
//
// PROCEDIMIENTOS RELACIONADOS AL ABB DE PACIENTES

void bajar_paciente(paciente p, FILE *f)
{
    fwrite(&p.cedula, sizeof(long), 1, f);
    bajar_string(p.nombre, f);
    bajar_string(p.apellido, f);
    bajar_string(p.domicilio, f);
    fwrite(&p.telefono, sizeof(long), 1, f);
}

void levantar_paciente(paciente &p, FILE *f)
{
    fread (&p.cedula, sizeof(long int), 1, f);
    crear_string(p.nombre);
    levantar_string (p.nombre, f);
    crear_string(p.apellido);
    levantar_string (p.apellido, f);
    crear_string(p.domicilio);
    levantar_string (p.domicilio, f);
    fread (&p.telefono, sizeof(long int), 1, f);
}

void bajar_abb(abb_de_pacientes a)
{
    FILE *f = fopen(ARCHIVO_PACIENTES, "wb");

    bajar_abb_aux(a, f);
    fclose(f);
}

void bajar_abb_aux(abb_de_pacientes a, FILE * f)
{
    if (a != NULL)
    {
        bajar_paciente(a->info, f);
        bajar_abb_aux(a->hIzq, f);
        bajar_abb_aux(a->hDer, f);
    }
}

void levantar_abb(abb_de_pacientes &a)
{
    FILE *f = fopen(ARCHIVO_PACIENTES, "rb");
    paciente buffer;
    levantar_paciente(buffer, f);

    while (!feof(f))
    {
        abb_insertar_paciente(a, buffer);

        levantar_paciente(buffer, f);
    }

    fclose(f);
}

//
//
//
// PROCEDIMIENTOS RELACIONADOS A LA LISTA DE CONSULTAS

void bajar_fecha(fecha fec,FILE *f)
{
    fwrite(&fec.dia, sizeof(int), 1, f);
    fwrite(&fec.mes, sizeof(int), 1, f);
    fwrite(&fec.anio, sizeof(int), 1, f);
}

void levantar_fecha(fecha fec, FILE *f)
{
    fread(&fec.dia, sizeof(int), 1, f);
    fread(&fec.mes, sizeof(int), 1, f);
    fread(&fec.anio, sizeof(int), 1, f);
}

void bajar_consulta(consulta c, FILE *f)
{
    bajar_string(c.descripcion, f);

    fwrite(&c.cedula_paciente, sizeof(long), 1, f);

    fwrite(&c.evaluacion_paciente, sizeof(evaluacion), 1, f);

    bajar_fecha(c.realizacion, f);
}

void levantar_consulta(consulta &c, FILE *f)
{
    crear_string(c.descripcion);
    levantar_string(c.descripcion, f);

    fread(&c.cedula_paciente, sizeof(long), 1, f);

    fread(&c.evaluacion_paciente, sizeof(evaluacion), 1, f);

    levantar_fecha(c.realizacion,f);
}

void bajar_lista_consulta(lista_de_consultas l)
{
    FILE *f = fopen(ARCHIVO_CONSULTAS, "wb");
    lista_de_consultas lista_aux = l;

    while (lista_aux != NULL)
    {
        bajar_consulta(lista_aux->info, f);
        lista_aux = lista_aux->sig;
    }

    fclose(f);
}

void levantar_lista_consulta(lista_de_consultas &l)
{
    FILE * f = fopen (ARCHIVO_CONSULTAS, "rb");
    consulta buffer;
    levantar_consulta(buffer, f);

    while (!feof(f))
    {
        lista_insertar_consulta(l,buffer);
        levantar_consulta(l->info, f);
    }

    fclose(f);
}
