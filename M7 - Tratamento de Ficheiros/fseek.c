#include <stdio.h>

int main()
{
    FILE *fp;
    int tam;

    fp = fopen("demo2.txt","w+");
    if(fp == NULL)
    {
        printf("Erro na abertura de ficheiro.");
        return -1;
    }
    fputs("Eu gosto muito de sopa",fp);
    fseek(fp,18,SEEK_SET);
    fputs("estudar no TSI da Bordalo!",fp);
    fclose(fp);

    fp = fopen("demo2.txt","r");
    fseek(fp,0,SEEK_END);
    tam = ftell(fp);
    printf("O ficheiro demo2.txt ocupa %d bytes\n",tam);
    rewind(fp);
    for(tam=1;tam<35;tam++)
    {
        printf("%c",getc(fp));
        fseek(fp,ftell(fp),0);
        if(tam%17==0) {
            rewind(fp);
            printf(" ...\n");
        }
    }
    fclose(fp);
    return 0;
}
