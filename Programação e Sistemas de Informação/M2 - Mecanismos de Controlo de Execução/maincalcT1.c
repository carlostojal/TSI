#include <stdio.h>

float soma(int num1, int num2);
float sub(int num1, int num2);
float mult(int num1, int num2);
float div(int num1, int num2);

int main(int argc, int *argv[])
{
    int num1, num2;
    char op;
    if(argc!=4)
    {
        printf("maincalc n1 operador n2");
        exit(1);
    }
    num1 = atoi(argv[1]);
    op = argv[2][0];
    num2 = atoi(argv[3]);
    switch(op)
    {
        case '+': printf("\n%d + %d = %.1f\n", num1, num2, soma(num1, num2)); break;
        case '-': printf("\n%d - %d = %.1f\n", num1, num2, sub(num1, num2)); break;
        case 'x': printf("\n%d * %d = %.1f\n", num1, num2, mult(num1, num2)); break;
        case '/': if (num2!=0) printf("\n%d / %d = %.1f\n", num1, num2, div(num1, num2)); break;
        default: printf("\nOperador invalido!\n"); break;
    }
}

float soma(int num1, int num2)
{
    return num1 + num2;
}

float sub(int num1, int num2)
{
    return num1 - num2;
}

float mult(int num1, int num2)
{
    return num1 * num2;
}

float div(int num1, int num2)
{
    return num1 / num2;
}
