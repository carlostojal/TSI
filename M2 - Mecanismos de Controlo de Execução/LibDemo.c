#include <stdio.h>
#include <G:\Programacao e Sistemas de Informacao\1�TSI\M2 - Mecanismos de Controlo de Execu��o\Exerc�cios\LibDemo\mylib.h>

void main(void)
{
    int x=5, y=10;
    int res=0;

    printf("%d + %d = %d\n",x,y,soma(x,y));
    printf("%d - %d = %d\n",x,y,subtrai(x,y));
    getch();
}
