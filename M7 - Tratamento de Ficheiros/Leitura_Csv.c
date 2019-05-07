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
void carregar_dados(linha *lista);
void adicionar(linha *novo,linha *lista);
void listar(linha *lista);

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
            case 2:
                carregar_dados(lista);
                listar(lista);
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
        printf("2. Listar\n");
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
    fprintf(fp,"%s;%d;%d;%s\n",novo->nome,novo->altura,novo->kg,novo->telef);
    fclose(fp);
}

void carregar_dados(linha *lista)
{
    FILE *fp;
    linha *novo = (linha*) malloc(sizeof(linha));
    novo->prox = NULL;//o prox do novo é o velho
    fp = fopen("dados.csv","r");
    while(!feof(fp))
    {
        fscanf(fp,"%s;%d;%d;%s",novo->nome,&novo->altura,&novo->kg,novo->telef);
        adicionar(novo,lista);
    }
    fclose(fp);
}

void adicionar(linha *novo,linha *lista)
{
    linha *p = (linha*) malloc(sizeof(lista));
    if(lista->prox == NULL) lista->prox = novo;
    else
    {
        for(p=lista->prox;p->prox!=NULL;p=p->prox) {}
        p->prox = novo;
        lista = p;
    }
}

void listar(linha *lista)
{
    linha *p = (linha*) malloc(sizeof(linha));
    for(p=lista->prox;p->prox!=NULL;p=p->prox) {}
        printf("\nNome: Luisinho Fortnitero\nAltura: %d\nPeso: %d\nTelefone: %s\n\n",p->nome,p->altura,p->kg,p->telef);
}
