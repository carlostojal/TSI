#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct {
    int dia;
    int mes;
    int ano;
}Data;

typedef struct {
    int num;
    char Nome[30];
    char Telef[12];
    char email[30];
    Data Dt_nasc;
    struct Agenda *prox;
}Ficha;

int tam;
int last;

void opcao(Ficha *LISTA,int op);
void inicia(Ficha *LISTA);
void insere(Ficha *LISTA);
void insereFim(Ficha *LISTA);
void insereInicio(Ficha *LISTA);
void listar(Ficha *LISTA);
void liberta(Ficha *LISTA);
Ficha *criaNo();
Ficha *aloca();
Ficha *retiraInicio(Ficha *LISTA);
Ficha *retiraFim(Ficha *LISTA);
Ficha *retira(Ficha *LISTA);

int menu()
{
    int opt;

    do{
        system("cls");
        printf("Escolha a opcao\n");
        printf("0. Sair\n");
        printf("1. Limpar todos os contatos\n");
        printf("2. Mostrar contatos\n");
        printf("3. Adicionar contato\n");
        printf("4. Apagar contato\n");
        printf("Opcao: ");
        scanf("%d",&opt);
    }while(opt<0||opt>4);
    return opt;
}

void main()
{
    Ficha *LISTA = (Ficha*)malloc(sizeof(Ficha));
    if(!LISTA)
    {
        printf("Memoria insuficiente\n");
        exit(1);
    }
    else
    {
        inicia(LISTA);
        int opt;
        do{
            opt=menu();
            opcao(LISTA,opt);
        }while(opt);
        free(LISTA);
        return 0;
    }
}

void inicia(Ficha *LISTA)
{
    LISTA->prox = NULL;
    last=tam=0;
}

void opcao(Ficha *LISTA,int op)
{
    Ficha *tmp;
    switch(op)
    {
        case 0:
            escreve_ficha(LISTA);
            liberta(LISTA);
            break;
        case 1:
            liberta(LISTA);
            inicia(LISTA);
            break;
        case 2:
            listar(LISTA);
            break;
        case 3:
            insereFim(LISTA);
            break;
        case 4:
            retira(LISTA);
            break;
    }
}

void liberta(Ficha *LISTA)
{
    if(!vazia(LISTA))
    {
        Ficha *proxRegisto, *atual;

        atual = LISTA->prox;
        while(atual!=NULL)
        {
            proxRegisto = atual->prox;
            free(atual);
            atual = proxRegisto;
        }
    }
}

void insere(Ficha *LISTA)
{
    int pos,count;

    printf("Em que posicao [de 1 a %d] deseja inserir: ",tam);
    scanf("%d",&pos);
    if(pos>0&&pos<=tam)
    {
        if(pos==1)
            insereInicio(LISTA);
        else
        {
            Ficha *atual = LISTA->prox, *anterior=LISTA;
            Ficha *novo=aloca();
            for(count=1;count<pos;count++)
            {
                anterior = atual;
                atual=atual->prox;
            }
            anterior->prox = novo;
            novo->prox = atual;
            last=tam++;
        }
    }
    else
        printf("\nElemento invalido\n");
}

int vazia(Ficha *LISTA)
{
    if(LISTA->prox==NULL)
        return 1;
    else
        return 0;
}

Ficha *aloca(int ID)
{
    Ficha *novo = (Ficha *)malloc(sizeof(Ficha));
    if(!novo)
    {
        printf("Sem memoria\n");
        exit(1);
    }
    else
    {
        novo->num=last+1;
        printf("\nContato N: %d\n",novo->num);
        printf("Nome: ");fflush(stdin);gets(novo->Nome);
        printf("Telef: ");fflush(stdin);gets(novo->Telef);
        printf("Email: ");fflush(stdin);gets(novo->email);
        printf("Data de nasc: ");scanf("%d/%d/%d",&novo->Dt_nasc.dia,&novo->Dt_nasc.mes,&novo->Dt_nasc.ano);
    }
}

void listar(Ficha *LISTA)
{
    char op;
    system("cls");
    if(vazia(LISTA))
    {
        printf("Lista vazia!\n");
        getch();
        return;
    }
    Ficha *tmp;
    tmp = LISTA->prox;
    printf("Lista: ");
    while(tmp!=NULL)
    {
        printf("\nID: %d\n",tmp->num);
        printf("Nome: %s\n",tmp->Nome);
        printf("Telefone: %s\n",tmp->Telef);
        printf("Email: %s\n",tmp->email);
        printf("Data de Nascimento: %d/%d/%d\n",tmp->Dt_nasc.dia,tmp->Dt_nasc.mes,tmp->Dt_nasc.ano);
        tmp=tmp->prox;
        printf("\nEsc para terminar outra tecla para continuar...\n");
        op=getch();
        if(op==27) break;
    }
}

void insereInicio(Ficha *LISTA)
{
    Ficha *novo=aloca(tam);
    Ficha *oldHead = LISTA->prox;
    LISTA->prox = novo;
    novo->prox = oldHead;
    last=tam++;
}

void insereFim(Ficha *LISTA)
{
    Ficha *novo=aloca(tam);
    novo->prox=NULL;
    if(vazia(LISTA))
        LISTA->prox=novo;
    else
    {
        Ficha *tmp = LISTA->prox;
        while(tmp->prox!=NULL)
            tmp=tmp->prox;
        tmp->prox = novo;
    }
}

Ficha *retiraInicio(Ficha *LISTA)
{

}

Ficha *retiraFim(Ficha *LISTA)
{
    if(LISTA->prox==NULL)
    {
        printf("Lista ja esta vazia\n");
        return NULL;
    }
    else
    {
        Ficha *ultimo = LISTA->prox, *penultimo = LISTA;
        while(ultimo->prox != NULL)
        {
            penultimo = ultimo;
        }
    }
}

Ficha *retira(Ficha *LISTA)
{
    int opt;
    Ficha *atual = LISTA->prox;
    printf("Qual o numero do contato que deseja remover [%d a %d]: ",atual->num,last);
    scanf("%d",&opt);
    if(opt>=atual->num&&opt<=last)
    {
        if(opt==atual->num)
        {
            return retiraInicio(LISTA);
            tam--;
        }else {
            Ficha *anterior = LISTA;
            while(atual->num<opt)
            {
                anterior=atual;
                atual=atual->prox;
            }
            if(atual->prox!=NULL)
            {
                anterior->prox=atual->prox;
                tam--;
                return atual;
            }else if(atual->num>opt) {
                printf("Elemento inexistente\n\n");
                getch();
                return NULL;
            }
        }
    }else {
        printf("Elemento inexistente\n\n");getch();
        return NULL;
    }
}

void escreve_ficha(Ficha *LISTA)
{
    Ficha *tmp;
    FILE *fp;
    tmp = LISTA->prox;
    fp=fopen("agenda.txt","w+");
    while(tmp!=NULL)
    {
        fprintf(fp,"%d;%s;%s;%d;%d/%d/%d\n",tmp->num,tmp->Nome,tmp->Telef,tmp->email,tmp->Dt_nasc);
        tmp = tmp->prox;
    }
}
