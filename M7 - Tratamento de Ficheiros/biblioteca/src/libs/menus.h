//Carlos Tojal, nº5, 1ºTSI
//https://www.github.com/carlostojal/TSI/tree/master/M7 - Tratamento de Ficheiros/biblioteca/src/libs/menus.h
//biblioteca/src/libs/menus.h

//Contém os menus do programa

#include <stdio.h>

//Menu principal
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
    }while(opt<0||opt>4); //repete enquanto a opção selecionada for inválida
    return opt;
}

//Submenu (Recebe o título como argumento) (opções 1, 2 e 3 do menu principal)
int submenu(char *tipo)
{
    int opt;
    do{
        printf("\n** %s **\n\n",tipo);
        printf("1. Adicionar\n");
        printf("2. Listar\n");
        printf("3. Pesquisar\n");
        printf("0. Voltar\n\n");
        printf("Opcao: ");
        scanf("%d",&opt);
    }while(opt<0||opt>3); //repete enquanto a opção selecionada for inválida
    return opt;
}

//Menu das listagens (opção 4 do menu principal)
int menu_listagens()
{
    int opt;

}
