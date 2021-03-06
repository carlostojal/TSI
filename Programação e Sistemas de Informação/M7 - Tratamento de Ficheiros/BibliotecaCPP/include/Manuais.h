#ifndef MANUAIS_H
#define MANUAIS_H
#include <string>

using namespace std;


class Manuais
{
    public:
        typedef struct EstManual {
            char isbn[20];
            //char titulo[30];
            string titulo;
            char disciplina[20];
            struct EstManual *prox;
            struct EstManual *ant;
        } EstManual;

        Manuais();
        void AdicionarManual(Manuais::EstManual *lista);
        void LimparManuais(Manuais::EstManual *lista);
        void CarregarManuais(Manuais::EstManual *lista);
        void ListarManual(Manuais::EstManual *manual);
        void PesquisarManualISBN(Manuais::EstManual *lista);
        void PesquisarManuaisTitulo(Manuais::EstManual *lista);
        void PesquisarManuaisDisciplina(Manuais::EstManual *lista);

    protected:

    private:
};

#endif // MANUAIS_H
