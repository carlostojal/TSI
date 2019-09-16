#include <stdio.h>

void main(main)
{
    float raio, v;

    printf("Pretende-se calcular o volume de uma esfera\n\n");
    printf("Introduza o valor do raio: ");
    scanf("%f",&raio);
    printf("\n\n    V = 4/3 x 3.14 x raio^3\n\n");
    printf("(=) V = 4/3 x 3.14 x %.2f^3\n\n", raio);
    printf("(=) V = 4/3 x 3.14 x %.2f\n\n", raio*raio*raio);
    v = (float) 4/3 * 3.14 * (raio*raio*raio);
    printf("(=) V = %.2f cm3\n", v);
}
