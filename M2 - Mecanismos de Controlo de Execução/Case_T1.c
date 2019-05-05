#include <stdio.h>

void main(void)
{
    int op;
    do
    {
        system("cls");
        printf("Introduza um numero inteiro (0 para terminar): \n");
        scanf("%d",&op);
        if((op>0) && (op<8)) printf("\nO %d%c dia corresponde a ",op,167);
        switch(op)
        {
            case 1: printf("Domingo");break;
            case 2: printf("Segunda");break;
            case 3: printf("Terca");break;
            case 4: printf("Quarta");break;
            case 5: printf("Quinta");break;
            case 6: printf("Sexta");break;
            case 7: printf("Sabado");break;
            default:{ if(op==0) printf("Optou por terminar...");
                      else printf("O valor %d nao corresponde a nenhum dia da semana",op);
                    }
        }
        getch();
    }while(op!=0);
}
