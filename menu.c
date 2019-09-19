#include "menu.h"

void inicioProg(){

     int opcion=-1;

     while(opcion != 0){
       // system("clear");
        printf("\n\n \t\t\t\t-----PROG HOTEL BINARIO -----\n\n");
        
        printf("\t[1] - CREAR HABITACIONES\t\t\t[2] - RESERVAR HABITACION\n\n");
       
        printf("\t[3] - LIBERAR HABITACION\t\t\t[4] - LISTAR HABITACIONES\n\n");
        
        printf("\t[5] - CANTIDAD DE REGISTROS\t\t\t[6] - HABITACIONES DISPONIBLES \n\n");

        printf("\t[7] - REINICIAR HABITACIONES\t\t\t[0] - FINALIZAR PROG \n\n");
        
        printf("\n\t\t\tINGRESE LA OPCION: ");
        scanf("%d",&opcion);

        switch (opcion)
        {
            case MENU_INICIALIZAR:
                    system("clear");
                    crearHabitaciones(Open_A_Bin);
                break;

            case MENU_RESERVA:
                    system("clear");
                    reservarHabitacion();
                break;
           case MENU_LIBERAR:
                    system("clear");
                    liberarHabitacion();
               break;
            
            case MENU_LISTAR:
                    system("cls");
                    printea();
                break;

            case MENU_CANTREG:
                    system("clear");
                    cantidadRegistros();
                break;

            case MENU_H_LIBRES:
                    system("clear");
                    printearHabitacionesLibres();
                break;

            case MENU_H_REINICIAR:
                    system("clear");
                    crearHabitaciones(Open_W_Bin);
                break;
        }
    }

}
