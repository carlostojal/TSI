#include <stdio.h>
#include<windows.h>

void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD) {x-1,y-1});
}

void main()
{
    int x,y,x1,y1,x2,y2,x3,y3,x4,y4;
    printf("Qual o tamanho da matriz quadrada? ");
    scanf("%d",&x);
    x+=2;
    y=x;
    x1=2;
    y1=2;
    x2=x;
    y2=2;
    if(x%2!=0)
        x3=(x/2)+1;
    else
        x3=x/2;
    y3=2;
    x4=2;
    y4=x3;
    while(x1!=x)
    {
        gotoxy(x1,y1);
        printf("*");
        x1++;
        y1++;
    }
    while(x2!=2)
    {
        gotoxy(x2,y2);
        printf("*");
        x2--;
        y2++;
    }
    while(y3!=y)
    {
        gotoxy(x3,y3);
        printf("*");
        y3++;
    }
    while(x4!=x)
    {
        gotoxy(x4,y4);
        printf("*");
        x4++;
    }
    gotoxy(24,24);
}
