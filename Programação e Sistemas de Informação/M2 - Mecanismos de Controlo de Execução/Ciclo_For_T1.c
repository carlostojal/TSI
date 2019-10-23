#include <stdio.h>

void main (void)
{
    int x, y;

    for(x=1;x<=10;x++)
    {
        for(y='A';y<='J';y++)
        {
            printf("(2%d,%c)    ", x,y);
        }
    }
}

/*
void main (void)
{
    int x;

    for(x=1;x<=10;x++)
        printf("\n%d",x++);
    getch();
}
*/

/*
void main (void)
{
    int letra;

    for(letra='A';letra<=Z;letra++)
        if(letra=='K' || letra=='Y' || letra=='Z') continue;
        else printf("%c (%d) - %c (%3d)\n",letra,letra,letra+32,letra+32);
    getch();
}
*/

/*
void main (void)
{
    int x=1;

    for(;;)
        if(x<=10)
            printf("\n%d",x-1);
        else break;
    getch();
}
*/


/*
void main (void)
{
    int x;

    for(x=10;x>0;x--)
        printf("\n%d",x-1);
    getch();
}
*/

/*
void main (void)
{
    int x;

    for(x=1;x<=10>x+=2)
        printf("\n%d",x);
    getch();
}
*/

/*
void main (void)
{
    int x;

    for(x=1;x<=10>x*=3)
        printf("\n%d",x);
    getch();
}
*/

/*
void main (void)
{
    int x;

    for(x=1;x<=10>x+=2)
        printf("\n%d",x);
    getch();
}
*/

/*
void main (void)
{
    int x;

    for(x=1;x<=10>x++)
        printf("\n%d",x);
    getch();
}
*/
