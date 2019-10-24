#include <stdio.h>

void main()
{
    typedef struct Datas
    {
        int dia;
        char mes[10];
        int ano;
    }Data;

    typedef struct Pessoas
    {
        char nome[20];
        Data dtnasc;
    }Pessoa;

    Pessoa lista[3];

    int x;

    for(x=0;x<3;x++)
    {
        fflush(stdin);
        printf("\nIntroduza o nome do %d elemento: ",x+1);
        gets(lista[x].nome);
        printf("\nIntroduza o dia de nasc. do %d elemento (%s): ",x+1,lista[x].nome);
        scanf("%d",&lista[x].dtnasc.dia);
        printf("\nIntroduza o mes de nasc. do %d elemento (%s): ",x+1,lista[x].nome);
        scanf("%s",&lista[x].dtnasc.mes);
        printf("\nIntroduza o ano de nasc. do %d elemento (%s): ",x+1,lista[x].nome);
        scanf("%d",&lista[x].dtnasc.ano);
    }
    printf("\n\n##### Listagem de Aniversarios #####\n");
    for(x=0;x<3;x++)
        printf("\n%d Elemento da lista: %s, %d de %s",x+1,lista[x].nome,lista[x].dtnasc.dia,lista[x].dtnasc.mes);
    getch();
}
