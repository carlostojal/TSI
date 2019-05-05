#include <stdio.h>

//Carlos Tojal, nº5, 1ºTSI

void main()
{
    char pwd[100], pwdcript[100];
    int i=0,j=0, k=0, l=0;
    printf("\nPassword: ");
    while(1)
    {
        fflush(stdin);
        pwd[i]=getch();
        if(pwd[i]==13)
            break;
        else if(pwd[i]==8)
            continue;
        printf("*");
        i++;
    }
    while(pwd[j]!='\0')
    {
        if(pwd[j]%2==0)
            pwdcript[j]=pwd[j]+2;
        else
            pwdcript[j]=pwd[j]-2;
        if(pwd[j]>=65&&pwd[j]<=90)
            pwdcript[j]=pwd[j]*2;
        else if(pwd[j]>=97&&pwd[j]<=122)
            pwdcript[j]=(pwd[j]-32)+100;
        else if(pwd[j]>=48&&pwd[j]<=57)
            pwdcript[j]=pwd[j]*3;
        j++;
    }
    printf("\n\nPassword normal: ");
    while(pwd[k]!='\0')
    {
        printf("%c",pwd[k]);
        k++;
    }
    printf("\nPassword encriptada: ");
    while(pwdcript[l]!='\0')
    {
        printf("%c",pwdcript[l]);
        l++;
    }
    printf("\n");
    getch();
}
