#include "Menus.h"
using namespace std;

Menus::Menus()
{
    //ctor
}

int Menus::Menu()
{
    int opt;
    do{
        cout << "\n** BibliotecaCPP **\n" << endl;
        cout << "1. Alunos" << endl;
        cout << "2. Manuais" << endl;
        cout << "3. Emprestimos" << endl;
        cout << "0. Sair\n" << endl;
        cout << "Opcao: ";
        cin >> opt;
    }while(opt<0||opt>3);
    return opt;
}

int Menus::SubMenu(string tipo)
{
    int opt;
    do{
        cout << "\n** " << tipo << " **\n" <<endl;
        cout << "1. Adicionar" << endl;
        cout << "2. Listar" <<endl;
        cout << "3. Pesquisar" <<endl;
        cout << "0. Voltar\n" << endl;
        cout << "Opcao: ";
        cin >> opt;
    }while(opt<0||opt>3);
    return opt;
}

int Menus::SubSubMenu(int tipo)
{
    int opt;
    if(tipo==1) //Alunos
    {
        do{
            cout << "\n** Pesquisar Alunos **\n" << endl;
            cout << "1. Numero de Processo" << endl;
            cout << "2. Nome" << endl;
            cout << "3. Ano" << endl;
            cout << "4. Turma" << endl;
            cout << "5. Telemovel" << endl;
            cout << "0. Voltar ao inicio\n" << endl;
            cout << "Opcao: ";
            cin >> opt;
        }while(opt<0||opt>5);
        return opt;
    }
    else if(tipo==2) //Manuais
    {
        do{
            cout << "\n** Pesquisar Manuais **\n" << endl;
            cout << "1. ISBN" << endl;
            cout << "2. Titulo" << endl;
            cout << "3. Disciplina" << endl;
            cout << "0. Voltar ao inicio\n" << endl;
            cout << "Opcao: ";
            cin >> opt;
        }while(opt<0||opt>3);
        return opt;
    }
    else //Empréstimos
    {
        do{
            cout << "\n** Pesquisar Emprestimos **\n" << endl;
            cout << "1. ID" << endl;
            cout << "2. Numero de Processo do Aluno" << endl;
            cout << "3. Nome do Aluno" << endl;
            cout << "4. Ano do Aluno" << endl;
            cout << "5. Turma do Aluno" << endl;
            cout << "6. Telemovel do Aluno" << endl;
            cout << "7. ISBN no Manual" << endl;
            cout << "8. Titulo do Manual" << endl;
            cout << "9. Disciplina do Manual" << endl;
            cout << "10. Valor" << endl;
            cout << "0. Voltar ao inicio\n" << endl;
            cout << "Opcao: ";
            cin >> opt;
        }while(opt<0||opt>10);
        return opt;
    }
}
