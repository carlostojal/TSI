#include <stdio.h>

void imprime_array(int tam,int*vet);
void soma_arrays(int *vetorA, int *vetorB, int *vetorSoma, int *tam);

void main()
{
    int x,y;
    int vetorA[10];
    int vetorB[10];
    int vetorSoma[10];

    for(x=0;x<10;x++)
    {
        vetorA[x]=x+1;
        vetorB[x]=(x+1)*10;
    }
    imprime_array(10,vetorA);
    imprime_array(10,vetorB);
    soma_arrays(vetorA,vetorB,vetorSoma,10);
    imprime_array(10,vetorSoma);
    getch();
}

void imprime_array(int tam,int*vet)
{
    int i;
    printf("\n");
    for(i=0;i<tam;i++)
        printf("%3d\t",vet[i]);
}

void soma_arrays(int *vetorA, int *vetorB, int *vetorSoma, int tam)
{
    int i;
    for(i=0;i<tam;i++)
        vetorSoma[i]=vetorA[i]+vetorB[i];
}
