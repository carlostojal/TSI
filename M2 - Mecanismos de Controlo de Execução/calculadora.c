#include <stdio.h>

float FuncSoma(int num1, int num2);
float FuncSub(int num1, int num2);
float FuncMult(int num1, int num2);
float FuncDiv(int num1, int num2);

void main(void)
{
    int num1, num2;
    char op;

    printf("\t  ------------------------------------\n");
    printf("\t /             CALCULADORA           /\n");
    printf("\t -----------------------------------\n\n");
    printf(" Introduza o 1o num, operador e 2o num separados por espacos: ");
    scanf("%d %c %d", &num1, &op, &num2);

    switch(op)
    {
        case '+': printf("\n%d + %d = %.0f\n", num1, num2, FuncSoma(num1, num2)); break;
        case '-': printf("\n%d - %d = %.0f\n", num1, num2, FuncSub(num1, num2)); break;
        case '*': printf("\n%d * %d = %.0f\n", num1, num2, FuncMult(num1, num2)); break;
        case '/': if (num2!=0) printf("\n%d / %d = %.0f", num1, num2, FuncDiv(num1, num2)); break;
        default: printf("\nOperador invalido!\n");
    }
}

float FuncSoma(int num1, int num2)
{
    return num1+num2;
}

float FuncSub(int num1, int num2)
{
    return num1-num2;
}

float FuncMult(int num1, int num2)
{
    return num1*num2;
}

float FuncDiv(int num1, int num2)
{
    return num1/num2;
}


