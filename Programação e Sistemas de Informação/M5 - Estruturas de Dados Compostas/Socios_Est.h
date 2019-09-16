#include <stdio.h>

typedef struct Datas
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Socios
{
    int idSocio;
    char nome[25];
    char morada[25];
    char NIF[25];
    char telefone[25];
    Data dtnascSocio;
} Socio;

typedef struct Quotas
{
    int idQuota;
    int idSocio;
    char periodo[25];
    float valor;
    Data dtPagamento;
} Quota;
