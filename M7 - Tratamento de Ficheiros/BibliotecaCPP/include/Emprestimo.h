#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H


class Emprestimo
{
    public:
        typedef struct EstEmprestimo {
            int id;
            int id_aluno;
            int id_manual;
            float valor;
            struct EstEmprestimo *prox;
            struct EstEmprestimo *ant;
        } EstEmprestimo;

        Emprestimo();
        int AdquirirID(Emprestimo::EstEmprestimo *lista);
        void AdicionarEmprestimo(Emprestimo::EstEmprestimo *lista);
        void LimparEmprestimos(Emprestimo::EstEmprestimo *lista);
        void CarregarEmprestimos(Emprestimo::EstEmprestimo *lista);
        void ListarEmprestimo(Emprestimo::EstEmprestimo *emprestimo);

    protected:

    private:
};

#endif // EMPRESTIMO_H
