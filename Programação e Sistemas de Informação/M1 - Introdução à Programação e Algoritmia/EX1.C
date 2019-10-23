#include <stdio.h>

int main(void)
{
    int npar=100, soma=0;

    printf("SOMA DOS NUMEROS PARES DE 100 A 200\n\n");

    while (npar<=200)
    {
        soma = soma + npar;
        printf("%d      Soma = %d\n", npar, soma);
        npar = npar + 2;
    }
}

/*
void main(void)
{
    int numpar, soma=0;
    for(numpar=100; numpar<=200; numpar+=2)
    {
        soma +=npar;
        printf("%d  Soma = %d\n", npar, soma);
        npar = npar + 2;
    }
}
*/

