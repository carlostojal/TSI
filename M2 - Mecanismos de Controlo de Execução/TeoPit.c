#include <stdio.h>
#include <math.h>

void main(void)
{
    float cat1, cat2, hip;
    printf("TEOREMA DE PITAGORAS\n\n");
    printf("Introduza o valor de um cateto: ");
    scanf("%f", &cat1);
    printf("\nIntroduza o valor de outro cateto: ");
    scanf("%f", &cat2);

    hip = sqrt(pow(cat1,2)+pow(cat2,2));

     printf("\n\n");
    printf("       |\\\n");
    printf("       | \\ %.2f\n", hip);
    printf("  %.2f |  \\\n", cat1);
    printf("       |   \\\n");
    printf("       |____\\\n");
    printf("        %.2f\n", cat2);
}
