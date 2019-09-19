#ifndef CONFIG_H_INCLUDES
#define CONFIG_H_INCLUDES

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define File_Name_Bin "habitaciones.dat"

#define n_rooms 10

#define l_first_name 20
#define l_last_name 20
#define l_email 20

#define Open_A_Bin "ab+"
#define Open_R_Bin "r+b"
#define Open_W_Bin "wb+"

typedef enum { ESTADO_LIBRE = 0, ESTADO_OCUPADO }ESTADOS;

#endif