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
