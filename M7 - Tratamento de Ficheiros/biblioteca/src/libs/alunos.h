//Carlos Tojal, nº5, 1ºTSI
//https://www.github.com/carlostojal/TSI/tree/master/M7 - Tratamento de Ficheiros/biblioteca/src/libs/alunos.h
//biblioteca/src/libs/alunos.h

//Contém as funções de gestão dos alunos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>

void adicionar_aluno()
{
    FILE *fp;
    Aluno *novo = malloc(sizeof(Aluno));
    printf("\n** Adicionar Aluno **\n\n");
    if(!novo)
        printf("Ocorreu um erro de memória.\n");
    else
    {
        printf("Numero de processo: ");
        scanf("%d",&novo->num_proc);
        printf("Nome: ");
        scanf("%s",novo->nome);
        printf("Ano: ");
        scanf("%d",&novo->ano);
        printf("Turma: ");
        scanf("%s",novo->turma);
        printf("Telemovel: ");
        scanf("%s",novo->telemovel);
        fp = fopen("alunos.dat","a");
        fprintf(fp,"%d %s %d %s %s\n",novo->num_proc,novo->nome,novo->ano,novo->turma,novo->telemovel);
        fclose(fp);
    }
}

void carregar_alunos(Aluno *lista)
{
    Aluno *p = (Aluno*) malloc(sizeof(Aluno));
    Aluno *novo = (Aluno*) malloc(sizeof(Aluno));
    FILE *fp = fopen("alunos.dat","r");
    int num;
    if(!p||!novo)
        printf("Ocorreu um erro de memória.\n");
    else
    {
        while(!feof(fp))
        {
            novo->prox = NULL;
            novo->ant = NULL;
            fscanf(fp,"%d %s %d %s %s",&novo->num_proc,novo->nome,&novo->ano,novo->turma,novo->telemovel);
            printf("Lido: %s",novo->nome);
            scanf("%d",&num);
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

void listar_aluno(Aluno *aluno)
{
    printf("\nNumero de processo: %d\n",aluno->num_proc);
    printf("Nome: %s\n",aluno->nome);
    printf("Ano: %d\n",aluno->ano);
    printf("Turma: %s\n",aluno->turma);
    printf("Telemovel: %s\n\n",aluno->telemovel);
}

void pesquisar_aluno_numproc(Aluno *lista)
{
    int num_proc;
    Aluno *p = (Aluno*) malloc(sizeof(Aluno));
    printf("\n** Pesquisar Aluno por Num Processo **\n\n");
    printf("Numero de processo: ");
    scanf("%d",&num_proc);
    for(p=lista->prox;p!=NULL;p=p->prox)
    {
        if(p->num_proc==num_proc)
        {
            listar_aluno(p);
            break;
        }
    }
}

void pesquisar_aluno_nome(Aluno *lista)
{
    char nome[30];
    Aluno *p = (Aluno*) malloc(sizeof(Aluno));
    printf("\n** Pesquisar Aluno por Nome **\n\n");
    printf("Nome: ");
    scanf("%s",nome);
    for(p=lista->prox;p!=NULL;p=p->prox)
    {
        if(strcmp(p->nome,nome)==0)
            listar_aluno(p);
    }
}
