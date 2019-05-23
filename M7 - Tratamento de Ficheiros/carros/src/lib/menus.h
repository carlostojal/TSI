#include <stdio.h>

int main_menu()
{
    int opt;
    do{
        printf("\n** Carros **\n\n");
        printf("1. Adicionar carro\n");
        printf("2. Listar carros\n");
        printf("3. Atualizar inspeção\n");
        printf("0. Sair\n\n");
        printf("Opcao: ");
        scanf("%d",&opt);
    }while(opt<0||opt>3);
}
