#include <stdio.h>
#include <stdlib.h

typedef struct Elementos {
    int num;
    struct Elemento *prox;
}Elemento;

int tam;
int ordem=0;

void inicia(Elemento *FILA);
void Listar(Elemento *FILA);
void Liberta(Elemento *FILA);
void insereFim(Elemento *FILA);

Elemento *criaNo();
Elemento *retiraInicio(Elemento *FILA);

int menu();
void opcao(Elemento *FILA,int op);

void main()
{
    int opt;
    Elemento *FILA = (Elemento*)malloc(sizeof(Elemento));
    if(!FILA)
    {
        printf("Sem memoria disponivel.\n");
        exit(1);
    }else{
        inicia(FILA);

    }
}
