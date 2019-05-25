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
    int opt,sub_opt,sub_sub_opt;
    do{
        opt = menu();
        switch(opt)
        {
            case 1: //Opção 1 (Alunos)
                sub_opt = submenu("Alunos");
                switch(sub_opt)
                {
                    case 1: //Opção 1 (Adicionar)
                        adicionar_aluno();
                        break;
                    case 2: //Opção 2 (Listar)
                        limpar_alunos(alunos);
                        carregar_alunos(alunos);
                        Aluno *p = (Aluno*) malloc(sizeof(Aluno));
                        for(p=alunos->prox;p!=NULL;p=p->prox)
                            listar_aluno(p);
                        free(p);
                        break;
                    case 3: //Opção 3 (Pesquisar)
                        sub_sub_opt = menu_pesquisas(1); //O 1 significa que se refere ao tipo 1 (alunos)
                        switch(sub_sub_opt)
                        {
                            case 1: //Opção 1 (Número de processo)
                                limpar_alunos(alunos); //Limpa quaisquer elementos existentes
                                carregar_alunos(alunos); //Carrega os elementos da lista para a RAM
                                pesquisar_aluno_numproc(alunos); //Procura
                                break;
                            case 2: //Opção 2 (Nome)
                                limpar_alunos(alunos); //Limpa quaisquer elementos existentes
                                carregar_alunos(alunos); //Carrega os elementos da lista para a RAM
                                pesquisar_aluno_nome(alunos); //Procura
                                break;
                            case 3: //Opção 3 (Ano)
                                limpar_alunos(alunos); //Limpa quaisquer elementos existentes
                                carregar_alunos(alunos); //Carrega os elementos da lista para a RAM
                                pesquisar_alunos_ano(alunos); //Procura
                                break;
                            case 4: //Opção 4 (Turma)
                                limpar_alunos(alunos); //Limpa quaisquer elementos existentes
                                carregar_alunos(alunos); //Carrega os elementos da lista para a RAM
                                pesquisar_alunos_turma(alunos); //Procura
                                break;
                            case 5: //Opção 5 (Telemóvel)
                                limpar_alunos(alunos); //Limpa quaisquer elementos existentes
                                carregar_alunos(alunos); //Carrega os elementos da lista para a RAM
                                pesquisar_alunos_telemovel(alunos); //Procura
                                break;
                        }
                }
                break;
            case 2: //Opção 2 (Manuais)
                sub_opt = submenu("Manuais");
                switch(sub_opt)
                {
                    case 1: //Opção 1 (Adicionar)
                        adicionar_manual();
                        break;
                    case 2: //Opção 2 (Listar)
                        limpar_manuais(manuais);
                        carregar_manuais(manuais);
                        Manual *p = (Manual*) malloc(sizeof(Manual));
                        for(p=manuais->prox;p!=NULL;p=p->prox)
                            listar_manual(p);
                        free(p);
                        break;
                    case 3: //Opção 3 (Pesquisar)
                        sub_sub_opt = menu_pesquisas(2);
                        switch(sub_sub_opt)
                        {
                            case 1: //Opção 1 (ISBN)
                                limpar_manuais(manuais);
                                carregar_manuais(manuais);
                                pesquisar_manual_isbn(manuais);
                                break;
                            case 2: //Opção 2 (Título)
                                limpar_manuais(manuais);
                                carregar_manuais(manuais);
                                pesquisar_manuais_titulo(manuais);
                                break;
                            case 3: //Opção 3 (Disciplina)
                                limpar_manuais(manuais);
                                carregar_manuais(manuais);
                                pesquisar_manuais_disciplina(manuais);
                                break;
                        }
                }
                break;
            case 3: //Opção 3 (Empréstimos)
                sub_opt = submenu("Emprestimos");
                switch(sub_opt)
                {
                    case 1: //Opção 1 (Adicionar)
                        adicionar_emprestimo();
                        break;
                    case 2: //Opção 2 (Listar)
                        limpar_emprestimos(emprestimos);
                        carregar_emprestimos(emprestimos);
                        Emprestimo *p = (Emprestimo*) malloc(sizeof(Emprestimo));
                        for(p=emprestimos->prox;p!=NULL;p=p->prox)
                            listar_emprestimo(p);
                        free(p);
                        break;
                    case 3: //Opção 3 (Pesquisar)
                        sub_sub_opt = menu_pesquisas(3);
                        switch(sub_sub_opt)
                        {
                            case 1: //Opção 1 (ID do Empréstimo)
                                limpar_emprestimos(emprestimos);
                                carregar_emprestimos(emprestimos);
                                pesquisar_emprestimo_id(emprestimos);
                                break;
                            case 2: //Opção 2 (ID do Aluno)
                                limpar_emprestimos(emprestimos);
                                carregar_emprestimos(emprestimos);
                                pesquisar_emprestimo_id_aluno(emprestimos);
                                break;
                            case 3: //Opção 3 (ID do Manual)
                                limpar_emprestimos(emprestimos);
                                carregar_emprestimos(emprestimos);
                                pesquisar_emprestimo_id_manual(emprestimos);
                                break;
                            case 4: //Opção 4 (Data de Levantamento)
                                limpar_emprestimos(emprestimos);
                                carregar_emprestimos(emprestimos);
                                pesquisar_emprestimo_data_levantamento(emprestimos);
                                break;
                        }
                }
                break;
        }
    }while(opt); //repete enquanto o operador do menu principal for diferente de 0
    //Libertação dos headers das listas no fim da execução
    free(alunos);
    free(manuais);
    free(emprestimos);
    return 0;
}
