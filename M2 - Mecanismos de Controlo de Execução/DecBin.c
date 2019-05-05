#include <stdio.h>

int DecBin(int dec, int *bin)
{
    int quoc,i=1;
    quoc=dec;
    while(quoc!=0)
    {
        bin[i++]=quoc % 2;
        quoc = quoc / 2;
    }
    return i;
}

void main(void)
{
    int dec;
    int i,j;
    int bin[100];
    char rep;

    do
    {
        system("cls");
        printf("Introduza um inteiro: ");
        scanf("%d",&dec);
        i=DecBin(dec,bin);
        printf("\n\t%d(10) = ",dec);
        for(j=i-1;j>0;j--)
            printf("%d",bin[j]);
        printf("(2)\n");
        fflush(stdin);
        printf("Deseja repetir (S/N)?: ");
        rep=toupper(getch());
    }while(rep!='N');
}
