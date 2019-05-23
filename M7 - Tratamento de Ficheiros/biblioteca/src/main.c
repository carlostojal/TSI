//Carlos Tojal, nº5, 1ºTSI
//https://www.github.com/carlostojal/TSI/tree/master/M7 - Tratamento de Ficheiros/biblioteca/src/main.c

//Contém o código principal

#include <stdio.h>
#include "libs/estruturas.h"
#include "libs/menus.h"


int main()
{
    int opt;
    do{
        opt = menu();
    }while(opt);
    return 0;
}
