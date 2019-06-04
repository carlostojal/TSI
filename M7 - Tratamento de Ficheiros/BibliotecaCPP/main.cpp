#include <iostream>
#include <stdlib.h>
#include "Menus.h"
#include "Aluno.h"

using namespace std;

int main()
{
    Menus menus;
    Aluno aluno;
    int opt,subopt;
    Aluno::EstAluno *alunos = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
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
                        Aluno::EstAluno *p = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
                        if(alunos->prox==NULL)
                            cout << "Nunca foram adicionados alunos." << endl;
                        else
                        {
                            for(p=alunos->prox;p!=NULL;p=p->prox)
                                aluno.ListarAluno(p);
                        }
                        break;
                }
                break;
        }
    }while(opt);
    return 0;
}
