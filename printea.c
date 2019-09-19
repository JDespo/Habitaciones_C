#include "funciones.h"
#include "printea.h"

void printea()
{
    FILE *pArchivio = Open(File_Name_Bin, Open_A_Bin);
    STR_DATOS *dato=(STR_DATOS*)malloc(sizeof(STR_DATOS));

    fseek(pArchivio, 0, SEEK_SET);
    fread(dato, sizeof(STR_DATOS),1,pArchivio);
    printf("\n..:: LIST HABITACIONES ::..\nHABITACION \tNombre: \tApellido:\t\tEDAD: \t\tDNI: \t\tEMAIL: \t\tDIAS:\n");
        

    while(!feof(pArchivio))
    {
        pintDatos(dato);
        fread(dato, sizeof(STR_DATOS),1,pArchivio);
    }
    fclose(pArchivio);
    system("pause");
}

void printearHabitacionesLibres()
{
    FILE *pArchivio = Open(File_Name_Bin, Open_A_Bin);
    STR_DATOS dato;
    
    fseek(pArchivio, 0, SEEK_SET);
    fread(&dato, sizeof(STR_DATOS), 1, pArchivio);
    
    int contador = 0;
    printf("\n\t\t..:: LIST HABITACIONES DISPONIBLES ::..\n\n");
    while(!feof(pArchivio))
    {
        if(dato.estado == ESTADO_LIBRE)
        {             
            contador++;
            printf("\t[%d]\t", dato.numeroHabitacion);
            if (contador == 5)
            { 
                printf("\n");
                contador = 0;
            }
        }
        
        fread(&dato, sizeof(STR_DATOS), 1, pArchivio);
    }
    fclose(pArchivio);
}

void pintDatos(STR_DATOS *dato)
{
        printf("  [%d]", dato->numeroHabitacion);
        printf("\t\t%s\t", dato->cliente.nombre);
        printf("\t%s\t", dato->cliente.apellido);
        printf("%d", dato->cliente.edad);
        printf("\t\t%d", dato->cliente.dni);
        printf("\t\t%s", dato->cliente.email);
        printf("\t\t%d\n\n", dato->dias);
}