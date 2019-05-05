#include <stdio.h>
#include <windows.h>
#define MAX 10

typedef struct Datas
{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct Pessoas
{
    int id;
    char nome[30];
    char email[30];
    Data dtnasc;
    char tlf[15];
    int ano;
}Pessoa;

void ler_pessoa(Pessoa *xpto);
void exibir_pessoa(Pessoa xpto);
void ativar_desativar_pessoa(Pessoa *xpto, int tam);
void listar_ativos(Pessoa *xpto, int tam);
void listar_inativos(Pessoa *xpto, int tam);
int menu();

void main()
{
    Pessoa membro[MAX];
    int opMenu;
    int i, tam=0;
    do{
        opMenu=menu();
        switch(opMenu)
        {
            case 1:
                if(tam!=0)
                {
                    for(i=0;i<tam;i++)
                        exibir_pessoa(membro[i]);
                }
                else
                    printf("\nLista Vazia");
                getch();
                break;
            case 2:
                membro[tam].id = tam+1;
                ler_pessoa(&membro[tam]);
                tam++;
                break;
            case 3:
                ativar_desativar_pessoa(membro,tam);
                break;
            case 4:
                listar_ativos(membro,tam);
                break;
            case 5:
                listar_inativos(membro,tam);
                break;

        }
    }while(opMenu!=0);
}

int menu()
{
    int op;
    do{
        fflush(stdin);
        system("cls");
        printf(" *** C O N T A T O ***\n");
        printf(" **  1 - Listar     **\n");
        printf(" **  2 - Inserir    **\n");
        printf(" **  3 - Des/Ativar **\n");
        printf(" **  4 - L. Ativos  **\n");
        printf(" **  5 - L. Inativos**\n");
        printf(" **  0 - Sair       **\n");
        printf(" **  ** ** ** ** ** **\n\n");
        printf("\tOpcao: ");
        scanf("%d",&op);
    }while(op<0 || op>3);
    return op;
}

void ler_pessoa(Pessoa *xpto)
{
    system("cls");
    printf("\n\n*** A Receber Pessoa ***\n");
    printf("\nNumero: %d",(*xpto).id);
    printf("\nNome: ");
    fflush(stdin);
    gets((*xpto).nome);
    printf("Dt nasc (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&(*xpto).dtnasc.dia,&(*xpto).dtnasc.mes,&(*xpto).dtnasc.ano);
    printf("Tlf: ");
    scanf("%s",&(*xpto).tlf);
    printf("Email: ");
    fflush(stdin);
    gets((*xpto).email);
}

void exibir_pessoa(Pessoa xpto, int opMenu)
{
    printf("\n\nNumero: %d - ",xpto.id);
    printf("Nome: %s",xpto.nome);
    if(xpto.id<0) printf("**INATIVO**");
    printf("\nDt Nasc: %d/%d/%d",xpto.dtnasc.dia,xpto.dtnasc.mes,xpto.dtnasc.ano);
    printf("\nTlf: %s - ",xpto.tlf);
    printf("Email: %s",xpto.email);
    getch();
}

void ativar_desativar_pessoa(Pessoa *xpto,int tam)
{
    int i;
    int op;
    int id;
    printf("\n\n*** Ativar/Desativar Pessoa ***\n\n");
    printf("1. Ativar pessoa\n");
    printf("2. Desativar pessoa\n\n");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
            system("cls");
            printf("\n\n*** Ativar Pessoa***\n\n");
            for(i=0;i<tam;i++)
            {
                if(xpto[i].id<0)
                    exibir_pessoa(xpto[i]);
            }
            printf("\nAtivar pessoa: ");
            scanf("%d",&id);
            xpto[i].id = -xpto[i].id;
            break;

        case 2:
            system("cls");
            printf("\n\n*** Desativar Pessoa***\n\n");
            for(i=0;i<tam;i++)
            {
                if(xpto[i].id>0)
                    exibir_pessoa(xpto[i]);
            }
            printf("Desativar pessoa: ");
            scanf("%d",&id);
            xpto[i].id = -xpto[i].id;
            break;
    }
}

void listar_ativos(Pessoa *xpto, int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(xpto[i].id>0)
        {
            printf("\n\nNumero: %d - ",xpto[i].id);
            printf("Nome: %s",xpto[i].nome);
            printf("\nDt Nasc: %d/%d/%d",xpto[i].dtnasc.dia,xpto[i].dtnasc.mes,xpto[i].dtnasc.ano);
            printf("\nTlf: %s - ",xpto[i].tlf);
            printf("Email: %s\n\n",xpto[i].email);
        }
    }
    getch();
}

void listar_inativos(Pessoa *xpto, int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(xpto[i].id<0)
        {
            printf("\n\nNumero: %d - ",xpto[i].id);
            printf("Nome: %s",xpto[i].nome);
            printf("\nDt Nasc: %d/%d/%d",xpto[i].dtnasc.dia,xpto[i].dtnasc.mes,xpto[i].dtnasc.ano);
            printf("\nTlf: %s - ",xpto[i].tlf);
            printf("Email: %s\n\n",xpto[i].email);
        }
    }
    getch();
}
