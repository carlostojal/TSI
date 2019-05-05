#include <stdio.h>
#include <windows.h>

float func_media(int, int*);

void main()
{
    int notas[30][10];
    int alunos;
    int disciplinas;
    float result;
    float soma=0;
    int x; //alunos
    int y; //disciplinas
    printf("Introduza o numero de alunos: ");
    scanf("%d",&alunos);
    printf("Introduzao numero de disciplinas: ");
    scanf("%d",&disciplinas);

    for(x=0;x<alunos;x++)
    {
        for(y=0;y<disciplinas;y++)
        {
            printf("\nIntroduza a %d nota do %d aluno: ",y+1,x+1);
            scanf("%d",&notas[x][y]);
        }
        printf("\n\n");
    }
    for(x=0;x<alunos;x++)
    {
        printf("\nO aluno %d tem: ",x+1);
        result=func_media(disciplinas,notas[x]);
        printf(" = %.2f de media",result);
        soma+=(result*disciplinas);
    }
    printf("\n");
    printf("Media da turma: %.2f",soma/(alunos*disciplinas));
    printf("\n");
    system("pause");
}

float func_media(int x, int *notas)
{
    int n;
    float soma=0;
    for(n=0;n<x;n++)
    {
        printf("    %d",notas[n]);
        soma+=notas[n];
    }
    return soma/x;
}


