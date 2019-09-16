#include <stdio.h>
#include <conio.h>
#include <windows.h>

typedef struct Datas {
    int dia;
    int mes;
    int ano;
}Data;

typedef struct Avalicacoes {
    int id;
    char disciplina[50];
    float notas[3];
}Avaliacao;

typedef struct Alunos {
    int numero;
    char nome[50];
    Data DataNascimento;
    int telefone;
    Avaliacao avaliacoes[10];
}Aluno;

int menu();

void Ler_Aluno(Aluno *aluno);
void Ler_Notas_Periodo(Aluno *turma);
void Ler_Notas_Aluno(Aluno *turma);
void Lista_Notas_Aluno(turma);

void main()
{
    Aluno turma[30];
    int totalAlunos = 30;
    int totalDisciplinas = 10;
    int totalPeriodos = 3;
    int numAlunos = 0;
    int opMenu;
    do{
        opMenu = menu();
        switch(opMenu)
        {
            case 1:
                Ler_Aluno(&turma[numAlunos]);
                numAlunos++;
                break;
            case 2:
                Ler_Notas_Periodo(&(*turma));
                break;
            case 3:
                Ler_Notas_Aluno(&(*turma));
                break;
            case 4:
                Lista_Notas_Aluno(turma);
                break;
        }
    }while(opMenu!=0);
}

int menu()
{
    int op;
    do{
        system("cls");
        printf("\n\t** TURMA **\n\n");
        printf("1. Ler aluno\n");
        printf("2. Ler notas por periodo\n");
        printf("3. Ler notas por aluno\n");
        printf("4. Listar Notas por aluno\n\n");
        printf("0. Sair\n\n");
        printf("Opcao: ");
        scanf("%d",&op);
    }while(op<0||op>4);
}

void Ler_Aluno(Aluno *aluno)
{
    system("cls");
    printf("\n\t** LER ALUNO **\n\n");
    printf("Nome: ");
    scanf("%s",(*aluno).nome);
    printf("Data de nascimento (dd-mm-aaaa): ");
    scanf("%d-%d-%d",&(*aluno).DataNascimento.dia,&(*aluno).DataNascimento.mes,&(*aluno).DataNascimento.ano);
    printf("Telefone: ");
    scanf("%d",&(*aluno).telefone);
    printf("\nQualquer tecla para continuar.");
    getch();
}

void Ler_Notas_Periodo(Aluno *turma)
{
    int periodo,aluno,disciplina;
    system("cls");
    for(periodo=0;periodo<3;periodo++)
    {
        printf("\n\t**%do PERIODO **\n\n",periodo+1);
        for(aluno=0;aluno<30;aluno++)
        {
            printf("**%do ALUNO**\n",aluno+1);
            for(disciplina=0;disciplina<10;disciplina++)
            {
                printf("**%da DISCIPLINA**\n\n",disciplina+1);
                printf("Nome: ");
                scanf("%s",turma[aluno].avaliacoes[disciplina].disciplina);
                printf("Nota: ");
                scanf("%f",&turma[aluno].avaliacoes[disciplina].notas[periodo]);
            }
        }
    }
}

void Ler_Notas_Aluno(Aluno *turma)
{
    int aluno,disciplina,periodo;
    for(aluno=0;aluno<30;aluno++)
    {
        printf("\n**%do ALUNO**\n\n",aluno+1);
        for(disciplina=0;disciplina<10;disciplina++)
        {
            printf("**%da DISCIPLINA**\n",disciplina+1);
            printf("Nome: ");
            scanf("%s",turma[aluno].avaliacoes[disciplina].disciplina);
            for(periodo=0;periodo<3;periodo++)
            {
                printf("Nota do %do periodo: ");
                scanf("%f",&turma[aluno].avaliacoes[disciplina].notas[periodo]);
                printf("\n");
            }
        }
    }
}

void Lista_Notas_Aluno(Aluno *turma)
{
    int aluno,disciplina,periodo;
    for(aluno=0;aluno<30;aluno++)
    {
        printf("\n\n**%do ALUNO**\n\n");
        printf("Nome: %s\n",turma[aluno].nome);
        printf("Numero: %d",turma[aluno].numero);
        printf("Data de nascimento: %d-%d-%d",turma[aluno].DataNascimento.dia,turma[aluno].DataNascimento.mes,turma[aluno].DataNascimento.ano);
        printf("Telefone: %d",turma[aluno].telefone);
        for(disciplina=0;disciplina<10;disciplina++)
        {
            for(periodo=0;periodo<3;periodo++)
            {
                printf("%s: %f\n",turma[aluno].avaliacoes[disciplina].disciplina,turma[aluno].avaliacoes[disciplina].notas[periodo]);
            }
            printf("\n");
        }
    }
    getch();
}
