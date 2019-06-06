#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "Aluno.h"
#include "Manuais.h"


class Emprestimo
{
    public:
        typedef struct EstEmprestimo {
            int id;
            int id_aluno;
            char id_manual[20];
            float valor;
            struct EstEmprestimo *prox;
            struct EstEmprestimo *ant;
        } EstEmprestimo;

        Emprestimo();
        int AdquirirID(Emprestimo::EstEmprestimo *lista);
        void AdicionarEmprestimo(Emprestimo::EstEmprestimo *lista);
        void LimparEmprestimos(Emprestimo::EstEmprestimo *lista);
        void CarregarEmprestimos(Emprestimo::EstEmprestimo *lista);
        void ListarEmprestimo(Emprestimo::EstEmprestimo *emprestimo,Aluno::EstAluno *aluno,Manuais::EstManual *manual);
        void PesquisarEmprestimoID(Emprestimo::EstEmprestimo *emprestimos,Aluno::EstAluno *alunos,Manuais::EstManual *manuais);
        void PesquisarEmprestimoNumProc(Emprestimo::EstEmprestimo *emprestimos,Aluno::EstAluno *alunos,Manuais::EstManual *manuais);
        void PesquisarEmprestimoISBN(Emprestimo::EstEmprestimo *emprestimos,Aluno::EstAluno *alunos,Manuais::EstManual *manuais);
        void PesquisarEmprestimoNome(Emprestimo::EstEmprestimo *emprestimos,Aluno::EstAluno *alunos,Manuais::EstManual *manuais);
        void PesquisarEmprestimoAno(Emprestimo::EstEmprestimo *emprestimos,Aluno::EstAluno *alunos,Manuais::EstManual *manuais);
        void PesquisarEmprestimoTurma(Emprestimo::EstEmprestimo *emprestimos,Aluno::EstAluno *alunos,Manuais::EstManual *manuais);
        void PesquisarEmprestimoTelemovel(Emprestimo::EstEmprestimo *emprestimos,Aluno::EstAluno *alunos,Manuais::EstManual *manuais);
        void PesquisarEmprestimoTitulo(Emprestimo::EstEmprestimo *emprestimos,Aluno::EstAluno *alunos,Manuais::EstManual *manuais);
        void PesquisarEmprestimoDisciplina(Emprestimo::EstEmprestimo *emprestimos,Aluno::EstAluno *alunos,Manuais::EstManual *manuais);

    protected:

    private:
};

#endif // EMPRESTIMO_H
