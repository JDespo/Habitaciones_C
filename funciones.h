#ifndef FUNCIONES_H_INCLUDES
#define FUNCIONES_H_INCLUDES

#include "config.h"

typedef struct 
{
    char nombre[l_first_name+1];
    char apellido[l_last_name+1];
    char email[l_email+1];
    int edad;
    int dni;
}STR_CLIENTES;

typedef struct
{
    int numeroHabitacion;
    STR_CLIENTES cliente;
    ESTADOS estado;
    int dias;
}STR_DATOS;


FILE *Open(const char* name,  const char *mode);
STR_DATOS *iniciarHabitacion(int i, int estado);
void crearHabitaciones(const char *mode);
int cantidadRegistros();


void reservarHabitacion();
void liberarHabitacion();
int buscarHabitacionLibre();
int buscarHabitacion();



#endif 