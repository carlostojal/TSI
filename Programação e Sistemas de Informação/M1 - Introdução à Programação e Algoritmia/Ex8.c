#include <stdio.h>

void main(void)
{
    FILE * fptr;

    int NAlunos;
    int cont=0;
    int NPositivas=0;
    int nota;
    char nome[20], apelido[20], turma[20];

    fptr = fopen("notas_alunos.txt", "w");

    printf("Introduza a turma: ");
    scanf("%c", &turma);
    fprintf(fptr, "Turma: %c\n\n", &turma);
    printf("\nIntroduza o n de alunos: ");
    scanf("%d", &NAlunos);

    while(cont<=NAlunos)
    {
        do{
        printf("\nIntroduza o nome do aluno: ");
        scanf("%c %c", &nome, &apelido);
        printf("\nIntroduza a nota do aluno: ");
        scanf("%d", &nota);
        fprintf(fptr, "%c %c, no%d - Nota: %d\n", nome, apelido, cont, nota);
        }while(nota<1 || nota>20);
        if(nota>=10)
        {
            NPositivas=NPositivas+1;
            fprintf(fptr, "               Apreciacao: Positiva\n\n");
        }
        else
        {
            fprintf(fptr, "               Apreciacao: Negativa\n\n");
        }
    printf("\nNo de positivas: %d\n", NPositivas);
    cont=cont+1;
    }
    printf("No de negativas: %d\n", NAlunos-NPositivas);
}
