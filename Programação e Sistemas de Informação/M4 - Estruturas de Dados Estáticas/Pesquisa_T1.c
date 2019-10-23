#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>
#define DIM 1000

int ProcuraMaior(int *vet);
int ProcuraMenor(int *vet);

void preenche(int v[], int max)
{
    int i;

    for(i=0;i<DIM;i++)
        v[i]=rand()&max;
}

void lista(int v[])
{
    int i;

    for(i=0;i<DIM;i++)
        printf("[%3d]=%4d\t",i,v[i]);
}

void main()
{
    int vet[DIM];
    int pos;

    preenche(vet,9999);
    lista(vet);

    pos = ProcuraMaior(vet);
    printf("\nMaior valor = v[%d] = %d",pos,vet[pos]);
    pos = ProcuraMenor(vet);
    printf("\nMenor valor = v[%d] = %d",pos,vet[pos]);

    getch();
}

int ProcuraMenor(int v[])
{
    int i,Min=INT_MAX,Pos=0;

    for(i=0;i<DIM;i++)
    {
        if(v[i]<Min)
        {
            Min=v[i];
            Pos=i;
        }
    }
    return Pos;
}

int ProcuraMaior(int v[])
{
    int i,Max=INT_MIN,Pos=0;

    for(i=0;i<DIM;i++)
    {
        if(v[i]>Max)
        {
            Max=v[i];
            Pos=i;
        }
    }
    return Pos;
}

