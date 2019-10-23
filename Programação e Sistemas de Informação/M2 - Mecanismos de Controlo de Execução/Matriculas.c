#include <stdio.h>

void main (void)
{
    int D1,D2,D3,D4;
    char L1,L2;
    int matricula=0;

    for(L1='A';L1<='Z';L1++)
    {
        if(L1=='K'||L1=='Y'||L1=='W')
        {
            continue;
        }
        for(L2='A';L2<='Z';L2++)
        {
            if(L1=='K'||L1=='Y'||L1=='W')
            {
                continue;
            }
            for(D1=0;D1<=9;D1++)
            {
                for(D2=0;D2<=9;D2++)
                {
                    for(D3=0;D3<=9;D3++)
                    {
                        for(D4=0;D4<=9;D4++)
                        {
                            printf("%d%d-%c%c-%d%d\t",D1,D2,L1,L2,D3,D4);
                            matricula++;
                        }
                    }
                }
            }
        }
        printf("\nNumero de matriculas: %d\n\n",matricula);
        getch();
    }
    printf("Total de matriculas: %d",matricula);
}
