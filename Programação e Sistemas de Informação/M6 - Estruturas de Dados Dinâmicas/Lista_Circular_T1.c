#include <stdio.h>
#include <stdlib.h>

typedef struct Reg {
    int num;
    struct Reg * prox;
}Reg;

void insereCircularLista(Reg **head,int x);
void LerLista(Reg **head);
void ImprimeLista(Reg *head);
void InverteLista(Reg **head);

int main()
{
    Reg *lista = NULL;
    LerLista(&lista);
    printf("\nLista lida\n");
    ImprimeLista(lista);
    printf("\nLista invertida\n");
    InverteLista(&lista);
    ImprimeLista(lista);
    return 0;
}

void insereCircularLista(Reg **head,int x)
{
    Reg *p;
    p = (Reg*)malloc(sizeof(Reg));
    p->num = x;
    if(*head==NULL) p->prox = p;
    else
    {
        p->prox = (*head)->prox;
        (*head)->prox = p;
    }
    *head = p;
}

void LerLista(Reg **head)
{
    int i,n,val;
    printf("Quantos elementos pretende colocar na lista? ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\nIntroduza o %d.o: ",i);
        scanf("%d",&val);
        insereCircularLista(head,val);
    }
    if(*head!=NULL) *head = (*head)->prox;
}

void ImprimeLista(Reg *head)
{
    Reg *p;
    if(head != NULL)
    {
        p = head;
        do{
            printf("6%d",p->num);
            p = p->prox;
        }while(p!=head);
    }
    putchar('\n');
}

void InverteLista(Reg **head)
{
    Reg *pa, *pb, *pc;
    if(*head!=NULL)
    {
        *pa = *head;
        pb = pa->prox;
        pc = pb->prox;
        do{
            pb->prox = pa;
            pa = pb;
            pb = pc;
            pc = pc->prox;
        }while(pa != *head);
        *head = (*head)->prox;
    }
}
