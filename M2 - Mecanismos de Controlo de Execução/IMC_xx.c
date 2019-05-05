#include <stdio.h>
#include <math.h>

void main(void)
{
    float peso, altura, imc;
    printf("Introduza o seu peso (kg): ");
    scanf("%f",&peso);
    printf("Introduza a sua altura (m): ");
    scanf("%f",&altura);

    imc=peso/(altura*altura);
    printf("\n\n     IMC = Peso/Altura%c\n",253);
    printf(" (=) IMC = %.2f/%.2f\n",peso,altura*altura);
    printf(" (=) IMC = %.2f\n\n",imc);

    if(imc<22)
        printf("O seu IMC e %.1f e o seu estado e magreza.\n",imc);
    else if(imc>27)
        printf("O seu IMC e %.1f e o seu estado e excesso de peso.\n",imc);
    else
        printf("O seu IMC e %.1f e o seu estado e excesso de eutrofia.\n",imc);
    getch();
}
