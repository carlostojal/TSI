#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *origem = fopen(argv[1],"r");
    FILE *destino = fopen(argv[2],"w");
    char temp[50];
    int i;
    fprintf(destino,"");
    fclose(destino);
    destino = fopen(argv[2],"a");
    while(!feof(origem))
    {
        fgets(temp,50,origem);
        for(i=0;temp[i]!='\0';i++)
            temp[i]=toupper(temp[i]);
        fprintf(destino,"%s",temp);
        strcpy(temp,"");
    }
    fclose(origem);
    fclose(destino);
    return 0;
}
