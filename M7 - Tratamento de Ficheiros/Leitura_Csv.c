#include <stdio.h>
#include <stdlib.h>

typedef struct linhas {
    char nome[20];
    int altura;
    int kg;
    char telef[20];
    struct linhas *prox;
}linha;

int menu();
void ler_dados(linha *novo);
void escrever_ficheiro(linha *novo);

int main()
{
    int opt;
    linha *temp = (linha*) malloc(sizeof(linha));
    linha *lista = (linha*) malloc(sizeof(linha));
    lista->prox = NULL;
    do{
        opt=menu();
        switch(opt)
        {
            case 1:
                ler_dados(temp);
                escrever_ficheiro(temp);
                break;
        }
    }while(opt);
    return 0;
}

int menu()
{
    int opt;
    do{
        printf("\n** Leitura_Csv **\n\n");
        printf("1. Adicionar leitura\n");
        printf("0. Sair\n\n");
        printf("Opcao: ");
        scanf("%d",&opt);
    }while(opt<0||opt>2);
    return opt;
}

void ler_dados(linha *novo)
{
    printf("\nNome: ");
    fflush(stdin);
    //gets(novo->nome);
    scanf("%s",novo->nome);
    printf("Altura: ");
    scanf("%d",&novo->altura);
    printf("Peso: ");
    scanf("%d",&novo->kg);
    printf("Telefone: ");
    fflush(stdin);
    //gets(novo->telef);
    scanf("%s",novo->telef);
}

void escrever_ficheiro(linha *novo)
{
    FILE *fp;
    fp = fopen("dados.csv","a");
    fprintf(fp,"%s %d %d %s\n",novo->nome,novo->altura,novo->kg,novo->telef);
    fclose(fp);
}
