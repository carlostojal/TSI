#include <stdio.h>

void main(void)
{
    int num, num1=0;
    char rep='S';

    while(rep=='S')
    {
        printf("\nIntroduza um numero: ");
        scanf("%d", &num);

        printf("\n\nTABUADA DO NUMERO %d\n\n", num);

        while(num1<=10)
        {
            printf("    %d x %d = %d\n", num, num1, num*num1);
            num1++;
        }
        printf("\nDeseja repetir (S/N)? ");
        fflush(stdin);
        rep=toupper(getch());
    }
}
