#include <iostream>
#include <stdlib.h>
#include "Menus.h"
#include "Aluno.h"

using namespace std;

int main()
{
    Menus menus;
    Aluno aluno;
    int opt,subopt,subsubopt;
    Aluno::EstAluno *alunos = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
    Aluno::EstAluno *p = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
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
                        }
                        break;
                }
                break;
        }
    }while(opt);
    return 0;
}
