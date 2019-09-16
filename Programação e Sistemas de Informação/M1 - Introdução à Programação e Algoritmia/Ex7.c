#include <stdio.h>

void main(void)
{
    int dia;

    while(dia>0 && dia<8)
    {
        printf("Digite um numero para que o mesmo seja correspondido a um dia da semana: ");
        scanf("%d", &dia);
        switch(dia)
        {
        case 1:
            printf("Domingo\n\n");
            break;

        case 2:
            printf("Segunda-feira\n\n");
            break;
        case 3:
            printf("Terca-feira\n\n");
            break;
        case 4:
            printf("Quarta-feira\n\n");
            break;
        case 5:
            printf("Quinta-feira\n\n");
            break;
        case 6:
            printf("Sexta-feira\n\n");
            break;
        case 7:
            printf("Sabado\n\n");
            break;
        default:
            printf("Dia Invalido!\n\n");
        }
    }
}
