//Carlos Tojal, nº5, 1ºTSI

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

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
    Cliente clientes[1000];
    FILE *fp = fopen("clientes.csv","r");
    while(!feof(fp))
    {
        fscanf(fp,"%d %s",&clientes[tam].id,clientes[tam].nome);
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
                        adicionar_cliente(&clientes[tam],tam+1);
                        break;
                    case 2:
                        for(i=0;i<tam;i++)
                            listar_cliente(clientes[i]);
                        break;
                }
                break;
        }
    }while(opt);
    fflush(fp);
    fp = fopen("clientes.csv","a");
    for(i=0;i<tam;i++)
        fprintf(fp,"%d %s\n",clientes[i].id,clientes[i].nome);
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
