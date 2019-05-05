#include <stdio.h>

int main(void)
{
    int num=1;
    printf("QUADRADO DOS NUMEROS ENTRE 1 E 20\n\n");

    while(num<=20)
    {
        printf("%d\tQuadrado = %d^2=%d\n", num, num, num*num);
        num = num + 1;
    }

    /*
    int num = 1;

    do
    {
        printf("\n%2d^2 = %3d", num, num*num);
        num++;
    } while(num<=20);
    */
}
