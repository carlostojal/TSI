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

typedef struct Apolices {
    int id;
    int id_cliente;
    char veiculo[20];
    float valor;
}Apolice;

//Protótipos
int menu();
int submenu(char *tipo);
void adicionar_cliente(Cliente *novo,int id);
void listar_cliente(Cliente cliente);
void adicionar_apolice(Apolice *novo,int id);
void listar_apolice(Apolice apolice);

//Main
int main()
{
    int i;
    int opt,subopt;
    int tam_clientes=0,tam_apolices=0;
    Cliente pesquisa;
    Apolice pesquisa_apolice;
    Cliente clientes[1000];
    Apolice apolices[1000];
    FILE *fp = fopen("clientes.csv","r");
    while(!feof(fp))
    {
        fscanf(fp,"%d %s %s",&clientes[tam_clientes].id,clientes[tam_clientes].nome,clientes[tam_clientes].telemovel);
        tam_clientes++;
    }
    fclose(fp);
    fp = fopen("apolices.csv","r");
    while(!feof(fp))
    {
        fscanf(fp,"%d %d %s %f",&apolices[tam_apolices].id,&apolices[tam_apolices].id_cliente,apolices[tam_apolices].veiculo,&apolices[tam_apolices].valor);
        tam_apolices++;
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
                        adicionar_cliente(&clientes[tam_clientes-1],tam_clientes);
                        tam_clientes++;
                        break;
                    case 2:
                        printf("\n** Listar Clientes **\n");
                        for(i=0;i<tam_clientes-1;i++)
                            listar_cliente(clientes[i]);
                        break;
                    case 3:
                        printf("\n** Pesquisar Clientes **\n\n");
                        printf("Pesquisa: ");
                        scanf("%s",pesquisa.nome);
                        strcpy(pesquisa.telemovel,pesquisa.nome);
                        pesquisa.id = atoi(pesquisa.nome);
                        for(i=0;i<tam_clientes-1;i++)
                        {
                            if(strcmp(clientes[i].nome,pesquisa.nome)==0||strcmp(clientes[i].telemovel,pesquisa.telemovel)==0||clientes[i].id==pesquisa.id)
                                listar_cliente(clientes[i]);
                        }
                }
                break;
            case 2:
                subopt = submenu("Apolices");
                switch(subopt)
                {
                    case 1:
                        adicionar_apolice(&apolices[tam_apolices-1],tam_apolices);
                        tam_apolices++;
                        break;
                    case 2:
                        printf("\n** Listar Apolices **\n\n");
                        for(i=0;i<tam_apolices-1;i++)
                            listar_apolice(apolices[i]);
                        break;
                    case 3:
                        printf("\n** Pesquisar Apolices **\n\n");
                        printf("Pesquisa: ");
                        scanf("%s",pesquisa_apolice.veiculo);
                        pesquisa_apolice.id = atoi(pesquisa_apolice.veiculo);
                        pesquisa_apolice.id_cliente = atoi(pesquisa_apolice.veiculo);
                        for(i=0;i<tam_apolices-1;i++)
                        {
                            if(strcmp(apolices[i].veiculo,pesquisa_apolice.veiculo)==0||apolices[i].id==pesquisa_apolice.id||apolices[i].id_cliente==pesquisa_apolice.id_cliente)
                                listar_apolice(apolices[i]);
                        }
                }
                break;
        }
    }while(opt);
    fp = fopen("clientes.csv","w");
    fclose(fp);
    fp = fopen("clientes.csv","a");
    for(i=0;i<tam_clientes-1;i++)
        fprintf(fp,"%d %s %s\n",clientes[i].id,clientes[i].nome,clientes[i].telemovel);
    fclose(fp);
    fp = fopen("apolices.csv","w");
    fclose(fp);
    fp = fopen("apolices.csv","a");
    for(i=0;i<tam_apolices-1;i++)
        fprintf(fp,"%d %d %s %.2f\n",apolices[i].id,apolices[i].id_cliente,apolices[i].veiculo,apolices[i].valor);
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

void adicionar_apolice(Apolice *novo,int id)
{
    printf("\n** Adicionar Apolice **\n\n");
    novo->id = id;
    printf("ID do cliente: ");
    scanf("%d",&novo->id_cliente);
    printf("Veiculo: ");
    scanf("%s",novo->veiculo);
    printf("Valor: ");
    scanf("%f",&novo->valor);
}

void listar_apolice(Apolice apolice)
{
    printf("\nID: %d\n",apolice.id);
    printf("ID do Cliente: %d\n",apolice.id_cliente);
    printf("Veiculo: %s\n",apolice.veiculo);
    printf("Valor: %.2f€\n",apolice.valor);
}
