#include "Aluno.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

Aluno::Aluno()
{
    //ctor
}

void Aluno::AdicionarAluno(Aluno::EstAluno *lista)
{
    ofstream fp;
    Aluno::EstAluno aluno;
    cout << "\n** Adicionar Aluno **\n" << endl;
    cout << "Numero de processo: ";
    cin >> aluno.num_proc;
    cout << "Nome: ";
    cin >> aluno.nome;
    cout << "Ano: ";
    cin >> aluno.ano;
    cout << "Turma: ";
    cin >> aluno.turma;
    cout << "Telemovel: ";
    cin >> aluno.telemovel;

    fp.open("alunos.tsv",ios_base::app);
    fp << aluno.num_proc << "\t" << aluno.nome << "\t" << aluno.ano << "\t" << aluno.turma << "\t" << aluno.telemovel << "\n";
    fp.close();
}

void Aluno::LimparAlunos(Aluno::EstAluno *lista)
{
    Aluno::EstAluno *p;
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

void Aluno::CarregarAlunos(Aluno::EstAluno *lista)
{
    ifstream fp("alunos.tsv");
    Aluno::EstAluno *tmp = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
    Aluno::EstAluno *p = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
    while(!fp.eof())
    {
        Aluno::EstAluno *novo = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
        fp >> novo->num_proc >> novo->nome >> novo->ano >> novo->turma >> novo->telemovel;
        novo->ant = NULL;
        novo->prox = NULL;
        if(lista->prox == NULL)
        {
            novo->ant = lista;
            lista->prox = novo;
        }
        else
        {
            for(p=lista;p->prox!=NULL;p=p->prox) {}
            p->prox = novo;
            novo->ant = p;
        }
    }
    fp.close();
}

void Aluno::ListarAluno(Aluno::EstAluno *aluno)
{
    cout << "\nNumero de processo: " << aluno->num_proc << endl;
    cout << "Nome: " << aluno->nome << endl;
    cout << "Ano: " << aluno->ano << endl;
    cout << "Turma: " << aluno->turma << endl;
    cout << "Telemovel: " << aluno->telemovel << endl;
}

void Aluno::PesquisarAlunoNumProc(Aluno::EstAluno *lista,int num_proc)
{
    if(lista->prox==NULL)
        cout << "Nunca foram adicionados alunos." << endl;
    Aluno::EstAluno *p = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
    for(p=lista->prox;p!=NULL;p=p->prox)
    {
        if(p->num_proc==num_proc)
            ListarAluno(p);
    }
}
