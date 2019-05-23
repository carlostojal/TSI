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
    Aluno *novo = malloc(sizeof(Aluno));
    Aluno *p = malloc(sizeof(Aluno));
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
}
