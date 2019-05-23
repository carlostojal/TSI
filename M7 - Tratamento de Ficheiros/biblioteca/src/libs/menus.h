//Carlos Tojal, nº5, 1ºTSI
//https://www.github.com/carlostojal/TSI/tree/master/M7 - Tratamento de Ficheiros/biblioteca/src/libs/menus.h



//Contém os menus do programa

#include <stdio.h>

int menu()
{
    int opt;
    do{
        printf("\n** Biblioteca **\n\n");
        printf("1. Inserir aluno\n");
        printf("2. Listar alunos\n");
        printf("3. Adicionar manual\n");
        printf("4. Listar manuais\n");
        printf("5. Adicionar empréstimo\n");
        printf("6. Listar empréstimos\n");
        printf("0. Sair\n\n");
        printf("Opcao: ");
        scanf("%d",&opt);
    }while(opt<0||opt>6);
    return opt;
}
