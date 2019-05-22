#include <stdio.h>
#include <stdlib.h>
#include "lib/estruturas.h"
#include "lib/menus.h"
#include "lib/carros.h"
#include "lib/inspecoes.h"

int main()
{
    Carro *lista = malloc(sizeof(Carro));
    lista->prox = NULL;
    lista->ant = NULL;
    int opt;
    do{
        opt = main_menu();
        switch(opt)
        {
            case 1:
                adicionar_carro();
                break;
            case 2:
                carregar_carros(lista);
                listar_carros(lista);
                break;
        }
    }while(opt);
    return 0;
}
