#include <stdio.h>
#include <stdlib.h>
//#include "estruturas.h"

void adicionar_carro()
{
    Carro *novo = malloc(sizeof(Carro));
    printf("\n** Adicionar Carro **\n\n");
    printf("Marca: ");
    scanf("%s",novo->marca);
    printf("Modelo: ");
    scanf("%s",novo->modelo);
    FILE *fp = fopen("carros.dat","ab");
    fprintf(fp,"%s %s\n",novo->marca,novo->modelo);
    fclose(fp);
}

void carregar_carros(Carro *lista)
{
    Carro *novo = malloc(sizeof(Carro));
    Carro *p = malloc(sizeof(Carro));
    FILE *fp = fopen("carros.dat","rb");
    while(!feof(fp))
    {
        printf("a\n");
        fscanf(fp,"%s %s",novo->marca,novo->modelo);
        if(lista->prox == NULL)
        {
            novo->prox = NULL;
            novo->ant = lista;
            lista->prox = novo;
        }
        else
        {
            for(p=lista;p->prox!=NULL;p=p->prox) {
                printf("fracasso\n");
            }
            novo->ant = p;
            novo->prox = NULL;
            p->prox = novo;
        }
    }
    fclose(fp);
}

void listar_carros(Carro *lista)
{
    Carro *p = malloc(sizeof(Carro));
    printf("\n** Listar Carros **\n\n");
    for(p=lista->prox;p!=NULL;p=p->prox)
    {
        printf("Marca: %s\n",p->marca);
        printf("Modelo: %s\n\n",p->modelo);
    }
}
