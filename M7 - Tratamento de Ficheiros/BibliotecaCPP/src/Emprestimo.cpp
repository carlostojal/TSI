#include "Emprestimo.h"
#include <iostream>
#include <fstream>
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
