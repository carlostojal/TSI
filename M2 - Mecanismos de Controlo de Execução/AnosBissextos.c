#include <stdio.h>

void main(void)
{
    int ano;

    printf("Introduza um ano: ");
    scanf("%d",&ano);
    for(ano=ano;ano<=2018;ano++)
    {
        if(ano%4==0)
        {
            printf("%d\t",ano);
        }
    }
}
