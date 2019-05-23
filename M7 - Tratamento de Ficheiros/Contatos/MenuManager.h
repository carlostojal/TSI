#include <stdio.h>

int MainMenu()
{
    int opt;
    do{
        printf("\n** Contatos **\n\n");
        printf("1. Adicionar Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Remover Contato\n");
        printf("0. Sair\n\n");
        printf("Opcao: ");
        scanf("%d",&opt);
    }while(opt<0||opt>3);
    return opt;
}
