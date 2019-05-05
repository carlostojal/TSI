#include <stdio.h>

int main(void)
{

    /*
    #include <limits.h>

    float num, min=INT_MAX, max=0;
    int contador=1;

    while(contador<=10)
    {
        printf("Introduza o %d numero: ", contador);
        scanf("%d", &num);
        if(num<=min){
            min = num;
        }
        if(num>=num) {
            max = num;
        }
        contador = contador + 1;
    }
    printf("\nMenor valor introduzido: %d\n", min);
    printf("Maior valor introduzido: %d\n", max);
    */

    int contador, num, min, max;

    for(contador=1;contador<=10;contador++)
    {
        printf("Introduza o %d numero: ", contador);
        scanf("%d", &num);
        if(contador==1) {
            max=min=num;
        }
        if(num<min) {
            min=num;
        }
        if(num>max) {
            max=num;
        }
        printf("Depois do %d numero temos:\nMenor = %d\nMaior = %d\n\n", contador, min, max);
    }
}
