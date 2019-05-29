//Carlos Tojal, nº5, 1ºTSI

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estruturas de Dados
typedef struct Clientes {
    int id;
    char nome[20];
    char telemovel[20];
}Cliente;

//Protótipos
int menu();
int submenu(char *tipo);
void adicionar_cliente(Cliente *novo,int id);
void listar_cliente(Cliente cliente);

//Main
int main()
{
    int i;
    int opt,subopt;
    int tam=0;
    Cliente pesquisa;
    Cliente clientes[1000];
    FILE *fp = fopen("clientes.csv","r");
    while(!feof(fp))
    {
        fscanf(fp,"%d %s %s",&clientes[tam].id,clientes[tam].nome,clientes[tam].telemovel);
        tam++;
    }
    fclose(fp);
    do{
        opt = menu();
        switch(opt)
        {
            case 1:
                subopt = submenu("Clientes");
                switch(subopt)
                {
                    case 1:
                        printf("\nid: %d\n",tam);
                        adicionar_cliente(&clientes[tam-1],tam);
                        tam++;
                        break;
                    case 2:
                        printf("\n** Listar Clientes **\n");
                        for(i=0;i<tam-1;i++)
                            listar_cliente(clientes[i]);
                        break;
                    case 3:
                        printf("\n** Pesquisar Clientes **\n\n");
                        printf("Nome: ");
                        scanf("%s",pesquisa.nome);
                        for(i=0;i<tam-1;i++)
                        {
                            if(strcmp(clientes[i].nome,pesquisa.nome)==0)
                                listar_cliente(clientes[i]);
                        }
                }
                break;
        }
    }while(opt);
    fp = fopen("clientes.csv","w");
    fclose(fp);
    fp = fopen("clientes.csv","a");
    for(i=0;i<tam-1;i++)
        fprintf(fp,"%d %s %s\n",clientes[i].id,clientes[i].nome,clientes[i].telemovel);
    fclose(fp);
    return 0;
}

//Funções
int menu()
{
    int opt;
    do{
        printf("\n** Seguros **\n\n");
        printf("1. Clientes\n");
        printf("2. Apolices\n");
        printf("3. Simulacoes\n");
        printf("0. Sair\n\n");
        printf("Opcao: ");
        scanf("%d",&opt);
    }while(opt<0||opt>3);
    return opt;
}

int submenu(char *tipo)
{
    int opt;
    do{
        printf("\n** %s **\n\n",tipo);
        printf("1. Adicionar\n");
        printf("2. Listar\n");
        printf("3. Pesquisar\n");
        printf("0. Voltar\n\n");
        printf("Opcao: ");
        scanf("%d",&opt);
    }while(opt<0||opt>3);
    return opt;
}

void adicionar_cliente(Cliente *novo,int id)
{
    printf("\n** Adicionar Cliente **\n\n");
    novo->id = id;
    printf("Nome: ");
    scanf("%s",novo->nome);
    printf("Telemovel: ");
    scanf("%s",novo->telemovel);
}

void listar_cliente(Cliente cliente)
{
    printf("\nID: %d\n",cliente.id);
    printf("Nome: %s\n",cliente.nome);
    printf("Telemovel: %s\n",cliente.telemovel);
}
