#include <stdio.h>

float func_media(int, int*);

void main()
{
    int notas[20];
    int num_notas;
    float result;
    int x;
    printf("Introduza o numero de notas: ");
    scanf("%d",&num_notas);
    for(x=0;x<num_notas;x++)
    {
        printf("Introduza a %d nota: ",x+1);
        scanf("%d",&notas[x]);
    }
    result=func_media(num_notas,notas);
    printf("MEDIA DE: %.1f\n",result);
    system("pause");
}

float func_media(int num_notas, int *notas)
{
    float res=0;
    int x=0;
    while(x<=num_notas)
    {
        res=res+notas[x];
        x++;
    }
    res=res/num_notas;
    return res;
}


