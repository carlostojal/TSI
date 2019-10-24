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
        printf("0. Sair\n\n");
        printf("Opcao: ");
        scanf("%d",&opt);
    }while(opt<0||opt>3); //repete enquanto a opção selecionada for inválida
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

int menu_pesquisas(int tipo)
{
    int opt;
    if(tipo==1)
    {
        do{
            printf("\n** Pesquisar Alunos**\n\n");
            printf("1. Numero de processo\n");
            printf("2. Nome\n");
            printf("3. Ano\n");
            printf("4. Turma\n");
            printf("5. Telemovel\n");
            printf("0. Voltar ao inicio\n\n");
            printf("Opcao: ");
            scanf("%d",&opt);
        }while(opt<0||opt>5);
    }
    else if(tipo==2)
    {
        do{
            printf("\n** Pesquisar Manuais**\n\n");
            printf("1. ISBN\n");
            printf("2. Titulo\n");
            printf("3. Disciplina\n");
            printf("0. Voltar ao inicio\n\n");
            printf("Opcao: ");
            scanf("%d",&opt);
        }while(opt<0||opt>3);
    }
    else
    {
        do{
            printf("\n** Pesquisar Emprestimos **\n\n");
            printf("1. ID do Emprestimo\n");
            printf("2. ID do Aluno\n");
            printf("3. ID do Manual\n");
            printf("4. Data de Levantamento\n");
            printf("5. Valor\n");
            printf("6. Nome do Aluno\n");
            printf("7. Ano do Aluno\n");
            printf("8. Turma do Aluno\n");
            printf("9. Telemovel do Aluno\n");
            printf("10. Titulo do Manual\n");
            printf("11. Disciplina do Manual\n");
            printf("0. Voltar ao inicio\n\n");
            printf("Opcao: ");
            scanf("%d",&opt);
        }while(opt<0||opt>11);
    }
    return opt;
}
