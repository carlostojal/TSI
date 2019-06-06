#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Menus.h"
#include "Aluno.h"
#include "Manuais.h"
#include "Emprestimo.h"
using namespace std;

int main()
{
    Menus menus;
    Aluno aluno;
    Manuais manual;
    Emprestimo emprestimo;
    int opt,subopt,subsubopt;

    Aluno::EstAluno *alunos = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
    Manuais::EstManual *manuais = (Manuais::EstManual*) malloc(sizeof(Manuais::EstManual));
    Emprestimo::EstEmprestimo *emprestimos = (Emprestimo::EstEmprestimo*) malloc(sizeof(Emprestimo::EstEmprestimo));

    Aluno::EstAluno *p = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
    Manuais::EstManual *q = (Manuais::EstManual*) malloc(sizeof(Manuais::EstManual));
    Emprestimo::EstEmprestimo *r = (Emprestimo::EstEmprestimo*) malloc(sizeof(Emprestimo::EstEmprestimo));

    alunos->ant = NULL;
    alunos->prox = NULL;
    manuais->ant = NULL;
    manuais->prox = NULL;
    emprestimos->ant = NULL;
    emprestimos->prox = NULL;

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
                            case 2:
                                manual.LimparManuais(manuais);
                                manual.CarregarManuais(manuais);
                                manual.PesquisarManuaisTitulo(manuais);
                                break;
                            case 3:
                                manual.LimparManuais(manuais);
                                manual.CarregarManuais(manuais);
                                manual.PesquisarManuaisDisciplina(manuais);
                                break;
                        }
                }
                break;
            case 3: //Emprstimos
                subopt = menus.SubMenu("Emprestimos");
                switch(subopt)
                {
                    case 1:
                        emprestimo.LimparEmprestimos(emprestimos);
                        emprestimo.CarregarEmprestimos(emprestimos);
                        emprestimo.AdicionarEmprestimo(emprestimos);
                        break;
                    case 2:
                        emprestimo.LimparEmprestimos(emprestimos);
                        emprestimo.CarregarEmprestimos(emprestimos);
                        for(r=emprestimos->prox;r!=NULL;r=r->prox)
                        {
                            for(p=alunos->prox;p!=NULL;p=p->prox)
                            {
                                for(q=manuais->prox;q!=NULL;q=q->prox)
                                {
                                    if(r->id_aluno==p->num_proc&&strcmp(r->id_manual,q->isbn)==0)
                                        emprestimo.ListarEmprestimo(r,p,q);
                                }
                            }
                        }
                        break;
                    case 3:
                        subsubopt = menus.SubSubMenu(3);
                        switch(subsubopt)
                        {
                            case 1:
                                aluno.LimparAlunos(alunos);
                                aluno.CarregarAlunos(alunos);
                                manual.LimparManuais(manuais);
                                manual.CarregarManuais(manuais);
                                emprestimo.LimparEmprestimos(emprestimos);
                                emprestimo.CarregarEmprestimos(emprestimos);
                                emprestimo.PesquisarEmprestimoID(emprestimos,alunos,manuais);
                                break;
                            case 2:
                                aluno.LimparAlunos(alunos);
                                aluno.CarregarAlunos(alunos);
                                manual.LimparManuais(manuais);
                                manual.CarregarManuais(manuais);
                                emprestimo.LimparEmprestimos(emprestimos);
                                emprestimo.CarregarEmprestimos(emprestimos);
                                emprestimo.PesquisarEmprestimoNumProc(emprestimos,alunos,manuais);
                                break;
                            case 3:
                                aluno.LimparAlunos(alunos);
                                aluno.CarregarAlunos(alunos);
                                manual.LimparManuais(manuais);
                                manual.CarregarManuais(manuais);
                                emprestimo.LimparEmprestimos(emprestimos);
                                emprestimo.CarregarEmprestimos(emprestimos);
                                emprestimo.PesquisarEmprestimoNome(emprestimos,alunos,manuais);
                                break;
                            case 4:
                                aluno.LimparAlunos(alunos);
                                aluno.CarregarAlunos(alunos);
                                manual.LimparManuais(manuais);
                                manual.CarregarManuais(manuais);
                                emprestimo.LimparEmprestimos(emprestimos);
                                emprestimo.CarregarEmprestimos(emprestimos);
                                emprestimo.PesquisarEmprestimoAno(emprestimos,alunos,manuais);
                                break;
                            case 5:
                                aluno.LimparAlunos(alunos);
                                aluno.CarregarAlunos(alunos);
                                manual.LimparManuais(manuais);
                                manual.CarregarManuais(manuais);
                                emprestimo.LimparEmprestimos(emprestimos);
                                emprestimo.CarregarEmprestimos(emprestimos);
                                emprestimo.PesquisarEmprestimoTurma(emprestimos,alunos,manuais);
                                break;
                        }
                }
        }
    }while(opt);
    return 0;
}
