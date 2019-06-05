#include <iostream>
#include <stdlib.h>
#include "Menus.h"
#include "Aluno.h"
#include "Manuais.h"

using namespace std;

int main()
{
    Menus menus;
    Aluno aluno;
    Manuais manual;
    int opt,subopt,subsubopt;
    Aluno::EstAluno *alunos = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
    Manuais::EstManual *manuais = (Manuais::EstManual*) malloc(sizeof(Manuais::EstManual));
    Aluno::EstAluno *p = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
    Manuais::EstManual *q = (Manuais::EstManual*) malloc(sizeof(Manuais::EstManual));
    alunos->ant = NULL;
    alunos->prox = NULL;
    do{
        opt = menus.Menu();
        switch(opt)
        {
            case 1:
                subopt = menus.SubMenu("Alunos");
                switch(subopt)
                {
                    case 1:
                        aluno.LimparAlunos(alunos);
                        aluno.CarregarAlunos(alunos);
                        aluno.AdicionarAluno(alunos);
                        break;
                    case 2:
                        aluno.LimparAlunos(alunos);
                        aluno.CarregarAlunos(alunos);
                        if(alunos->prox==NULL)
                            cout << "Nunca foram adicionados alunos." << endl;
                        else
                        {
                            for(p=alunos->prox;p!=NULL;p=p->prox)
                                aluno.ListarAluno(p);
                        }
                        break;
                    case 3:
                        aluno.LimparAlunos(alunos);
                        aluno.CarregarAlunos(alunos);
                        subsubopt = menus.SubSubMenu(1);
                        switch(subsubopt)
                        {
                            case 1:
                                aluno.PesquisarAlunoNumProc(alunos);
                                break;
                            case 2:
                                aluno.PesquisarAlunoNome(alunos);
                                break;
                            case 3:
                                aluno.PesquisarAlunoAno(alunos);
                                break;
                            case 4:
                                aluno.PesquisarAlunosTurma(alunos);
                                break;
                            case 5:
                                aluno.PesquisarAlunosTelemovel(alunos);
                                break;
                        }
                        break;
                }
                break;

            case 2: //Manuais
                subopt = menus.SubMenu("Manuais");
                switch(subopt)
                {
                    case 1:
                        manual.LimparManuais(manuais);
                        manual.CarregarManuais(manuais);
                        manual.AdicionarManual(manuais);
                        break;
                    case 2:
                        manual.LimparManuais(manuais);
                        manual.CarregarManuais(manuais);
                        for(q=manuais->prox;q!=NULL;q=q->prox)
                            manual.ListarManual(q);
                        break;
                    case 3:
                        subsubopt = menus.SubSubMenu(2);
                        switch(subsubopt)
                        {
                            case 1:
                                manual.LimparManuais(manuais);
                                manual.CarregarManuais(manuais);
                                manual.PesquisarManualISBN(manuais);
                                break;
                        }
                }
                break;
        }
    }while(opt);
    return 0;
}
