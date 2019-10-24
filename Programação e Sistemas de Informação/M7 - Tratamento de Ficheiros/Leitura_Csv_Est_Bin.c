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
    fp = fopen("dados.dat","ab");
    fprintf(fp,"%s %d %d %s\n",novo->nome,novo->altura,novo->kg,novo->telef);
    fclose(fp);
}

void adicionar(linha *novo,linha *lista)
{
    linha *p = (linha*) malloc(sizeof(lista));
    p=lista->prox;

    if (lista->prox == NULL)
        lista->prox = novo;
    else
    {
        linha *tmp;
        tmp=lista->prox;
        while (tmp->prox != NULL)
            tmp = tmp->prox;
        tmp->prox = novo;
    }
}

void carregar_dados(linha *lista)
{
    FILE *fp;
    fp = fopen("dados.dat","rb");
    while(!feof(fp))
    {
        linha *novo = (linha*) malloc(sizeof(linha));
        fscanf(fp,"%s %d %d %s",&novo->nome,&novo->altura,&novo->kg,&novo->telef);
        novo->prox = NULL;
        adicionar(novo,lista);
    }
    fclose(fp);
}

void listar(linha *lista)
{
    int total_altura=0,total_peso=0;
    int n=0;
    linha *p = (linha*) malloc(sizeof(linha));
    for(p=lista->prox;p!=NULL;p=p->prox)
    {
        printf("\nNome: %s\nAltura: %d\nPeso: %d\nTelefone: %s\n\n",p->nome,p->altura,p->kg,p->telef);
        total_altura+=p->altura;
        total_peso+=p->kg;
        n++;
    }
    printf("\nMedia de alturas: %.2f",(float)total_altura/n);
    printf("\nMedia de pesos: %.2f\n",(float)total_peso/n);
}
