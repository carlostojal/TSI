//Carlos Tojal, nº5, 1ºTSI
//https://www.github.com/carlostojal/TSI/tree/master/M7 - Tratamento de Ficheiros/biblioteca/src/main.c
//biblioteca/src/main.c

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
    //Declaração dos headers das listas
    Aluno *alunos = (Aluno*) malloc(sizeof(Aluno));
    Manual *manuais = (Manual*) malloc(sizeof(Manual));
    Emprestimo *emprestimos = (Emprestimo*) malloc(sizeof(Emprestimo));
    //Inicialização dos headers das listas
    alunos->prox = NULL;
    alunos->ant = NULL;
    manuais->prox = NULL;
    manuais->ant = NULL;
    emprestimos->prox = NULL;
    emprestimos->ant = NULL;
    int opt,sub_opt;
    do{
        opt = menu();
        switch(opt)
        {
            case 1: //Opção 1 (Alunos)
                sub_opt = submenu("Alunos");
                switch(sub_opt)
                {
                    case 1: //Opção 1 (Adicionar Aluno)
                        adicionar_aluno();
                        break;
                    case 2: //Opção 2 (Listar Alunos)
                        carregar_alunos(alunos);
                        listar_alunos(alunos);
                        break;
                }
                break;
            case 2: //Opção 2 (Manuais)
                sub_opt = submenu("Manuais");
                switch(sub_opt)
                {
                    case 1: //Opção 1 (Adicionar Manual)
                        adicionar_manual();
                        break;
                    case 2: //Opção 2 (Listar Manuais)
                        carregar_manuais(manuais);
                        listar_manuais(manuais);
                        break;
                }
                break;
            case 3: //Opção 3 (Empréstimos)
                sub_opt = submenu("Emprestimos");
                switch(sub_opt)
                {
                    case 1: //Opção 1 (Adicionar empréstimo)
                        adicionar_emprestimo();
                        break;
                    case 2: //Opção 2 (Listar Empréstimos)
                        carregar_emprestimos(emprestimos);
                        listar_emprestimos(emprestimos);
                        break;
                }
                break;
        }
    }while(opt); //repete enquanto o operador do menu principal for diferente de 0
    //Libertação dos headers no fim da execução
    free(alunos);
    free(manuais);
    free(emprestimos);
    return 0;
}
