//Carlos Tojal, nº5, 1ºTSI
//https://www.github.com/carlostojal/TSI/tree/master/M7 - Tratamento de Ficheiros/biblioteca/src/libs/estruturas.h
//biblioteca/src/libs/estruturas.h

//Contém as estruturas de dados do programa

#include <stdio.h>

typedef struct Datas {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Alunos {
    int num_proc; //chave primária
    char nome[30];
    int ano;
    char turma[20];
    char telemovel[20];
    struct Alunos *prox;
    struct Alunos *ant;
} Aluno;

typedef struct Manuais {
    char isbn[20]; //chave primária
    char titulo[30];
    char disciplina[20];
    struct Manuais *prox;
    struct Manuais *ant;
} Manual;

typedef struct Emprestimos {
    int id; //este
    int id_aluno; //+ este
    char id_manual[20]; //+ este = chave primária
    Data data_levantamento;
    float valor;
    struct Emprestimos *prox;
    struct Emprestimos *ant;
} Emprestimo;
