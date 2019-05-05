#include <stdio.h>

void main(void)
{
    int rapazes=0, raparigas=0, alunos=0;
    float PRapazes=0, PRaparigas=0;
    printf("Pretende-se calcular a percentagem de rapazes e raparigas de uma turma\n\n");
    printf("Introduza o numero de alunos: ");
    scanf("%d", &alunos);
    printf("Introduza o numero de rapazes: ");
    scanf("%d", &rapazes);
    PRapazes = (float) rapazes/alunos*100;
    raparigas = alunos - rapazes;
    PRaparigas = (float) 100 - PRapazes;
    printf("\n\nNo de rapazes: %d", rapazes);
    printf("\nNo de raparigas: %d", raparigas);
    printf("\n\nPercentagem de rapazes: %.1f%%", PRapazes);
    printf("\nPercentagem de raparigas: %.1f%%\n", PRaparigas);
}
