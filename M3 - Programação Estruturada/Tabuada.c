#include <stdio.h>

void Tabuada(int tab[][10], char op);
void Escreve(int tab[][10], char op);

void main()
{
    int tab[10][10];

    printf("   ** TABUADA **\n\n");

    Tabuada(tab, 'x');
    Escreve(tab, 'x');

    Tabuada(tab, '+');
    Escreve(tab, '+');
}

void Tabuada(int tab[][10], char op)
{
    int x,y;
    for(x=0;x<10;x++)
    {
        for(y=0;y<10;y++)
        {
            if(op=='x')
                tab[x][y]=x*y;
            else if(op =='+')
                tab[x][y]=x+y;
        }
    }
}

void Escreve(int tab[][10], char op)
{
    int x,y;
    if(op == 'x')
        printf("** MULTIPLICACAO **\n");
    else if(op == '+')
        printf("  ** ADICAO **\n");

    for(x=0;x<10;x++)
    {
        printf("\n** TABUADA DO %d**\n",x);
        for(y=0;y<10;y++)
        {
            printf("%4d %c %d = %2d",x,op,y,tab[x][y]);
            printf("\n");
        }
        printf("\n");
    }
}
