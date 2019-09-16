#include <stdio.h>
#include <windows.h>

typedef struct Datas{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct Apostas{
    int numAposta;
    int numeros[5];
    int estrelas[2];
    int milhao;
}Aposta;

typedef struct Euromilhoes{
    Data datajogo;
    int joker;
    float valor;
    Aposta apostas[5];
}Euromilhoes;

int menu();
void apostar(Euromilhoes boletim, int *numApostas);
void listar_boletim(Euromilhoes boletim, int numApostas);


void main()
{
    Euromilhoes boletim;
    int numApostas;
    int opMenu = menu();
    switch(opMenu)
    {
        case 1:
            apostar(boletim,&numApostas);
            break;
        case 2:
            listar_boletim(boletim,numApostas);
            break;
    }
}

int menu()
{
    int opMenu;
    do{
        system("cls");
        printf("\n ** Euromilhoes **\n\n");
        printf("1. Apostar\n");
        printf("2. Listar apostas\n");
        printf("0. Sair\n\n");
        printf("Introduza uma opcao: ");
        scanf("%d",&opMenu);
    }while(opMenu<0||opMenu>2);
    return opMenu;
}

void apostar(Euromilhoes boletim, int *numApostas)
{
    int i,j;
    char respJoker;
    system("cls");
    printf("\n ** Apostar **\n\n");
    printf("Quantas apostas vai jogar? ");
    scanf("%d",&numApostas);
    boletim.valor = 2.5*numApostas;
    printf("Qual a data em que vai apostar? ");
    scanf("%d/%d/%d",&boletim.datajogo.dia,&boletim.datajogo.mes,&boletim.datajogo.ano);
    printf("Vai querer apostar no Joker? ");
    scanf("%c",&respJoker);

    if(respJoker=='s'||respJoker=='S')
    {
        boletim.joker=rand();
        boletim.valor++;
    }
    else boletim.joker=0;

    for(i=0;i<numApostas;i++)
    {
        printf("\n%d Aposta\n",i+1);
        for(j=0;j<5;j++)
        {
            printf("%d Numero: ",j+1);
            scanf("%d",&boletim.apostas[i].numeros[j]);
        }
        for(j=0;j<2;j++)
        {
            printf("%d Estrela: ",j);
            scanf("%d",&boletim.apostas[i].numeros[j]);
        }
    }
}

void listar_boletim(Euromilhoes boletim, int numApostas)
{
    int i,j;
    system("cls");
    printf("\n ** Listar Apostas **\n\n");
    if(numApostas == 0)
        printf("Nenhuma aposta.");
    else
    {
        printf("Valor Total: %f",boletim.valor);
        for(i=0;i<numApostas;i++)
        {
            printf("%d Aposta\n\n",i+1);
            for(j=0;j<5;j++)
                printf("%d Numero: %d\n",j+1,boletim.apostas[i].numeros[j]);
            printf("\n");
            for(j=0;j<2;j++)
                printf("%d Estrela: %d\n",j+1,boletim.apostas[i].estrelas[j]);
            printf("\nMilhao: MIL%d\n\n",boletim.apostas[i].milhao);
        }
    }
}
