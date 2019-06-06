#include "Emprestimo.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

Emprestimo::Emprestimo()
{
    //ctor
}

int Emprestimo::AdquirirID(Emprestimo::EstEmprestimo *lista)
{
    Emprestimo::EstEmprestimo *p = (Emprestimo::EstEmprestimo*) malloc(sizeof(Emprestimo::EstEmprestimo));
    if(lista->prox==NULL)
        return 1;
    else
    {
        for(p=lista->prox;p->prox!=NULL;p=p->prox) {}
        return (p->id)+1;
    }
}

void Emprestimo::AdicionarEmprestimo(Emprestimo::EstEmprestimo *lista)
{
    Emprestimo::EstEmprestimo novo;
    ofstream fp;

    cout << "\n** Adicionar Emprestimo **\n" << endl;
    cout << "Numero de Processo: ";
    cin >> novo.id_aluno;
    cout << "ISBN do Manual: ";
    cin >> novo.id_manual;
    cout << "Valor: ";
    cin >> novo.valor;
    novo.id = AdquirirID(lista);

    fp.open("emprestimos.tsv",ios_base::app);
    fp << novo.id << "\t" << novo.id_aluno << "\t" << novo.id_manual << "\t" << novo.valor;
    fp.close();
}

void Emprestimo::LimparEmprestimos(Emprestimo::EstEmprestimo *lista)
{
    Emprestimo::EstEmprestimo *p = (Emprestimo::EstEmprestimo*) malloc(sizeof(Emprestimo::EstEmprestimo));

    if(lista->prox!=NULL)
    {
        for(p=lista->prox;p!=NULL;p=p->prox)
        {
            if(p->prox == NULL)
            {
                free(p);
                break;
            }
            else if(p->ant!=lista)
                free(p->ant);
        }
        lista->prox = NULL;
    }
}

void Emprestimo::CarregarEmprestimos(Emprestimo::EstEmprestimo *lista)
{
    Emprestimo::EstEmprestimo *p = (Emprestimo::EstEmprestimo*) malloc(sizeof(Emprestimo::EstEmprestimo));
    ifstream fp;

    while(!fp.eof())
    {
        Emprestimo::EstEmprestimo *novo = (Emprestimo::EstEmprestimo*) malloc(sizeof(Emprestimo::EstEmprestimo));
        novo->ant = NULL;
        novo->prox = NULL;
        fp >> novo->id >> novo->id_aluno >> novo->id_manual >> novo->valor;
        if(lista->prox==NULL)
        {
            novo->ant = lista;
            lista->prox = novo;
        }
        else
        {
            for(p=lista;p->prox!=NULL;p=p->prox) {}
            novo->ant = p;
            p->prox = novo;
        }
    }
}

void Emprestimo::ListarEmprestimo(Emprestimo::EstEmprestimo *emprestimo,Aluno::EstAluno *aluno,Manuais::EstManual *manual)
{
    cout << "\nID: " << emprestimo->id << endl;
    cout << "Numero de processo: " << aluno->num_proc << endl;
    cout << "Nome: " << aluno->nome << endl;
    cout << "Ano: " << aluno->ano << endl;
    cout << "Turma: " << aluno->turma << endl;
    cout << "Telemovel: " << aluno->telemovel << endl;
    cout << "ISBN: " << manual->isbn << endl;
    cout << "Titulo: " << manual->titulo << endl;
    cout << "Disciplina: " << manual->disciplina << endl;
}

void Emprestimo::PesquisarEmprestimoID(Emprestimo::EstEmprestimo *emprestimos,Aluno::EstAluno *alunos,Manuais::EstManual *manuais)
{
    int id;
    bool encontrou=false;
    Emprestimo::EstEmprestimo *p = (Emprestimo::EstEmprestimo*) malloc(sizeof(Emprestimo::EstEmprestimo));
    Aluno::EstAluno *q = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
    Manuais::EstManual *r = (Manuais::EstManual*) malloc(sizeof(Manuais::EstManual));

    cout << "\n** Pesquisar Emprestimo por ID **\n" << endl;
    cout << "ID: ";
    for(p=emprestimos->prox;p!=NULL;p=p->prox)
    {
        for(q=alunos->prox;q!=NULL;q=q->prox)
        {
            for(r=manuais->prox;r!=NULL;r=r->prox)
            {
                if(p->id_aluno==q->num_proc&&strcmp(p->id_manual,r->isbn)==0)
                {
                    if(p->id==id)
                    {
                        encontrou = true;
                        ListarEmprestimo(p,q,r);
                    }
                }
            }
        }
    }
    if(!encontrou)
        cout << "Nao foram encontrados resultados para a pesquisa." << endl;
}

void Emprestimo::PesquisarEmprestimoNumProc(Emprestimo::EstEmprestimo *emprestimos,Aluno::EstAluno *alunos,Manuais::EstManual *manuais)
{
    int num_proc;
    bool encontrou=false;
    Emprestimo::EstEmprestimo *p = (Emprestimo::EstEmprestimo*) malloc(sizeof(Emprestimo::EstEmprestimo));
    Aluno::EstAluno *q = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
    Manuais::EstManual *r = (Manuais::EstManual*) malloc(sizeof(Manuais::EstManual));

    cout << "\n** Pesquisar Emprestimos por Numero de Processo **\n" << endl;
    cout << "Numero de Processo: ";
    for(p=emprestimos->prox;p!=NULL;p=p->prox)
    {
        for(q=alunos->prox;q!=NULL;q=q->prox)
        {
            for(r=manuais->prox;r!=NULL;r=r->prox)
            {
                if(p->id_aluno==q->num_proc&&strcmp(p->id_manual,r->isbn)==0)
                {
                    if(p->id_aluno==num_proc)
                    {
                        encontrou = true;
                        ListarEmprestimo(p,q,r);
                    }
                }
            }
        }
    }
    if(!encontrou)
        cout << "Nao foram encontrados resultados para a pesquisa." << endl;
}
