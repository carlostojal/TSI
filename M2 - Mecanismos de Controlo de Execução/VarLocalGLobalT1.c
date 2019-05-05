#include <stdio.h>

int troca(int x, int y, int z)
{
    int aux;
    aux = z;
    z = x++; //primeiro utiliza e depois incrementa
    x = --y; //primeiro decrementa e depois utiliza
    y = aux;
    printf("\nNa troca: X=%d\tY=%d\tZ=%d",x,y,z);
    return 0;
}

void main(void)
{
    int x=5, y=10, z=20;

    x = troca(x,y,z); //x recebe o valor devolvido pela função troca

    printf("\nNa main: X=%d\tY=%d\tZ=%d",x,y,z);
}

/*int z=20;

int troca(int x, int y)
{
    int aux;
    aux = z;
    z = x++; //primeiro utiliza e depois incrementa
    x = --y; //primeiro decrementa e depois utiliza
    y = aux;
    printf("\nNa troca: X=%d\tY=%d\tZ=%d",x,y,z);
    return 0;
}

void main(void)
{
    int x=5, y=10;

    x = troca(x,y); //x recebe o valor devolvido pela função troca

    printf("\nNa main: X=%d\tY=%d\tZ=%d",x,y,z);
}
*/
