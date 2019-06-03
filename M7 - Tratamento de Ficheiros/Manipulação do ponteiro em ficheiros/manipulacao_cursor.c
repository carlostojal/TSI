//Manipulação do cursor em ficheiros

//Carlos Tojal
//nº5
//1º TSI

//Anexos no ficheiro "anexos.h"


//Output:

//Ecrã:
/*
* O ficheiro demo2.txt ocupa 44 bytes
* Eu gosto muito de ...
* Eu gosto muito de ...
*/

//Ficheiro demo2.txt:
/*
* Eu gosto muito de estudar no TSI da Bordalo!
*/


//Bibliotecas
#include <stdio.h>

//Código principal
int main()
{
    FILE *fp;
    int tam;

    fp = fopen("demo2.txt","w+"); //abre o ficheiro para leitura e escrita
    if(fp == NULL)
    {
        printf("Erro na abertura de ficheiro.");
        return -1;
    }
    fputs("Eu gosto muito de sopa",fp);
    fseek(fp,18,SEEK_SET); //posiciona o ponteiro do ficheiro na posição 18, depois do início do ficheiro (SEEK_SET). Pode ser substituído por 0.
    fputs("estudar no TSI da Bordalo!",fp); //escreve por cima do conteúdo existente a partir dessa mesma posição
    fclose(fp);

    fp = fopen("demo2.txt","r"); //abre o ficheiro para leitura
    fseek(fp,0,SEEK_END); //posiciona o cursor 0 posições depois do fim do ficheiro (SEEK_END). Pode ser substituído por 2.
    tam = ftell(fp); //calcula quantos caracteres/bytes tem o ficheiro até à posição atual do cursor (fim)
    printf("O ficheiro demo2.txt ocupa %d bytes\n",tam);
    rewind(fp); //coloca o ponteiro no início do ficheiro
    for(tam=1;tam<35;tam++)
    {
        printf("%c",getc(fp)); //mostra o caractere atual
        fseek(fp,ftell(fp),0); //posiciona o ponteiro uma posição à frente
        if(tam%17==0) { //se o contador for divisível por 17, volta ao início do ficheiro e escreve "..."
            //
            rewind(fp);
            printf(" ...\n");
        }
    }
    fclose(fp);
    return 0;
}
