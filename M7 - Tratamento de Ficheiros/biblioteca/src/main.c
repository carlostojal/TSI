//Carlos Tojal, nº5, 1ºTSI
//https://www.github.com/carlostojal/TSI/tree/master/M7 - Tratamento de Ficheiros/biblioteca/src/main.c

//Contém o código principal

#include <stdio.h>
#include "libs/estruturas.h"
#include "libs/menus.h"
#include "libs/alunos.h"


int main()
{
    Aluno *lista = malloc(sizeof(Aluno));
    lista->prox = NULL;
    lista->ant = NULL;
    int opt;
    do{
        opt = menu();
        switch(opt)
        {
            case 1:
                adicionar_aluno();
                break;
            case 2:
                carregar_alunos(lista);
                listar_alunos(lista);
                break;
        }
    }while(opt);
    free(lista);
    return 0;
}
