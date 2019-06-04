#include "Aluno.h"
#include <fstream>
#include <stdlib.h>
using namespace std;

Aluno::Aluno()
{
    //ctor
}

Aluno::AdicionarAluno(Aluno::EstAluno *lista)
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

    fp.open("alunos.csv");
    fp << aluno.num_proc << " " << aluno.nome << " " << aluno.ano << " " << aluno.turma << " " << aluno.telemovel << "\n";
    fp.close();
}

Aluno::LimparAlunos(Aluno::EstAluno *lista)
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

Aluno::CarregarAlunos(Aluno::EstAluno *lista)
{
    ifstream fp;
    Aluno::EstAluno *novo = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
    Aluno::EstAluno *p = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
    fp.open("alunos.csv");
    while(fp >> novo->num_proc >> novo->nome >> novo->ano >> novo->turma >> novo->telemovel)
    {
        if(lista->prox == NULL)
            lista->prox = novo;
        else
        {
            for(p=lista;p->prox!=NULL;p=p->prox) {}
            p->prox = novo;
            novo->ant = p;
        }
    }
}
