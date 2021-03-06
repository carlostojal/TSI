#ifndef ALUNO_H
#define ALUNO_H

#include <iostream>
using namespace std;

class Aluno
{
    public:
        typedef struct EstAluno {
            int num_proc;
            char nome[30];
            int ano;
            char turma[10];
            char telemovel[15];
            struct EstAluno *ant;
            struct EstAluno *prox;
        } EstAluno;

        Aluno();
        void AdicionarAluno(Aluno::EstAluno *lista);
        void LimparAlunos(Aluno::EstAluno *lista);
        void CarregarAlunos(Aluno::EstAluno *lista);
        void ListarAluno(Aluno::EstAluno *aluno);
        void PesquisarAlunoNumProc(Aluno::EstAluno *lista);
        void PesquisarAlunoNome(Aluno::EstAluno *lista);
        void PesquisarAlunoAno(Aluno::EstAluno *lista);
        void PesquisarAlunosTurma(Aluno::EstAluno *lista);
        void PesquisarAlunosTelemovel(Aluno::EstAluno *lista);

    protected:

    private:
};

#endif // ALUNO_H
