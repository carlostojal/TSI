#include <stdio.h>

/*
void main (void)
{
    int i=1,num;
    printf("Introduza o limite superior: ");
    scanf("%d",&num);
    do
    {
        printf("\t%d\n",i);
        i+=2;if(L1=='K'||L1=='Y'||L1=='W')
        {
            continue;
        }
    }while(i<=num);
}*/

/*
void main(void)
{
    int i=0,num;
    printf("Qual o limite superior? ");
    scanf("%d",&num);
    do
    {
        i++;
        if(i%2==0) continue;
        if(i%7==0) break;
        printf("\n\t%d\n",i);
    }while(i<num);
}*/

/*
void main(void)
{
    int letra='A';
    do{
        if(letra=='K'||letra=='Y'||letra=='W')
            printf("");
        else printf("%c ",letra);
        letra++;
    }while(letra<='Z');
}*/

/*
void main(void)
{
    int letra='A';
    do{
        printf("%c(%.2d) - %c(%.2d)\n",letra,letra,letra+32,letra+32);
        letra++;
    }while(letra<='Z');
}*/

/*
void main(void)
{
    long int fat=1;
    int n,num;
    printf("Qual o numero a calcular? ");
    scanf("%d",&num);
    n = num;
    printf("\n\t%d! = %d",num,num);
    do{
            fat=fat*n;
            n--;
            printf(" x %d",n);
    }while(n>1);
    printf(" = %d",fat);
    getch();
}*/

void main(void)
{
    int op;
    do{
        do{
            system("cls";
            printf("***MENU***\n");
            printf("1. Introduzir\n");
            printf("2. Listar\n");
            printf("3. Eliminar\n");
            printf("0, Sair\n\n");
            printf("Introduza um opcao: ");
            scanf("%d",&op);
            }while(op<0 || op>3);
            switch(op)
            {
                case 1: printf("Escolheu opcao 1\n"); break;
                case 2: printf("Escolheu opcao 2\n"); break;
                case 3: printf("Escolheu opcao 3\n"); break;
                case 0: printf("Adeus\n"); break;
            }
            getch();
    }while(op!=0)
}
