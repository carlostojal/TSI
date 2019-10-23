#include <stdio.h>

float media(int n, int *vet)
{
    int x, soma=0;
    for(x=0;x<n;x++)
        soma+=vet[x];
    return (float)soma/n;
}

void main()
{
    int i, n;
    int *v;
    int *x;

    printf("\nTamanho de um int: %d",sizeof(int));
    printf("\nTamanho de um char: %d",sizeof(char));
    printf("\nTamanho de um double: %d",sizeof(double));

    printf("\nIntroduza o numero de elementos do vetor: ");
    scanf("%d",&n);
    v = (int*) malloc(n*sizeof(int));
    if(v==NULL)
    {
        printf("Memoria insuficiente.\n");
        return 1;
    }
    for(i=0;i<n;i++)
    {
        printf("\nIntroduza o %do elemento: ",i+1);
        scanf("%d",&v[i]);
    }
    printf("\nMedia dos valores introduzidos: %.2f",media(n,v));
    free(v);
    getch();
}
