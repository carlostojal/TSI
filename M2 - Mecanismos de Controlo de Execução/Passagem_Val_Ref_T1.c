#include <stdio.h>

int xpto(int x, int y);
int optx(int *x, int *y);


//Na passagem por valor apenas � afetada a c�pia da vari�vel dentro da fun��o.
//Na passagem por refer�ncia a vari�vel originar � alterada, pois � dado o endere�o da mesma o que permite que seja alterada.


void main(void)
{
    int a=5, b=10;

    printf("a = %d, b= %d",a,b);
    if(xpto(a,b))
        printf("\nDepois de xpto - a = %d, b = %d",a,b);
    getch();
    if(optx(&a,&b))
        printf("\nDepois de optx - a = %d, b = %d",a,b);
}

int xpto(int x, int y)
{
    x+=5;
    y+=10;
    printf("\nEm xpto - x = %d, y = %d",x,y);
    return 1;
}

int optx(int *x, int *y)
{
    (*x)++;
    (*y)--;
    printf("\nEm optx - x = %d, y = %d",*x,*y);
    return 1;
}
