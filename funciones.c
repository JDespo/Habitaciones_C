#include "funciones.h"
#include "printea.h"


FILE *Open(const char *name, const char *mode)
{
    FILE *pArchivo = NULL;
    
    if((pArchivo=fopen(name, mode))== NULL)
    {
        exit(EXIT_FAILURE);
    }

    return pArchivo;
}


void crearHabitaciones(const char *mode)
{
    FILE *pArchivio = Open(File_Name_Bin, mode);
    STR_DATOS *dato=(STR_DATOS*)malloc(sizeof(STR_DATOS));

    for(int i= 1; i <= n_rooms; i++)
    {
        dato = iniciarHabitacion(i, ESTADO_LIBRE);
        fwrite(dato, sizeof(STR_DATOS), 1, pArchivio);
    }
    fclose(pArchivio);
}


STR_DATOS *iniciarHabitacion(int i, int estado)
{
    STR_DATOS *dato = (STR_DATOS*) malloc(sizeof(STR_DATOS));

        dato->estado = estado;               
        memset(dato->cliente.nombre, '\0', l_first_name+1);
        memset(dato->cliente.apellido, '\0', l_last_name+1);
        dato->cliente.edad = '\0';
        memset(dato->cliente.email, '\0', l_email+1);
        dato->cliente.dni = '\0';
        dato->numeroHabitacion = i;
        dato->dias = '\0';
        
     return dato;
}


int cantidadRegistros()
{
    FILE *pArchivo = Open(File_Name_Bin, Open_A_Bin);

    long Pos = ftell(pArchivo);
    fseek(pArchivo, 0, SEEK_END);
    long Ult = ftell(pArchivo);
    fseek(pArchivo, Pos, SEEK_SET);
    long result = Ult / sizeof(STR_DATOS);

    printf("\n\tCant Total de HAbitaciones: %ld \n", result);
    fclose(pArchivo);

    return result;
}



int buscarHabitacionLibre() 
{
    FILE *pArchivio = Open(File_Name_Bin, Open_A_Bin);
    STR_DATOS dato;
    
    fseek(pArchivio, 0, SEEK_SET);
    fread(&dato, sizeof(STR_DATOS), 1, pArchivio);
    int contador= 1;

    while(!feof(pArchivio))
    {
        if(dato.estado == ESTADO_LIBRE)
        {               
            fclose(pArchivio);
            return contador;
        }
        contador ++;
        fread(&dato, sizeof(STR_DATOS),1,pArchivio);
    }

    fclose(pArchivio);
    printf("\t\t #### NO disponemos de habitaciones LIBRES ####");
    return -1;
}

int buscarHabitacion()
{
    FILE *pArchivio = Open(File_Name_Bin, Open_A_Bin);
    fseek(pArchivio, 0, SEEK_SET);
    
    STR_DATOS dato;
    int numero = 0;
    printf("    INDIQUE N. DE HABITACION: ");
    scanf("%d",&numero);
    
    fseek(pArchivio, sizeof(STR_DATOS)*(numero-1), SEEK_SET);
    fread(&dato, sizeof(STR_DATOS),1,pArchivio);

    if(dato.estado == ESTADO_LIBRE)
    {
        printf("\nLa habitacion se encuentra disponible\n");
        return numero;
    }
    else
    {   
        
        printf("\nLa habitaicon NO ESTA DISPONIBLE\n ");
        printearHabitacionesLibres();
        printf("\n    INDIQUE N. DE HABITACION: ");
        scanf("%d",&numero);
        return numero;
    }
}

void reservarHabitacion()
{
    FILE *pArchivio = Open(File_Name_Bin, Open_R_Bin);
    STR_DATOS *dato=(STR_DATOS*)malloc(sizeof(STR_DATOS));
    
    int habitacion = 0;
    int opcion = 0;
    printf("\t\t...:::INGRESAR DATOS DE RESERVA:::...\n");
    printf(" Nombre: ");scanf("%s", dato->cliente.nombre);
    printf(" APELIIDO: ");scanf("%s", dato->cliente.apellido);
    printf(" DNI: "); scanf("%i", &dato->cliente.dni);
    printf(" EDAD: "); scanf("%i", &dato->cliente.edad);
    printf(" EMAIL: "); scanf("%s", dato->cliente.email);
    printf(" CANT. DIAS: "); scanf("%i", &dato->dias);

    printf("\nASIGNACION AUTOMATICA [0] - [1] ASIGNACION MANUAL: ");
    scanf("%i",&opcion);
    if(opcion == 0)
    {
          habitacion = buscarHabitacionLibre();
    }
    else
    {
         habitacion = buscarHabitacion();
    }
    
    dato->numeroHabitacion = habitacion;
    dato->estado = ESTADO_OCUPADO;
    pintDatos(dato);

    fseek(pArchivio, sizeof(STR_DATOS)*(habitacion-1), SEEK_SET);
    fwrite(dato, sizeof(STR_DATOS), 1, pArchivio);
    fclose(pArchivio);
}


void liberarHabitacion()
{
    int numero = 0;
    printf("Indique Habitacion a Liberar: ");
    scanf("%i",&numero);

    FILE *pArchivio = Open(File_Name_Bin, Open_R_Bin);
    STR_DATOS *dato=(STR_DATOS*)malloc(sizeof(STR_DATOS));
    dato = iniciarHabitacion(numero, ESTADO_LIBRE);
    fseek(pArchivio, sizeof(STR_DATOS)*(numero-1), SEEK_SET);
    fwrite(dato, sizeof(STR_DATOS),1,pArchivio);
    fclose(pArchivio);

}
