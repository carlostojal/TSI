//Carlos Tojal, nº5, 1ºTSI
//https://www.github.com/carlostojal/TSI/tree/master/M7 - Tratamento de Ficheiros/biblioteca/src/libs/emprestimos.h
//biblioteca/src/libs/emprestimos.h

//Contém as funções de gestão dos emprestimos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adicionar_emprestimo()
{
    FILE *fp;
    Emprestimo *novo = malloc(sizeof(Manual));
    printf("\n** Adicionar Emprestimo**\n\n");
    if(!novo)
        printf("Ocorreu um erro de memoria.\n");
    else
    {
        printf("ID: ");
        scanf("%d",&novo->id);
        printf("ID do Aluno: ");
        scanf("%d",&novo->id_aluno);
        printf("ID do Manual: ");
        scanf("%s",novo->id_manual);
        printf("Data de Levantamento (dd-mm-aaaa): ");
        scanf("%d-%d-%d",&novo->data_levantamento.dia,&novo->data_levantamento.mes,&novo->data_levantamento.ano);
        printf("Valor: ");
        scanf("%f",&novo->valor);
        fp = fopen("emprestimos.dat","a");
        fprintf(fp,"%d %d %s %d-%d-%d %f\n",novo->id,novo->id_aluno,novo->id_manual,novo->data_levantamento.dia,novo->data_levantamento.mes,novo->data_levantamento.ano,novo->valor);
        fclose(fp);
        free(novo);
    }
}

void carregar_emprestimos(Emprestimo *lista)
{
    Emprestimo *p = malloc(sizeof(Emprestimo));
    FILE *fp = fopen("manuais.dat","r");
    if(!p)
        printf("Ocorreu um erro de memoria.\n");
    else
    {
        if(fp) //se o ficheiro existe
        {
            while(!feof(fp))
            {
                Emprestimo *novo = malloc(sizeof(Manual));
                novo->prox = NULL;
                novo->ant = NULL;
                fscanf(fp,"%d %d %s %d-%d-%d %f",&novo->id,&novo->id_aluno,novo->id_manual,&novo->data_levantamento.dia,&novo->data_levantamento.mes,&novo->data_levantamento.ano,&novo->valor);
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
        }
        else //se o ficheiro não existe (nunca foram registados empréstimos)
            printf("\nNunca foram registados empréstimos.\n");
    }
    fclose(fp);
    free(p);
}

void listar_emprestimo(Emprestimo *emprestimo)
{
    printf("\nID: %d\n",emprestimo->id);
    printf("ID do Aluno: %d\n",emprestimo->id_aluno);
    printf("ID do Manual: %s\n",emprestimo->id_manual);
    printf("Data de Levantamento: %d-%d-%d\n",emprestimo->data_levantamento.dia,emprestimo->data_levantamento.mes,emprestimo->data_levantamento.ano);
    printf("Valor: %.2f\n\n",emprestimo->valor);
}

void limpar_emprestimos(Emprestimo *lista)
{
    Emprestimo *p = (Emprestimo*) malloc(sizeof(Emprestimo));
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

void pesquisar_emprestimo_id(Emprestimo *lista)
{
    int id;
    int encontrou=0;
    Emprestimo *p = (Emprestimo*) malloc(sizeof(Emprestimo));
    printf("\n** Pesquisar Emprestimo por ID **\n\n");
    printf("ID: ");
    scanf("%d",&id);
    for(p=lista->prox;p!=NULL;p=p->prox)
    {
        if(p->id==id)
        {
            encontrou=1;
            listar_emprestimo(p);
            break;
        }
    }
    if(!encontrou)
        printf("\nNao foram encontrados resultados.\n");
}

void pesquisar_emprestimo_id_aluno(Emprestimo *lista)
{
    int id_aluno;
    int encontrou=0;
    Emprestimo *p = (Emprestimo*) malloc(sizeof(Emprestimo));
    printf("\n** Pesquisar Emprestimo por ID do Aluno **\n\n");
    printf("ID do Aluno: ");
    scanf("%d",&id_aluno);
    for(p=lista->prox;p!=NULL;p=p->prox)
    {
        if(p->id_aluno==id_aluno)
        {
            encontrou=1;
            listar_emprestimo(p);
            break;
        }
    }
    if(!encontrou)
        printf("\nNao foram encontrados resultados.\n");
}

void pesquisar_emprestimo_id_manual(Emprestimo *lista)
{
    char id_manual[20];
    int encontrou=0;
    Emprestimo *p = (Emprestimo*) malloc(sizeof(Emprestimo));
    printf("\n** Pesquisar Emprestimo por ID do Manual **\n\n");
    printf("ID do Manual: ");
    scanf("%s",id_manual);
    for(p=lista->prox;p!=NULL;p=p->prox)
    {
        if(strcmp(p->id_manual,id_manual)==0)
        {
            encontrou=1;
            listar_emprestimo(p);
            break;
        }
    }
    if(!encontrou)
        printf("\nNao foram encontrados resultados.\n");
}

void pesquisar_emprestimo_data_levantamento(Emprestimo *lista)
{
    Data data_levantamento;
    int encontrou=0;
    Emprestimo *p = (Emprestimo*) malloc(sizeof(Emprestimo));
    printf("\n** Pesquisar Emprestimo por Data de Levantamento **\n\n");
    printf("Data de levantamento (dd-mm-aaaa): ");
    scanf("%d-%d-%d",&data_levantamento.dia,&data_levantamento.mes,&data_levantamento.ano);
    for(p=lista->prox;p!=NULL;p=p->prox)
    {
        if(p->data_levantamento.dia==data_levantamento.dia&&p->data_levantamento.mes==data_levantamento.mes&&p->data_levantamento.ano==data_levantamento.ano)
        {
            encontrou=1;
            listar_emprestimo(p);
        }
    }
    if(!encontrou)
        printf("\nNao foram encontrados resultados.\n");
}

void pesquisar_emprestimo_valor(Emprestimo *lista)
{
    float valor;
    int encontrou=0;
    Emprestimo *p = (Emprestimo*) malloc(sizeof(Emprestimo));
    printf("\n** Pesquisar Emprestimo por Valor **\n\n");
    printf("Valor: ");
    scanf("%f",&valor);
    for(p=lista->prox;p!=NULL;p=p->prox)
    {
        if(p->valor==valor)
        {
            encontrou=1;
            listar_emprestimo(p);
        }
    }
    if(!encontrou)
        printf("\nNao foram encontrados resultados.\n");
}
