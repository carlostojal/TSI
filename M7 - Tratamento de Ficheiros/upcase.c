#include <stdio.h>
#include <string.h>

int main()
{
    FILE *texto = fopen("texto.txt","r");
    FILE *maiusculas = fopen("maiusculas.txt","w");
    char temp[50];
    int i;
    fprintf(maiusculas,"");
    fclose(maiusculas);
    maiusculas = fopen("maiusculas.txt","a");
    while(!feof(texto))
    {
        fgets(temp,50,texto);
        for(i=0;temp[i]!='\0';i++)
            temp[i]=toupper(temp[i]);
        fprintf(maiusculas,"%s",temp);
        strcpy(temp,"");
    }
    fclose(texto);
    fclose(maiusculas);
    return 0;
}
