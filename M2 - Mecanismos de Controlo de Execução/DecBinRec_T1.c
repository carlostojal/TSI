#include <stdio.h>
int DecBin(int dec, int *Bin, int base);
int DecBinRec(int num, int base);
void main(void)
{
    long int dec,b;
    int binario[100],i=1,j;

    printf("Introduza um numero em decimal: ");
    scanf("%ld",&dec);
    printf("Introduza a base de destino: ");
    scanf("%d",&b);
    i=DecBin(dec,binario,b);
    printf("\n\t%ld(10) = ",dec);
    for(j=i-1;j>=0;j--)
    {
        /*
        if(b==16)
        {
            if(binario[j]<10)
                printf("%d",binario[j]);
            else if(binario[j]==10)
                printf("A");
            else if(binario[j]==11)
                printf("B");
            else if(binario[j]==12)
                printf("C");
            else if(binario[j]==13)
                printf("D");
            else if(binario[j]==14)
                printf("E");
            else if(binario[j]==15)
                printf("F");
        }
        */
        if(binario[j]>=10)
            printf("%c",55+binario[j]);
        else
            printf("%d",binario[j]);
    }
    printf("(%d)",b);
    printf("\n\nAgora recursivamente:\n");
    printf("\n\t%ld(10) = ",dec);
    DecBinRec(dec,b);
    printf("(%d)\n",b);
}

int DecBin(int dec, int *Bin, int base)
{
    int i=0;
    while(dec!=0)
    {
        Bin[i]=dec%base;
        dec/=base;
        i++;
    }
    return i;
}

int DecBinRec(int num, int base)
{
    if(num==0)
        return;
    DecBinRec(num/base, base);
    printf("%d",num%base);
}

