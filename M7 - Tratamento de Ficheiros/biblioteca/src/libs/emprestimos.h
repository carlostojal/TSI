//Carlos Tojal, nº5, 1ºTSI
//https://www.github.com/carlostojal/TSI/tree/master/M7 - Tratamento de Ficheiros/biblioteca/src/libs/emprestimos.h
//biblioteca/src/libs/emprestimos.h

//Contém as funções de gestão dos emprestimos

#include <stdio.h>
#include <stdlib.h>

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
    for(p=lista->prox->prox;p!=NULL;p=p->prox)
    {
        if(p->prox==NULL) //se o elemento é o último da lista, liberta-se a si próprio
        {
            free(p);
            break;
        }
        else //senão, liberta o seu antecessor
            free(p->ant);
    }
    lista->prox = NULL;
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
