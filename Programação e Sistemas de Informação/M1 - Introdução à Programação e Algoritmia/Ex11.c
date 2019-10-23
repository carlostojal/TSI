#include <stdio.h>

void main(void)
{
    float bits = 0, Bytes, KB, MB, GB;

    system("title Conversor de Unidades");
    while (bits >= 0)
    {
        printf("Introduza o numero de bits: ");
        scanf("%f", &bits);
        Bytes = bits / 8;
        KB = Bytes / 1024;
        MB = KB / 1024;
        GB = MB / 1024;

        printf("\n\n%.0f bits\n", bits);
        printf("%.3f Bytes\n", Bytes);
        printf("%f KB\n", KB);
        printf("%f MB\n", MB);
        printf("%f GB\n\n", GB);
    }
    printf("ERRO: O numero de bits nao pode ser negativo!\n");
}
