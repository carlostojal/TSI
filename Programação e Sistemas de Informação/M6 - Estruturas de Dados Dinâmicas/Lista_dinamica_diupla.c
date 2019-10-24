#include <stdio.h>
#include <stdlib.h>

typedef struct lista2 {
    int num;
    struct lista2 *ant;
    struct lista2 *prox;
}Lista2;

Lista2* inicializa(void);
void imprime(Lista2 *list);
Lista2* insere(Lista2 *list, int v);
Lista2* insere_ord(Lista2 *list, int v);
Lista2* procura(Lista2 *list, int v);
Lista2* elimina(Lista2 *list, int v);

int main()
{
    Lista2 *list;
    Lista2 *proc;
    char op;
    int num;
    list = inicializa();
    do{
        printf("Introduza um valor para a lista: ");
        scanf("%d",&num);
        //list = insere_ord(list,num);
        list = insere(list,num);
        imprime(list);
        printf("\n\nDeseja adicionar outro elemento (S/N):");
        fflush(stdin);
        op = getchar();
    }while(op!='n'&&op!='N');
    do{
        printf("\nIntroduza um valor a pesquisar: ");
        scanf("%d",&num);
        proc = procura(list,num);
        if(proc==NULL)
           printf("\nRegisto nao encontrado!");
        else
        {
            printf("\nO registo %d nao foi encontrado",proc->num);
            if(proc->ant!=NULL)
                printf("\nTem o elemento %d como antecessor.",(proc->ant)->num);
            else printf("\nE o primeito elemento.");
            if(proc->prox==NULL)
                printf("\nTem o elemento %d como sucessor.",(proc->prox)->num);
            else printf("\nE o ultimo elemento.");
        }
        printf("\n\nDeseja procurar outro elemento (S/N): ");
        fflush(stdin);
        op=getchar();
    }while(op!='n'&&op!='N');
    do{
        printf("\nIntroduza um valor a eliminar: ");
        scanf("%d",&num);
        list = elimina(list,num);
        imprime(list);
        printf("\n\nDeseja eliminar outro elemento (S/N): ");
        fflush(stdin);
        op=getchar();
    }while(op!='n'&&op!='N');
    return 0;
}

Lista2* inicializa(void)
{
    return NULL;
}

void imprime(Lista2 *list)
{
    Lista2 *p;
    Lista2 *ant;
    printf("Conteudo:\n");
    for(p=list;p!=NULL;p=p->prox)
    {
        printf("%d\t",p->num);
        ant = p;
    }

    printf("\nInverso:\n");
    for(p=ant;p!=NULL;p=p->ant)
        printf("%d\t",p->num);
}

Lista2* insere(Lista2 *list, int v)
{
    Lista2 *novo = (Lista2*)malloc(sizeof(Lista2));
    if(list!=NULL) list->ant = novo;
    novo->num = v;
    novo->prox = list;
    novo->ant = NULL;
    return novo;
}

Lista2* insere_ord(Lista2 *list, int v)
{
    Lista2 *atual, *novo, *anterior;

    novo = (Lista2*)malloc(sizeof(Lista2));
    atual = list;
    anterior = NULL;

    novo->num = v;

    if(atual==NULL)
    {
        novo->prox = NULL;
        novo->ant = NULL;
        list = novo;
    }
    else
    {
        while(atual!=NULL && atual->num<v)
        {
            atual->ant = anterior;
            anterior = atual;
            atual = atual->prox;
        }
        novo->ant = anterior;
        novo->prox = atual;
        if(atual!=NULL)
            atual->ant = novo;
        if(anterior == NULL)
        {
            list = novo;
            novo->ant = NULL;
        }
        else
            anterior->prox = novo;
    }

    return list;
}

Lista2* procura(Lista2 *list,int v)
{
    Lista2* p;
    for(p=list;p!=list;p=p->prox)
    {
        if(p->num == v)
            return p;
        if(p==NULL)
            return NULL;
    }
}

Lista2* elimina(Lista2* list,int v)
{
    Lista2 *p = procura(list,v);
    if(p==NULL)
    {
        printf("\nElemento nao encontrado");
        return list;
    }

    if(list==p)
        list = p->prox;
    else
        p->ant->prox = p->prox;
    if(p->prox!=NULL)
        p->prox->ant = p->ant;
    free(p);
    return list;
}
