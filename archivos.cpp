#include "archivos.h"

//controlar que exista
boolean Existe_archivo (string nomArch)
{
    boolean existeArchivo = TRUE;

    FILE * f = fopen (nomArch,"rb");

    if(f == NULL)
        existeArchivo =FALSE;

    fclose(f);

    return existeArchivo;
}

//Escribir string en Archivo
void Bajar_String (string s, FILE * f)
{
    int i=0;

    while (s[i] != '\0')
    {
        fwrite (&s[i], sizeof(char), 1, f);
        i++;
    }

    // escribo el ‘\0’
    fwrite (&s[i], sizeof(char), 1, f);
}

//Cargar string en Archivo
void Levantar_String (string &s, FILE * f)
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
    copiar_string(aux,s);
    delete [] aux;
}

//Escribe paciente en Archivo
void Bajar_Paciente (paciente p, FILE * f )
{
    fwrite (&p.cedula, sizeof(long), 1, f);
    Bajar_String (p.nombre, f);
    Bajar_String (p.apellido, f);
    Bajar_String (p.domicilio, f);
    fwrite (&p.telefono, sizeof(long), 1, f);
}

//Lee paciente del Archivo
void Levantar_Paciente (paciente &p, FILE * f )
{
    fread (&p.cedula, sizeof(long int), 1, f);
    crear_string(p.nombre);
    Levantar_String (p.nombre, f);
    crear_string(p.apellido);
    Levantar_String (p.apellido, f);
    crear_string(p.domicilio);
    Levantar_String (p.domicilio, f);
    fread (&p.telefono, sizeof(long int), 1, f);
}

//Abre el archivo y llama a la funcion que Baja el ABB a un archivo y luego lo cierra
void Bajar_ABB (abb_de_pacientes a)
{
    FILE * f = fopen ("d:\\pacientes.txt","wb");
    Bajar_ABB_Aux (a, f);
    fclose(f);
}

//Baja el archivo
void Bajar_ABB_Aux (abb_de_pacientes a, FILE * f)
{
    if (a != NULL)
    {
        Bajar_Paciente(a->info, f);
        Bajar_ABB_Aux (a->hIzq, f);
        Bajar_ABB_Aux (a->hDer, f);
    }
}

void Levantar_ABB (abb_de_pacientes &a)
{
    FILE * f = fopen ("d:\\pacientes.txt","rb");
    paciente buffer;
    Levantar_Paciente(buffer, f);

    while (!feof(f))
    {

    abb_insertar_paciente(a,buffer);
    Levantar_Paciente(buffer, f);
    }
    fclose(f);
}

// escribe fecha en archivo
void bajar_fecha(fecha fec,FILE *f)
{
    fwrite(&fec.dia,sizeof(int),1,f);
    fwrite(&fec.mes,sizeof(int),1,f);
    fwrite(&fec.anio,sizeof(int),1,f);
}

// lee fecha en un archivo
void levantar_fecha(fecha fec,FILE *f)
{
    fread(&fec.dia,sizeof(int),1,f);
    fread(&fec.mes,sizeof(int),1,f);
    fread(&fec.anio,sizeof(int),1,f);
}

//Escribe consulta en Archivo
void Bajar_consulta (consulta c, FILE * f )
{
    Bajar_String (c.descripcion, f);
    fwrite (&c.cedula_paciente, sizeof(long), 1, f);
    fwrite (&c.evaluacion_paciente, sizeof(evaluacion), 1, f);
    bajar_fecha(c.realizacion,f);
}

//Leeconsulta del Archivo
void Levantar_consulta (consulta &c, FILE * f )
{
    crear_string(c.descripcion);
    Levantar_String (c.descripcion, f);
    fread (&c.cedula_paciente, sizeof(long int), 1, f);
    levantar_fecha(c.realizacion,f);
}

/*//Baja el archivo
void Bajar_lista_consula_Aux (lista_consulta l, FILE * f)
{



if (l != NULL)
{
Bajar_consulta(l->info_consulta,f);
Bajar_lista_consula_Aux(l->sig_consulta,f);
}
}
//Abre el archivo y llama a la funcion que Baja la lista de consultas a un archivo y luego lo cierra
void Bajar_lista_consulta (lista_consulta l)
{
FILE * f = fopen ("d:\\consulta.txt","wb");
Bajar_lista_consula_Aux(l, f);
fclose(f);
}*/
//Abre el archivo y llama a la funcion que Baja la lista de consultas a un archivo y luego lo cierra
void Bajar_lista_consulta (lista_de_consultas l)
{
    FILE * f = fopen ("d:\\consultas.txt","wb");
    while(l!=NULL)
    {
        Bajar_consulta(l->info,f);
        l=l->sig;
    }
    fclose(f);
}
// levantar archivo lista de consultas
void Levantar_lista_consulta (lista_de_consultas &l)
{
    FILE * f = fopen ("d:\\consultas.txt","rb");
    consulta buffer;
    Levantar_consulta(buffer, f);

    while (!feof(f))
    {
        lista_insertar_consulta(l,buffer);
        Levantar_consulta(l->info, f);
    }
    fclose(f);
}
