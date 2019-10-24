#include <stdio.h>

void main()
{
    int l, c, input;
    printf("Introduza o valor da matriz quadrada: ");
    scanf("%d",&input);
    for(l=1;l<=input;l++)
    {
        for(c=1;c<=input;c++)
            printf("*");
        printf("\n");
    }
}
