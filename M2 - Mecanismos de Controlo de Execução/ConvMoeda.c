#include <stdio.h>
#include <windows.h>
#define CL 1.1 //cambio libra (valor da libra em relacao ao euro
#define CD 0.84 //cambio dolar (valor do dolar em relacao ao euro

void Conversao(float valor, char tipo, float *, float *, float *);

void main()
{
    char Moeda;
    float Valor;
    float Euro=0, Dolar=0, Libra=0;
    char Rep='S';
    while(Rep=='S')
    {
        system("cls");
        printf("\n\t**CONVERSOR DE MOEDAS**\n\n");
        printf("Qual o valor? ");
        scanf("%f",&Valor);
        printf("\nQual a moeda? ");
        fflush(stdin);
        Moeda = toupper(getch());
        printf("A moeda introduzida foi %c",Moeda);
        printf("\n");
        Conversao(Valor,Moeda,&Euro,&Dolar,&Libra);
        printf("\nValor em Euro: %.2f",Euro);
        printf("\nValor em Dolar: %.2f",Dolar);
        printf("\nValor em Libra: %.2f",Libra);
        printf("\n\nDeseja repetir? [S] para repetir ou qualquer outra tecla para sair.");
        Rep = toupper(getch());
    }
}

void Conversao(float valor, char tipo, float *E, float *D, float *L)
{
    switch(tipo)
    {
        case 'E':
        {
            (*E)=valor;
            (*D)=valor*CD;
            (*L)=valor*CL;
            break;
        }
        case 'D':
        {
            (*D)=valor;
            (*E)=valor/1.1;
            (*L)=(valor/CD)*CL;
            break;
        }
        case 'L':
        {
            (*L)=valor;
            (*E)=valor/CL;
            (*D)=(valor/CL)*CD;
        }
    }
}

/*
#include <stdio.h>
#include <windows.h>

//1€ = 1,1USD = 0,84Libras
void Conversao(float valor, char tipo);

void main()
{
    char Moeda;
    float Valor;
    char Rep='S';
    while(Rep=='S')
    {
        system("cls");
        printf("\n\t**Conversor de Moedas**\n\n");
        printf("Qual o valor? ");
        scanf("%f",&Valor);
        printf("\nQual a moeda? ");
        Moeda = toupper(getch());
        printf("\n");
        Conversao(Valor,Moeda);
        printf("\nDeseja repetir? [S] para repetir ou qualquer outra tecla para sair.");
        Rep = toupper(getch());
    }
}

Conversao(float valor, char tipo)
{
    switch(tipo)
    {
        case 'E':
        {
            printf("Valor em Euro: %.2f\n",valor);
            printf("Valor em USD: %.2f\n",valor*1.1);
            printf("Valor em Libras: %.2f\n",valor*0.84);
            break;
        }
        case 'D':
        {
            printf("Valor em Euro: %.2f\n",valor/1.1);
            printf("Valor em USD: %.2f\n",valor);
            printf("Valor em Libras: %.2f\n",(valor/1.1)*0.84);
            break;
        }
        case 'L':
        {
            printf("Valor em Euro: %.2f\n",valor/0.84);
            printf("Valor em USD: %.2f\n",(valor/0.84)*1.1);
            printf("Valor em Libras: %.2f\n",valor);
            break;
        }
    }
}
*/
