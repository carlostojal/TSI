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
    fp << novo.id << "\t" << novo.id_aluno << "\t" << novo.id_manual << "\t" << novo.valor << "\n";
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
    fp.open("emprestimos.tsv");

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
            for(p=lista->prox;p->prox!=NULL;p=p->prox) {}
            novo->ant = p;
            p->prox = novo;
        }
    }
    fp.close();
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
    cin >> id;
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
    cin >> num_proc;
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

void Emprestimo::PesquisarEmprestimoISBN(Emprestimo::EstEmprestimo *emprestimos,Aluno::EstAluno *alunos,Manuais::EstManual *manuais)
{
    char isbn[20];
    bool encontrou=false;
    Emprestimo::EstEmprestimo *p = (Emprestimo::EstEmprestimo*) malloc(sizeof(Emprestimo::EstEmprestimo));
    Aluno::EstAluno *q = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
    Manuais::EstManual *r = (Manuais::EstManual*) malloc(sizeof(Manuais::EstManual));

    cout << "\n** Pesquisar Emprestimos por ISBN **\n" << endl;
    cout << "ISBN: ";
    cin >> isbn;
    for(p=emprestimos->prox;p!=NULL;p=p->prox)
    {
        for(q=alunos->prox;q!=NULL;q=q->prox)
        {
            for(r=manuais->prox;r!=NULL;r=r->prox)
            {
                if(p->id_aluno==q->num_proc&&strcmp(p->id_manual,r->isbn)==0)
                {
                    if(strcmp(p->id_manual,isbn)==0)
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

void Emprestimo::PesquisarEmprestimoNome(Emprestimo::EstEmprestimo *emprestimos,Aluno::EstAluno *alunos,Manuais::EstManual *manuais)
{
    char nome[30];
    bool encontrou=false;
    Emprestimo::EstEmprestimo *p = (Emprestimo::EstEmprestimo*) malloc(sizeof(Emprestimo::EstEmprestimo));
    Aluno::EstAluno *q = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
    Manuais::EstManual *r = (Manuais::EstManual*) malloc(sizeof(Manuais::EstManual));

    cout << "\n** Pesquisar Emprestimos por Nome **\n" << endl;
    cout << "Nome: ";
    cin >> nome;
    for(p=emprestimos->prox;p!=NULL;p=p->prox)
    {
        for(q=alunos->prox;q!=NULL;q=q->prox)
        {
            for(r=manuais->prox;r!=NULL;r=r->prox)
            {
                if(p->id_aluno==q->num_proc&&strcmp(p->id_manual,r->isbn)==0)
                {
                    if(strcmp(q->nome,nome)==0)
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

void Emprestimo::PesquisarEmprestimoAno(Emprestimo::EstEmprestimo *emprestimos,Aluno::EstAluno *alunos,Manuais::EstManual *manuais)
{
    int ano;
    bool encontrou=false;
    Emprestimo::EstEmprestimo *p = (Emprestimo::EstEmprestimo*) malloc(sizeof(Emprestimo::EstEmprestimo));
    Aluno::EstAluno *q = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
    Manuais::EstManual *r = (Manuais::EstManual*) malloc(sizeof(Manuais::EstManual));

    cout << "\n** Pesquisar Emprestimos por Ano **\n" << endl;
    cout << "Ano: ";
    cin >> ano;
    for(p=emprestimos->prox;p!=NULL;p=p->prox)
    {
        for(q=alunos->prox;q!=NULL;q=q->prox)
        {
            for(r=manuais->prox;r!=NULL;r=r->prox)
            {
                if(p->id_aluno==q->num_proc&&strcmp(p->id_manual,r->isbn)==0)
                {
                    if(q->ano==ano)
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

void Emprestimo::PesquisarEmprestimoTurma(Emprestimo::EstEmprestimo *emprestimos,Aluno::EstAluno *alunos,Manuais::EstManual *manuais)
{
    char turma[10];
    bool encontrou=false;
    Emprestimo::EstEmprestimo *p = (Emprestimo::EstEmprestimo*) malloc(sizeof(Emprestimo::EstEmprestimo));
    Aluno::EstAluno *q = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
    Manuais::EstManual *r = (Manuais::EstManual*) malloc(sizeof(Manuais::EstManual));

    cout << "\n** Pesquisar Emprestimos por Turma **\n" << endl;
    cout << "Turma: ";
    cin >> turma;
    for(p=emprestimos->prox;p!=NULL;p=p->prox)
    {
        for(q=alunos->prox;q!=NULL;q=q->prox)
        {
            for(r=manuais->prox;r!=NULL;r=r->prox)
            {
                if(p->id_aluno==q->num_proc&&strcmp(p->id_manual,r->isbn)==0)
                {
                    if(strcmp(q->turma,turma)==0)
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

void Emprestimo::PesquisarEmprestimoTelemovel(Emprestimo::EstEmprestimo *emprestimos,Aluno::EstAluno *alunos,Manuais::EstManual *manuais)
{
    char telemovel[15];
    bool encontrou=false;
    Emprestimo::EstEmprestimo *p = (Emprestimo::EstEmprestimo*) malloc(sizeof(Emprestimo::EstEmprestimo));
    Aluno::EstAluno *q = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
    Manuais::EstManual *r = (Manuais::EstManual*) malloc(sizeof(Manuais::EstManual));

    cout << "\n** Pesquisar Emprestimos por Telemovel **\n" << endl;
    cout << "Telemovel: ";
    cin >> telemovel;
    for(p=emprestimos->prox;p!=NULL;p=p->prox)
    {
        for(q=alunos->prox;q!=NULL;q=q->prox)
        {
            for(r=manuais->prox;r!=NULL;r=r->prox)
            {
                if(p->id_aluno==q->num_proc&&strcmp(p->id_manual,r->isbn)==0)
                {
                    if(strcmp(q->telemovel,telemovel)==0)
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

void Emprestimo::PesquisarEmprestimoTitulo(Emprestimo::EstEmprestimo *emprestimos,Aluno::EstAluno *alunos,Manuais::EstManual *manuais)
{
    char titulo[30];
    bool encontrou=false;
    Emprestimo::EstEmprestimo *p = (Emprestimo::EstEmprestimo*) malloc(sizeof(Emprestimo::EstEmprestimo));
    Aluno::EstAluno *q = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
    Manuais::EstManual *r = (Manuais::EstManual*) malloc(sizeof(Manuais::EstManual));

    cout << "\n** Pesquisar Emprestimos por Titulo **\n" << endl;
    cout << "Titulo: ";
    cin >> titulo;
    for(p=emprestimos->prox;p!=NULL;p=p->prox)
    {
        for(q=alunos->prox;q!=NULL;q=q->prox)
        {
            for(r=manuais->prox;r!=NULL;r=r->prox)
            {
                if(p->id_aluno==q->num_proc&&strcmp(p->id_manual,r->isbn)==0)
                {
                    if(strcmp(r->titulo,titulo)==0)
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

void Emprestimo::PesquisarEmprestimoDisciplina(Emprestimo::EstEmprestimo *emprestimos,Aluno::EstAluno *alunos,Manuais::EstManual *manuais)
{
    char disciplina[20];
    bool encontrou=false;
    Emprestimo::EstEmprestimo *p = (Emprestimo::EstEmprestimo*) malloc(sizeof(Emprestimo::EstEmprestimo));
    Aluno::EstAluno *q = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
    Manuais::EstManual *r = (Manuais::EstManual*) malloc(sizeof(Manuais::EstManual));

    cout << "\n** Pesquisar Emprestimos por Disciplina **\n" << endl;
    cout << "Disciplina: ";
    cin >> disciplina;
    for(p=emprestimos->prox;p!=NULL;p=p->prox)
    {
        for(q=alunos->prox;q!=NULL;q=q->prox)
        {
            for(r=manuais->prox;r!=NULL;r=r->prox)
            {
                if(p->id_aluno==q->num_proc&&strcmp(p->id_manual,r->isbn)==0)
                {
                    if(strcmp(r->disciplina,disciplina)==0)
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

void Emprestimo::PesquisarEmprestimoValor(Emprestimo::EstEmprestimo *emprestimos,Aluno::EstAluno *alunos,Manuais::EstManual *manuais)
{
    float valor;
    bool encontrou=false;
    Emprestimo::EstEmprestimo *p = (Emprestimo::EstEmprestimo*) malloc(sizeof(Emprestimo::EstEmprestimo));
    Aluno::EstAluno *q = (Aluno::EstAluno*) malloc(sizeof(Aluno::EstAluno));
    Manuais::EstManual *r = (Manuais::EstManual*) malloc(sizeof(Manuais::EstManual));

    cout << "\n** Pesquisar Emprestimos por Valor **\n" << endl;
    cout << "Valor: ";
    cin >> valor;
    for(p=emprestimos->prox;p!=NULL;p=p->prox)
    {
        for(q=alunos->prox;q!=NULL;q=q->prox)
        {
            for(r=manuais->prox;r!=NULL;r=r->prox)
            {
                if(p->id_aluno==q->num_proc&&strcmp(p->id_manual,r->isbn)==0)
                {
                    if(p->valor==valor)
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
