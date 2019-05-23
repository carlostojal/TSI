//Carlos Tojal, nº5, 1ºTSI
//https://www.github.com/carlostojal/TSI/tree/master/M7 - Tratamento de Ficheiros/biblioteca/src/libs/manuais.h

//Contém as funções de gestão dos manuais

#include <stdio.h>
#include <stdlib.h>

void adicionar_manual()
{
    FILE *fp;
    Manual *novo = malloc(sizeof(Manual));
    printf("\n** Adicionar Manual**\n\n");
    printf("ISBN: ");
    scanf("%s",novo->isbn);
    printf("Titulo: ");
    scanf("%s",novo->titulo);
    printf("Disciplina: ");
    scanf("%s",novo->disciplina);
    fp = fopen("manuais.dat","a");
    fprintf(fp,"%s %s %s\n",novo->isbn,novo->titulo,novo->disciplina);
    fclose(fp);
    free(novo);
}

void carregar_manuais(Manual *lista)
{
    Manual *p = malloc(sizeof(Manual));
    FILE *fp = fopen("manuais.dat","r");
    while(!feof(fp))
    {
        Manual *novo = malloc(sizeof(Manual));
        novo->prox = NULL;
        novo->ant = NULL;
        fscanf(fp,"%s %s %s",novo->isbn,novo->titulo,novo->disciplina);
        if(lista->prox == NULL)
        {
            novo->ant = lista;
            lista->prox = novo;
        }
        else
        {
            p=lista;
            while(p->prox!=NULL)
                p=p->prox;
            novo->ant = p;
            p->prox = novo;
        }
    }
    fclose(fp);
    free(p);
}

void listar_manuais(Manual *lista)
{
    Manual *p = malloc(sizeof(Manual));
    printf("\n** Listar Manuais **\n\n");
    if(lista->prox == NULL)
    {
        printf("\a");
        printf("Nao ha manuais para listar!\n");
    }
    for(p=lista->prox;p!=NULL;p=p->prox)
    {
        printf("ISBN: %s\n",p->isbn);
        printf("Titulo: %s\n",p->titulo);
        printf("Disciplina: %s\n\n",p->disciplina);
    }
}
