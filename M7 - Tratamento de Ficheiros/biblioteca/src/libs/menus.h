//Carlos Tojal, nº5, 1ºTSI
//https://www.github.com/carlostojal/TSI/tree/master/M7 - Tratamento de Ficheiros/biblioteca/src/libs/menus.h

//Contém os menus do programa

#include <stdio.h>

int menu()
{
    int opt;
    do{
        printf("\n** Biblioteca **\n\n");
        printf("1. Alunos\n");
        printf("2. Manuais\n");
        printf("3. Emprestimos\n");
        printf("4. Listagens\n");
        printf("0. Sair\n\n");
        printf("Opcao: ");
        scanf("%d",&opt);
    }while(opt<0||opt>4);
    return opt;
}

int menu_alunos()
{
    int opt;
    do{
        printf("\n** Alunos **\n\n");
        printf("1. Adicionar\n");
        printf("2. Listar\n");
        printf("3. Pesquisar\n");
        printf("0. Sair\n\n");
        printf("Opcao: ");
        scanf("%d",&opt);
    }while(opt<0||opt>3);
    return opt;
}

int menu_manuais()
{
    int opt;
    do{
        printf("\n** Manuais **\n\n");
        printf("1. Adicionar\n");
        printf("2. Listar\n");
        printf("3. Pesquisar\n");
        printf("0. Sair\n\n");
        printf("Opcao: ");
        scanf("%d",&opt);
    }while(opt<0||opt>3);
    return opt;
}

int menu_emprestimos()
{
    int opt;
    do{
        printf("\n** Emprestimos **\n\n");
        printf("1. Adicionar\n");
        printf("2. Listar\n");
        printf("3. Pesquisar\n");
        printf("0. Sair\n\n");
        printf("Opcao: ");
        scanf("%d",&opt);
    }while(opt<0||opt>3);
    return opt;
}
