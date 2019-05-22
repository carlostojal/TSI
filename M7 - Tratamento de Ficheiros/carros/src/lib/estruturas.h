#include <stdio.h>

typedef struct Datas {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Inspecoes {
    Data data;
    char apontamentos[255];
    struct Inspecoes *prox;
    struct Inspecoes *ant;
} Inspecao;

typedef struct Carros {
    int id;
    char marca[20];
    char modelo[30];
    Inspecao inspecao;
    struct Carros *prox;
    struct Carros *ant;
} Carro;
