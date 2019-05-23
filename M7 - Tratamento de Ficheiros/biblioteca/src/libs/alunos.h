//Carlos Tojal, nº5, 1ºTSI
//https://www.github.com/carlostojal/TSI/tree/master/M7 - Tratamento de Ficheiros/biblioteca/src/libs/alunos.h

//Contém as funções de gestão dos alunos

#include <stdio.h>
#include <stdlib.h>

void adicionar_aluno()
{
    FILE *fp;
    Aluno *novo = malloc(sizeof(Aluno));
    printf("\n** Adicionar Aluno **\n\n");
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
    fp = fopen("alunos.dat","ab");
    fprintf(fp,"%d %s %d %s %s\n",novo->num_proc,novo->nome,novo->ano,novo->turma,novo->telemovel);
    fclose(fp);
}

void carregar_alunos(Aluno *lista)
{
    Aluno *p = malloc(sizeof(Aluno));
    Aluno *novo = malloc(sizeof(Aluno));
    novo->prox = NULL;
    novo->ant = NULL;
    FILE *fp = fopen("alunos.dat","rb");
    while(!feof(fp))
    {
        fscanf(fp,"%d %s %d %s %s",&novo->num_proc,novo->nome,&novo->ano,novo->turma,novo->telemovel);
        if(lista->prox == NULL)
        {
            novo->ant = lista;
            lista->prox = novo;
        }
        else
        {
            for(p=lista;p->prox!=NULL;p=p->prox) {}
            novo->ant = p;
            p->prox = novo;
        }
    }
    fclose(fp);
    free(novo);
    free(p);
}

void listar_alunos(Aluno *lista)
{
    Aluno *p = malloc(sizeof(Aluno));
    printf("\n** Listar Alunos **\n\n");
    if(lista->prox == NULL)
    {
        printf("\a");
        printf("Nao ha alunos para listar!\n");
    }
    for(p=lista->prox;p!=NULL;p=p->prox)
    {
        printf("Nome: %s\n",p->nome);
        printf("Ano: %d\n",p->ano);
        printf("Turma: %s\n",p->turma);
        printf("Telemovel: %s\n\n",p->telemovel);
    }
}
