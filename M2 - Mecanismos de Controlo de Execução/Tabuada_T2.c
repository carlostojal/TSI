#include <stdio.h>

void main(void)
{
    int x, y;

    printf("\nTABUADA\n\n");

    for(x=1;x<=10;x++)
    {
        printf("TABUADA DO %d\n",x);
        for(y=1;y<=10;y++)
        {
            printf("%d x %d = %d\n",x,y,x*y);
        }
        printf("\n\n");
    }
}
