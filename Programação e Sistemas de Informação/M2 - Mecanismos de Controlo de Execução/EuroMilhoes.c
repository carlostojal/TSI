#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int menu();
void limpa_aposta(int *ap);
void listar(int *ap);
void apostas(int *ap);
void sorteio(int *sorteio);
int acertos(int *boletim, int *sorteio);

void main()
{
    int OpMenu;
    int boletim[5][7];
    int chave[7];
    int x;
    int num;
    float saldo;
    int valop1=0,valop2=0;
    do
    {
        OpMenu=menu();
        switch(OpMenu)
        {
            case 1:
            {
                system("cls");
                for(x=0;x<5;x++)
                    limpa_aposta(boletim[x]);
                do{
                    printf("Quantas apostas vai jogar[1..5]? ");
                    scanf("%d",&num);
                }while(num<1||num>5);
                for(x=0;x<num;x++)
                    apostas(boletim[x]);
                for(x=0;x<num;x++)
                {
                    listar(boletim[x]);
                    valop1=1;
                }
                getch();
                break;
            }
            case 2:
            {
                if(valop1==1)
                {
                    sorteio(chave);
                    listar(chave);
                    valop1=1;
                }else printf("\nPrimeiro tem de fazer as apostas.\n");
                getch();
                break;
            }
            case 3:
            {
                if(valop2==1)
                {
                    acertos(boletim,chave);
                }else printf("\nPrimeiro tem de fazer as apostas e o sorteio.\n");
                system("cls");
                printf("\nA P O S T A S");
                for(x=0;x<num;x++)
                    listar(boletim[x]);
                printf("\n\nC H A V E");
                for(x=0;x<num;x++)
                    listar(chave);
                printf("\n\nA C E R T O S");
                for(x=0;x<num;x++)
                {
                    printf("\nNa %da aposta: ",x+1);
                    saldo=acertos(boletim[x],chave);
                }
                saldo=saldo-2.5*num;
                printf("\n\nO saldo do concurso foi %.2f",saldo);
                getch();
                break;
            }
        }
    }while(OpMenu!=4);
}

void limpa_aposta(int *ap)
{
    int n;
    printf("\n");
    for(n=0;n<7;n++)
        ap[n]=0;

}

void listar(int *ap)
{
    int x;
    printf("\n");
    for(x=0;x<7;x++)
    {
        if(x==5) printf("+ %d ",ap[x]);
        else printf("%d ",ap[x]);
    }
}

int menu()
{
    int op;
    do{
        system("cls");
        printf("\n\t**Euromilhoes**\n\n");
        printf(" 1 - Definir Apostas\n");
        printf(" 2 - Simular Sorteio\n");
        printf(" 3 - Validar Acertos\n");
        printf(" 4 - Sair\n\n");
        printf("\tOpcao: ");
        fflush(stdin);
        scanf("%d",&op);
    }while((op<1)||(op>4));
    return op;
}

void apostas(int *ap)
{
    int x;
    int k,num,repetido;
    for(x=0;x<5;x++)
    {
        do{
            repetido=0;
            do{
                printf("\t(N %d): ",x+1);
                scanf("%d",&num);
            }while(num<1||num>50);
            for(k=0;k<x;k++)
                if(num==ap[k]) repetido=1;
            }while(repetido==1);
            ap[x]=num;
    }
    for(x=5;x<7;x++)
    {
        do{
            repetido=0;
            do{
                printf("\t(E %d): ",x-4);
                scanf("%d",&num);
            }while(num<1||num>12);
            if(x==6)
                if(ap[5]==num) repetido=1;
        }while(repetido==1);
        ap[x]=num;
    }
}

void sorteio(int *sorteio)
{
    int aleat;
    int num=0;
    int repetido=0;
    int x,k;
    srand(time(NULL));
    for(x=0;x<5;x++)
    {
        do{
            repetido=0;
            aleat=(rand()%50+1);
            for(k=0;k<x;k++)
                if(aleat==sorteio[k]) repetido=1;
        }while(repetido==1);
        sorteio[x]=aleat;
    }
    for(x=5;x<7;x++)
    {
        do{
            repetido=0;
            aleat=(rand()%12+1);
            if(x==6)
                if(sorteio[5]==aleat) repetido=1;
        }while(repetido==1);
        sorteio[x]=aleat;
    }
}

int acertos(int *boletim, int *sorteio)
{
    int naposta;
    int nsorteio;
    int ncertos=0;
    int ecertas=0;
    int premio;

    for(naposta=0;naposta<5;naposta++)
        for(nsorteio=0;nsorteio<5;nsorteio++)
            if(boletim[naposta]==sorteio[nsorteio])
                ncertos++;

    for(naposta=5;naposta<7;naposta++)
        for(nsorteio=5;nsorteio<7;nsorteio++)
            if(boletim[naposta]==sorteio[nsorteio])
                ecertas++;

    printf("\n%d Numeros e %d Estrelas",ncertos,ecertas);
    if((ncertos==2)&&(ecertas==1)) premio=5;
    if((ncertos==3)&&(ecertas==1)) premio=500;
    if((ncertos==4)&&(ecertas==1)) premio=5000;
    if((ncertos==5)&&(ecertas==2)) premio=50000;

    getch();
    return premio;
}

