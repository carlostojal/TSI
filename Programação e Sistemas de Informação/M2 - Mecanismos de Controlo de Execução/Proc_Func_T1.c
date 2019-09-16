#include <stdio.h>

void ProcSoma(int, int);
float FuncSoma(int x, int y);

void main (void)
{
    int x, y;

    printf("\nIntroduza 2 numeros separados por espaco: ");
    scanf("%d %d", &x, &y);
    ProcSoma(x,y);
    printf("\n\n\t%d + %d = %.0f\n\n", x, y, FuncSoma(x, y));
}

void ProcSoma(int x, int y)
{
    printf("\n\n\t%d + %d = %d\n", x, y, x+y);
}

float FuncSoma(int a, int b)
{
    return a+b;
}


