#include "string.h"

void cargar_string(string &texto)
{
    char letra;
    int i=0;
    scanf("%c",&letra);
    while(letra!='\n'&&(i<LARGO_STRING))
    {
        texto[i]=letra;
        i++;
        scanf("%c",&letra);
    }
    texto[i]='\0';
}

void desplegar_string(string texto)
{
    int i=0;
    while(texto[i]!='\0')
    {
        printf("%c",texto[i]);
        i++;
    }
}

void copiar_string(string texto, string &texto2)
{
    int i=0;
    while(texto[i]!='\0')
    {
        texto2[i]=texto[i];
        i++;
    }
    texto2[i]='\0';
}

boolean comparar_2_strings(string s1,string s2)
{
    int i=0;
    boolean iguales = TRUE;
    while (iguales && (s1[i]!='\0') && (s2[i]!='\0'))
    {
        if (s1[i]!=s2[i])
        iguales = FALSE;
        i++;
    }
    if ((s1[i]!='\0') || (s2[i]!='\0'))
         iguales = FALSE;
    return iguales;
}
