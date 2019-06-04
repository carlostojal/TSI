#include "Aluno.h"
using namespace std;

Aluno::Aluno()
{
    //ctor
}

Aluno::AdicionarAluno()
{
    cout << "\n** Adicionar Aluno **\n" << endl;
    cout << "Numero de processo: ";
    cin >> Aluno::num_proc;
    cout << "Nome: ";
    cin >> Aluno::nome;
    cout << "Ano: ";
    cin >> Aluno::ano;
    cout << "Turma: ";
    cin >> Aluno::turma;
    cout << "Telemovel: ";
    cin >> Aluno::telemovel;
}
