#include <iostream>
#include "Menus.h"
#include "Aluno.h"

using namespace std;

int main()
{
    Menus menus;
    Aluno aluno;
    int opt,subopt;
    do{
        opt = menus.Menu();
        switch(opt)
        {
            case 1:
                subopt = menus.SubMenu("Alunos");
                switch(subopt)
                {
                    case 1:
                        aluno.AdicionarAluno();
                        break;
                }
                break;
        }
    }while(opt);
    return 0;
}
