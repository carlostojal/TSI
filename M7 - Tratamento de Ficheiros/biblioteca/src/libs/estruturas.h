//Carlos Tojal, nº5, 1ºTSI
//https://www.github.com/carlostojal/TSI/tree/master/M7 - Tratamento de Ficheiros/biblioteca/src/libs/estruturas.h


//Contém as estruturas de dados do programa

#include <stdio.h>

typedef struct Datas {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Alunos {
    int num_proc;
    char nome[30];
    int ano;
    char turma[20];
    char telemovel[20];
} Aluno;

typedef struct Manuais {
    char isbn[20];
    char titulo[20];
    char disciplina[20];
} Manual;

typedef struct Emprestimos {
    int id;
    int id_aluno;
    char id_manual[20];
    Data data_levantamento;
    float valor;
} Emprestimo;
