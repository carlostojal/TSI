#include <stdio.h>

void main(void)
{
    int x = 4, y = 2, z = 10;

    printf("Adivinhe o output...");
    getch();
    printf("\nX=%d\tY=%d\tZ=%d", x, y, z);
    getch();
    x++; y--; z+=5;
    printf("\nX=%d\tY=%d\tZ=%d", x, y, z);
    getch();
    z*=3; y = --z; x= --y;
    printf("\nX=%d\tY=%d\tZ=%d", x, y, z);
    getch();
    printf("\nX=%d\tY=%d\tZ=%d", --x, y++, z--);
    getch();
    printf("\nX=%d\tY=%d\tZ=%d", x, y, z);
    x--; ++y; --z;
    getch();
    printf("\nX=%d\tY=%d\tZ=%d", x, y, z);
    getch();
}
