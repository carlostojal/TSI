#include <stdio.h>
#include <windows.h>

void main()
{
    int OpMenu;
    int boletim[5][7];
    int aleat;
    int sorteio[7];
    int aposta;
    int num;
    int num1;
    int numeros=0;
    int estrelas=0;

    do{
        system("cls");
        printf("\n\t**Euromilhoes**\n\n");
        printf(" 1 - Definir Apostas\n");
        printf(" 2 - Simular Sorteio\n");
        printf(" 3 - Validar Acertos\n");
        printf(" 4 - Sair\n\n");
        printf("\tOpcao: ");
        fflush(stdin);
        scanf("%d",&OpMenu);
    }while((OpMenu<1)||(OpMenu>4));

    switch(OpMenu)
    {
        case 1: {
            for(aposta=0;aposta<5;aposta++)
            {
                system("cls");
                printf("**APOSTA NO. %d\n\n",aposta+1);
                for(num=0;num<7;num++)
                {
                    if(((num+1)>=1)&&((num+1)<=5))
                        printf("%d numero: ",num+1);
                    else
                        printf("%d estrela: ",num-4);
                    fflush(stdin);
                    //while((boletim[aposta][num])<1&&(boletim[aposta][num]>50))
                        scanf("%d",&boletim[aposta][num]);
                    printf("\n");
                }
            }
            getch();
            break;
        }
        case 2: {
            time_t t;
            system("cls");
            printf("\n\t**SORTEIO**\n\n");
            printf("Chave sorteada:\n");
            srand((unsigned) time(&t));
            while(num<7)
            {
                aleat=rand()%50;
                if(num+1<=5)
                {
                    if(aleat>=1&&aleat<=50)
                    {
                        sorteio[num]=aleat;
                        printf("%d ",sorteio[num]);
                        num++;
                    }
                }
                else
                {
                    if(aleat>=1&&aleat<=12)
                    {
                        sorteio[num]=aleat;
                        printf("*%d ",sorteio[num]);
                        num++;
                    }
                }
            }
            getch();
            break;
        }
        case 3: {
            for(num1=0;num1<7;num1++)
            {
                for(aposta=0;aposta<5;aposta++)
                {
                    for(num=0;num<7;num++)
                    {
                        if(boletim[aposta][num]==sorteio[num1])
                        {
                            if(num<5&&num1<5)
                                numeros++;
                            else if(num>=5&&num1>=5)
                                estrelas++;
                        }
                    }
                }
            }
            system("cls");
            printf("\n**VALIDAR ACERTOS**\n\n");
            if(numeros==0&&estrelas==0)
                printf("Infelizmente nao acertou nada.\n");
            else if(numeros==0)
                printf("Infelizmente nao acertou nenhum numero, mas acertou %d estrelas.\n",estrelas);
            else if(estrelas==0)
                printf("Infelizmente nao acertou nenhuma estrela, mas acertou %d numeros.\n",numeros);
            else if(numeros==5&&estrelas==5)
                printf("Parabens! Acertou todos os numeros e todas as estrelas.\n");
            else
                printf("Acertou %d numeros e %d estrelas.\n",numeros, estrelas);
            printf("\n\t**Suas apostas**\n\n");
            for(aposta=0;aposta+1<=5;aposta++)
            {
                for(num=0;num+1<=7;num++)
                {
                    if(num+1<=5)
                        printf("%d ",boletim[aposta][num]);
                    else
                        printf("*%d ",boletim[aposta][num]);
                }
                printf("\n");
            }
            printf("\n\n");
            printf("**Chave sorteada**\n\n");
            for(num=0;num+1<=7;num++)
            {
                if(num+1<=5)
                    printf("%d ",sorteio[num]);
                else
                    printf("*%d ",sorteio[num]);
            }
        }
    }
}
