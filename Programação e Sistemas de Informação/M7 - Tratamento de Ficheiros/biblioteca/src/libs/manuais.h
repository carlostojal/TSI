//Carlos Tojal, nº5, 1ºTSI
//https://www.github.com/carlostojal/TSI/tree/master/M7 - Tratamento de Ficheiros/biblioteca/src/libs/manuais.h
//biblioteca/src/libs/manuais.h

//Contém as funções de gestão dos manuais

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verificar_manual(Manual *novo,Manual *lista)
{
    Manual *p = (Manual*) malloc(sizeof(Manual));
    int existe=0;
    for(p=lista;p!=NULL;p=p->prox)
    {
        if(strcmp(p->isbn,novo->isbn)==0)
        {
            existe=1;
            break;
        }
    }
    return existe;
}

void adicionar_manual(Manual *lista)
{
    FILE *fp;
    Manual *novo = malloc(sizeof(Manual));
    int existe;
    printf("\n** Adicionar Manual**\n\n");
    printf("ISBN: ");
    scanf("%s",novo->isbn);
    printf("Titulo: ");
    scanf("%s",novo->titulo);
    printf("Disciplina: ");
    scanf("%s",novo->disciplina);
    existe=verificar_manual(novo,lista);
    if(!existe)
    {
        fp = fopen("manuais.dat","a");
        fprintf(fp,"%s %s %s\n",novo->isbn,novo->titulo,novo->disciplina);
        fclose(fp);
    }
    else
        printf("\nJa foi registado um manual com o ISBN %s.\n",novo->isbn);
    free(novo);
}

void carregar_manuais(Manual *lista)
{
    Manual *p = (Manual*) malloc(sizeof(Manual));
    FILE *fp = fopen("manuais.dat","r");
    if(!p)
        printf("\nOcorreu um erro de memoria.\n");
    else
    {
        if(fp) //se o ficheiro existe
        {
            while(!feof(fp))
            {
                Manual *novo = malloc(sizeof(Manual));
                novo->prox = NULL;
                novo->ant = NULL;
                fscanf(fp,"%s %s %s",novo->isbn,novo->titulo,novo->disciplina);
                if(lista->prox == NULL) //se a lista estiver vazia
                {
                    novo->ant = lista;
                    lista->prox = novo;
                }
                else //se a lista já tiver elementos
                {
                    p=lista;
                    while(p->prox!=NULL)
                        p=p->prox;
                    novo->ant = p;
                    p->prox = novo;
                }
            }
        }
        else //se o ficheiro existe (nunca foram registados manuais)
            printf("\nNunca foram registados manuais.\n");
    }
    fclose(fp);
}

void listar_manual(Manual *manual)
{
    printf("\nISBN: %s\n",manual->isbn);
    printf("Titulo: %s\n",manual->titulo);
    printf("Disciplina: %s\n\n",manual->disciplina);
}

void limpar_manuais(Manual *lista)
{
    Manual *p = (Manual*) malloc(sizeof(Manual));
    if(!p)
        printf("\nOcorreu um erro de memoria.\n");
    else
    {
        if(lista->prox!=NULL)
        {
            for(p=lista->prox;p!=NULL;p=p->prox)
            {
                if(p->prox == NULL) //se é o último elemento da lista, liberta-se a si próprio
                {
                    free(p);
                    break;
                }
                else if(p->ant!=lista) //senão, liberta o seu antecessor
                    free(p->ant);
            }
            lista->prox = NULL;
        }
    }
}

void pesquisar_manual_isbn(Manual *lista)
{
    char isbn[20];
    int encontrou=0;
    Manual *p = (Manual*) malloc(sizeof(Manual));
    printf("\n** Pesquisar Manual por ISBN **\n\n");
    printf("ISBN: ");
    scanf("%s",isbn);
    for(p=lista->prox;p!=NULL;p=p->prox)
    {
        if(strcmp(p->isbn,isbn)==0)
        {
            encontrou=1;
            listar_manual(p);
            break;
        }
    }
    if(!encontrou)
        printf("\nNao foram encontrados resultados.\n");
}

void pesquisar_manuais_titulo(Manual *lista)
{
    char titulo[20];
    int encontrou=0;
    Manual *p = (Manual*) malloc(sizeof(Manual));
    printf("\n** Pesquisar Manuais por Titulo **\n\n");
    printf("Titulo: ");
    scanf("%s",titulo);
    for(p=lista->prox;p!=NULL;p=p->prox)
    {
        if(strcmp(p->titulo,titulo)==0)
        {
            encontrou=1;
            listar_manual(p);
        }
    }
    if(!encontrou)
        printf("\nNao foram encontrados resultados.\n");
}

void pesquisar_manuais_disciplina(Manual *lista)
{
    char disciplina[20];
    int encontrou=0;
    Manual *p = (Manual*) malloc(sizeof(Manual));
    printf("\n** Pesquisar Manuais por Disciplina **\n\n");
    printf("Disciplina: ");
    scanf("%s",disciplina);
    for(p=lista->prox;lista!=NULL;p=p->prox)
    {
        if(strcmp(p->disciplina,disciplina)==0)
        {
            encontrou=1;
            listar_manual(p);
        }
    }
    if(!encontrou)
        printf("\nNao foram encontrados resultados.\n");
}
