#include "Manuais.h"
#include <fstream>
#include <iostream>
using namespace std;

Manuais::Manuais()
{
    //ctor
}

void Manuais::AdicionarManual(Manuais::EstManual *lista)
{
    ofstream fp;
    Manuais::EstManual manual;

    cout << "\n** Adicionar Manual **\n" << endl;
    cout << "ISBN: ";
    cin >> manual.isbn;
    cout << "Titulo: ";
    cin >> manual.titulo;
    cout << "Disciplina: ";
    cin >> manual.disciplina;

    fp.open("manuais.tsv",ios_base::app);
    fp << manual.isbn << "\t" << manual.titulo << "\t" << manual.disciplina;
    fp.close();
}

void Manuais::LimparManuais(Manuais::EstManual *lista)
{
    Manuais::EstManual *p = (Manuais::EstManual*) malloc(sizeof(Manuais::EstManual));

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

void Manuais::CarregarManuais(Manuais::EstManual *lista)
{
    ifstream fp;
    Manuais::EstManual *p = (Manuais::EstManual*) malloc(sizeof(Manuais::EstManual));
    fp.open("manuais.tsv");

    while(!fp.eof())
    {
        Manuais::EstManual *novo = (Manuais::EstManual*) malloc(sizeof(Manuais::EstManual));
        novo->ant = NULL;
        novo->prox = NULL;

        fp >> novo->isbn >> novo->titulo >> novo->disciplina;

        if(lista->prox==NULL)
        {
            lista->prox = novo;
            novo->ant = lista;
        }
        else
        {
            for(p=lista->prox;p->prox!=NULL;p=p->prox) {}
            p->prox = novo;
            novo->ant = p;
        }
    }
    fp.close();
}

void Manuais::ListarManual(Manuais::EstManual *manual)
{
    cout << "\nISBN: " << manual->isbn << endl;
    cout << "Titulo: " << manual->titulo << endl;
    cout << "Disciplina: " << manual->disciplina << endl;
}
