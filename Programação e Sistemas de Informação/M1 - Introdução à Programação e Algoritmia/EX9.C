#include <stdio.h>

void main(void)
{
    int num;
    while (num != 0)
    {
        printf("Introduza um numero diferente de 0: ");
        scanf("%d", &num);
        if (num < 0)
        {
            printf("\n\t\tNegativo\n\n\n");
        }
        if (num > 0)
        {
            printf("\n\t\tPositivo\n\n\n");
        }
    }
    printf("\nAVISO: O numero 0 nao pode ser introduzido, pois e neutro.\n");
}
