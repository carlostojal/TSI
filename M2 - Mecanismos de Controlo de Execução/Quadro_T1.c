#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD) {x-1,y-1});
}

void quadro(int x1, int y1, int x2, int y2)
{
    int x,y;
    for(x=x1+1;x<x2;x++)
    {
        gotoxy(x,y1);printf("%c",205);
        gotoxy(x,y2);printf("%c",205);
    }

    for(y=y1+1;y<y2;y++)
    {
        gotoxy(x1,y);printf("%c",186);
        gotoxy(x2,y);printf("%c",186);
    }
    gotoxy(x1,y1); printf("%c",201);
    gotoxy(x1,y2); printf("%c",200);
    gotoxy(x2,y1); printf("%c",187);
    gotoxy(x2,y2); printf("%c",188);
}

void main()
{
    quadro(1,1,80,25);
    getch();
}
