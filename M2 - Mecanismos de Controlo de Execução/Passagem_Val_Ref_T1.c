#include <stdio.h>

int xpto(int x, int y);
int optx(int *x, int *y);


//Na passagem por valor apenas é afetada a cópia da variável dentro da função.
//Na passagem por referência a variável originar é alterada, pois é dado o endereço da mesma o que permite que seja alterada.


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
