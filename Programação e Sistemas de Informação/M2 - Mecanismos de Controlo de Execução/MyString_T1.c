#include <stdio.h>

int mystrlen(char s[100])
{
    int i=0,cont=0;

    while(s[i]!='\0')
    {
        cont++;
        i++;
    }
    return cont;
}

void mystrcpy(char sd[100], int n, char so[100])
{
    int i;
    for(i=0;i<n;i++)
    {
        sd[i]=so[i];
    }
    sd[i]='\0';
}

void mystrupr(char sd[100], int n, char so[100])
{
    int i;
    for(i=0;i<n;i++)
    {
        sd[i]=toupper(so[i]);
    }
    sd[i]='\0';
}

int myprocchar(char s[],char letra)
{
    int c, found=0;
    for(c=0;c<mystrlen(s);c++)
        if(s[c]==letra)
        {
            found=c+1;
            break;
        }
    return found;
}

int mycharcount(char s[],char letra)
{
    int c, cont=0;
    for(c=0;c<mystrlen(s);c++)
        if(s[c]==toupper(letra))
        {
            cont++;
        }
    return cont;
}

void mypassword(char pwd[])
{
    int i=0;
    printf("\nIntroduza a password: ");
    while(1)
    {
        fflush(stdin);
        pwd[i]=getch();
        if(pwd[i]==13)
            break;
        printf("*");
        i++;
    }
    pwd[i]='\0';
}

void mypwdcript(char pwd[],char pwdorig[])
{
    int i=0;
    printf("\nIntroduza a password: ");
    while(1)
    {
        fflush(stdin);
        pwdorig[i]=getch();
        if(pwdorig[i]%2==0) pwd[i]=pwdorig[i]+1;
        else pwd[i]=pwdorig[i]-1;
        if(pwdorig[i]==13) break;
        if(pwdorig[i]==8) continue;
        printf("*");
        i++;
    }
    pwd[i]='\0';
}

void main()
{
    char str1[100],str2[100], pwd[100];
    int tam;
    char letra;
    int pos;
    int cont;

    /*
    printf("Introduza uma string: ");
    gets(str1);

    tam = mystrlen(str1);
    printf("\nA string %s tem %d caracteres.\n",str1,tam);

    mystrcpy(str2,tam,str1);
    printf("\nA string copiada: %s\n",str2);

    mystrupr(str2,tam,str1);
    printf("\nA string em maiusculas: %s\n\n",str2);

    printf("Qual o caracter a procurar? ");
    letra=getch();
    pos = myprocchar(str1,letra);
    if(pos!=0)
    {
        printf("\nO caracter %c foi encontrada na %d posicao.\n",letra,pos);
    }
    else
    {
        printf("\nO caracter \"%c\" nao foi encontrado  %d.\n",letra,pos);
    }
    cont = mycharcount(str1,letra);
    printf("\nO caracter \"%c\" foi encontrado %d vezes.\n",letra,cont);


    mypassword(str2);
    printf("\nA password lida foi: %s",str2);
    */

    /*
    mypwdcript(pwd,str2);
    printf("\n\nPassword original: %s",str2);
    printf("\nPassword encriptada: %s",pwd);
    */
}
