#include"fecha.h"

void cargar_fecha(fecha &fec)
{
    printf("\n\tIngrese un dia: ");
    scanf("%d", &fec.dia);

    printf("\n\tIngrese un mes: ");
    scanf("%d", &fec.mes);

    printf("\n\tIngrese un año: ");
    scanf("%d", &fec.anio);
}

void mostrar_fecha(fecha fec)
{
    printf("%d / %d / %d", fec.dia, fec.mes, fec.anio);
}

int dar_dia(fecha fec)
{
    return fec.dia;
}


int dar_mes(fecha fec)
{
    return fec.mes;
}

int dar_anio(fecha fec)
{
    return fec.anio;
}

boolean fecha_valida(fecha fec)
{
    boolean fechaValida=FALSE;
    if(dar_mes(fec)>0 && dar_mes(fec)<13)
    {
        switch(dar_mes(fec))
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                    if(fec.dia>0 && fec.dia<32)
                    {
                        fechaValida=TRUE;
                    }
                    break;
            case 4:
            case 6:
            case 9:
            case 11:
                    if(fec.dia>0 && fec.dia<31)
                    {
                        fechaValida=TRUE;
                    }
                    break;
            case 2:
                    if(!(fec.anio%4) && ( fec.anio%100  || !(fec.anio%400) ))
                    {
                        if(fec.dia>0 && fec.dia<30)
                        {
                            fechaValida=TRUE;
                        }
                    }
                    else
                    {
                        if(fec.dia>0 && fec.dia<29)
                        {
                            fechaValida=TRUE;
                        }
                    }
                    break;
        }
    }
    return fechaValida;
}

boolean fecha_pertenece_al_rango(fecha fecha_pertenece, fecha fecha_inicial, fecha fecha_fin){

    boolean pertenece = FALSE;

    if(fecha_pertenece.anio > fecha_inicial.anio && fecha_pertenece.anio < fecha_fin.anio){

        pertenece = TRUE;
    } else {
        if(fecha_pertenece.anio == fecha_inicial.anio){
            if(fecha_pertenece.mes > fecha_inicial.mes){

                pertenece = TRUE;
            } else {
                if(fecha_pertenece.mes == fecha_inicial.mes){
                    if(fecha_pertenece.dia >= fecha_inicial.dia){
                        pertenece = TRUE;
                    }
                }
            }
        } else {
            if(fecha_pertenece.anio == fecha_fin.anio){
                if(fecha_pertenece.mes < fecha_fin.mes){

                    pertenece = TRUE;
                } else {
                    if(fecha_pertenece.mes == fecha_fin.mes){
                        if(fecha_pertenece.dia <= fecha_inicial.dia){

                            pertenece = TRUE;
                        }
                    }
                }
            }
        }
    }

    return pertenece;
}

//Devuelve TRUE si el primero es mayor que el segundo
boolean fecha_es_mayor(fecha fecha_info, fecha fecha_despues){
    boolean es_mayor = FALSE;

    if(fecha_info.anio >= fecha_despues.anio){
        if(fecha_info.mes >= fecha_despues.mes){
            if(fecha_info.dia >= fecha_despues.dia){
                es_mayor = TRUE;
            }
        }
    }
}
