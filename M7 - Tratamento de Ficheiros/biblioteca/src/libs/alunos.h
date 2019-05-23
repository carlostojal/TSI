//Carlos Tojal, nº5, 1ºTSI
//https://www.github.com/carlostojal/TSI/tree/master/M7 - Tratamento de Ficheiros/biblioteca/src/libs/alunos.h

//Contém as funções de gestão dos alunos

#include <stdio.h>

void adicionar_aluno()
{
    FILE *fp;
    Aluno *novo;
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
    fprintf(fp,"%d %s %d %s %s",novo->num_proc,novo->nome,novo->ano,novo->turma,novo->telemovel);
    fclose(fp);
}
