//Carlos Tojal, nº5, 1ºTSI
//https://www.github.com/carlostojal/TSI/tree/master/M7 - Tratamento de Ficheiros/biblioteca/src/libs/manuais.h

//Contém as funções de gestão dos manuais

#include <stdio.h>
#include <stdlib.h>

void adicionar_manual(Manual *lista)
{
    FILE *fp;
    Manual *novo;
    printf("\n** Adicionar Manual**\n\n");
    printf("ISBN: ");
    scanf("%s",novo->isbn);
    printf("Titulo: ");
    scanf("%s",novo->titulo);
    printf("Disciplina: ");
    scanf("%s",novo->disciplina);
    fp = fopen("manuais.dat","a");
    fprintf(fp,"%s %s %s\n",novo->isbn,novo->titulo,novo->disciplina);
    fclose(fp);
}
