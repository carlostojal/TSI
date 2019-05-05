#include <stdio.h>
#include <string.h>

int menu();
void criar();
void acrescentar();
void ler();

int main()
{
    int opt;
    do{
        opt = menu();
        switch(opt)
        {
            case 1:
                criar();
                break;
            case 2:
                acrescentar();
                break;
            case 3:
                ler();
                break;
        }
    }while(opt);
    return 0;
}

int menu()
{
    int opt;
    do{
        printf("\n** Ficheiros **\n\n");
        printf("1. Criar ficheiro\n");
        printf("2. Acrescentar ao ficheiro\n");
        printf("3. Ler ficheiro\n");
        printf("0. Sair\n\n");
        printf("Opcao: ");
        scanf("%d",&opt);
    }while(opt<0||opt>3);
    return opt;
}

void criar()
{
    char filename[20];
    char conteudo[50];
    FILE *fp;
    printf("\nNome do ficheiro: ");
    scanf("%s",filename);
    strcat(filename,".txt");
    printf("Conteudo: ");
    scanf("%s",conteudo);
    fp = fopen(filename,"w");
    fprintf(fp,"%s\n",conteudo);
    fclose(fp);
}

void acrescentar()
{
    char filename[20];
    char conteudo[50];
    FILE *fp;
    printf("\nNome do ficheiro: ");
    scanf("%s",filename);
    strcat(filename,".txt");
    printf("Conteudo: ");
    scanf("%s",conteudo);
    fp = fopen(filename,"a");
    fprintf(fp,"%s\n",conteudo);
    fclose(fp);
}

void ler()
{
    char filename[20];
    char conteudo[50];
    FILE *fp;
    printf("\nNome do ficheiro: ");
    scanf("%s",filename);
    strcat(filename,".txt");
    fp = fopen(filename,"r");
    fgets(conteudo,50,fp);
    fclose(fp);
    printf("\n%s\n",conteudo);
}
