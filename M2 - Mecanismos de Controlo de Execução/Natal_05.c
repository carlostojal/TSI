#include <stdio.h>

//Carlos Tojal, nº5, 1ºTSI

void main()
{
    int v, r, c;
    char ch;

    printf("\n");
    for(v=1;v<=4;v++)
    {
        for(r=1;r<=4;r++)
        {
            for(c=1;c<=9-r;c++)
            {
                if(v==1) ch='$';
                else if(v==2) ch='#';
                else if(v==3) ch='0';
                else ch='*';
                printf("%c",ch);
                if(v==1)
                    if(c==2) break;
                if(v==2)
                    if(c==9-r) break;
                if(v==3)
                    if(c==7-r) break;
                if(v==4)
                    if(c==5-r) break;
            }
            printf("\n");
        }
    }
    getch();
}
