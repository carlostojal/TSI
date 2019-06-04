#ifndef ALUNO_H
#define ALUNO_H

#include <iostream>
using namespace std;

class Aluno
{
    public:
        typedef struct EstAluno {
            int num_proc;
            string nome;
            int ano;
            string turma;
            string telemovel;
            struct EstAluno *ant;
            struct EstAluno *prox;
        } EstAluno;

        Aluno();
        AdicionarAluno(Aluno::EstAluno *lista);
        LimparAlunos(Aluno::EstAluno *lista);
        CarregarAlunos(Aluno::EstAluno *lista);

    protected:

    private:
};

#endif // ALUNO_H
