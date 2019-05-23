//Carlos Tojal, nº5, 1ºTSI
//https://www.github.com/carlostojal/TSI/tree/master/M7 - Tratamento de Ficheiros/biblioteca/src/main.c

//Contém o código principal

#include <stdio.h>
#include <stdlib.h>
#include "libs/estruturas.h"
#include "libs/menus.h"
#include "libs/alunos.h"
#include "libs/manuais.h"
#include "libs/emprestimos.h"


int main()
{
    Aluno *alunos = (Aluno*) malloc(sizeof(Aluno));
    Manual *manuais = (Manual*) malloc(sizeof(Manual));
    Emprestimo *emprestimos = (Emprestimo*) malloc(sizeof(Emprestimo));
    alunos->prox = NULL;
    alunos->ant = NULL;
    manuais->prox = NULL;
    manuais->ant = NULL;
    int opt;
    do{
        opt = menu();
        switch(opt)
        {
            case 1:
                adicionar_aluno();
                break;
            case 2:
                carregar_alunos(alunos);
                listar_alunos(alunos);
                break;
            case 3:
                adicionar_manual();
                break;
            case 4:
                carregar_manuais(manuais);
                listar_manuais(manuais);
                break;
            case 5:
                adicionar_emprestimo();
                break;
            case 6:
                carregar_emprestimos(emprestimos);
                listar_emprestimos(emprestimos);
                break;
        }
    }while(opt);
    free(alunos);
    free(manuais);
    return 0;
}
