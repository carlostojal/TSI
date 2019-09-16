#include <stdio.h>

void main(void)
{
    int qtd=0;
    float preco=0, total=0;

    system("title EX2");

    printf("Pretende-se calcular o valor da fatura EDP\n\n");
    printf("Quantos KWh consumiu? ");
    scanf("%d",&qtd);
    printf("Qual o preco do kWh? ");
    scanf("%f",&preco);
    total = preco * qtd;
    printf("\nValor a pagar = %.2f Euros\n", total);


}
