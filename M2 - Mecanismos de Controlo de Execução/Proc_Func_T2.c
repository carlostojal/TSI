#include <stdio.h>

void ProcSoma(int, int, int*);
int FuncSoma(int x, int y);

void main (void)
{
    int x,y,res;

    printf("\nIntroduza 2 numeros separados por espaco: ");
    scanf("%d %d", &x, &y);
    ProcSoma(x,y,&res);
    printf("\n\nProcSoma\t%d + %d = %.0f\n\n",x,y,res);
    res = FuncSoma(x,y);
    printf("\n\nFuncSoma\t%d + %d = %.0f\n\n",x,y,res);
}

void ProcSoma(int x, int y, int *res)
{
    //printf("\n\n\t%d + %d = %d\n", x, y, x+y);
    (*res)=x+y;
}

int FuncSoma(int a, int b)
{
    return a+b;
}

