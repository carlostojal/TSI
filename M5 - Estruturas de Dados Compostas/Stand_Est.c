#include <stdio.h>
#include <windows.h>

typedef struct Datas {
        int dia;
        int mes;
        int ano;
    }Data;

    typedef struct Viaturas {
        int idViatura;
        char marca[30];
        char modelo[30];
        char combustivel[30];
        int numPortas;
        int cilindrada;
    }Viatura;

    typedef struct Clientes {
        int idCliente;
        char nome[30];
        char morada[30];
        char telefone[30];
    }Cliente;

    typedef struct Vendas {
        int idVenda;
        int idViatura;
        int idCliente;
        Data dataVenda;
        float valor;
    }Venda;

int menu();
int submenu(char *s);
void listar_viatura(Viatura v);
void ler_cliente(Cliente cliente);
void listar_viatura(Viatura v);

void main()
{
    Viatura viatura;
    int opMenu, opSubMenu;
    do{
        opMenu = menu();
        switch(opMenu)
        {
            case 1:
                do{
                    opSubMenu = submenu("VIATURA");
                    if(opSubMenu==1)
                    {
                        opSubMenu = submenu("INSERIR VIATURA");
                    }
                }while(opSubMenu!=0);
        }
    }while(opMenu!=0);
}

int menu()
{
    int opt;

    do{
        fflush(stdin);
        system("cls");
        printf("\n\t** STAND **\n\n");
        printf("1. Viaturas\n");
        printf("2. Clientes\n");
        printf("3. Vendas\n");
        printf("0. Sair\n\n");
        printf("Selecione uma opcao: ");
        scanf("%d",&opt);
    }while(opt<1||opt>3);
    return opt;
}

int submenu(char *s)
{
    int opt;

    do{
        fflush(stdin);
        system("cls");
        printf("\n\t** %s **\n\n",s);
        printf("1. Inserir\n");
        printf("2. Listar\n");
        printf("3. Des/Ativar\n");
        printf("0. Voltar\n\n");
        printf("Selecione uma opcao: ");
        scanf("%d",&opt);
    }while(opt<1||opt>3);
    return opt;
}

void listar_viatura(Viatura v)
{
    printf("\n\t** LISTAR VIATURA ***\n\n");
    printf("ID: %d\n",v.idViatura);
    printf("Marca: %s\n",v.marca);
    printf("Modelo: %s\n",v.modelo);
    printf("Combustivel: %s\n",v.combustivel);
    printf("Cilindrada: %d",v.cilindrada);
    getch();
}

void ler_cliente(Cliente *cliente)
{
    printf("\n\t ** A REGISTAR CLIENTE **\n\n");
    printf("ID: %d\n",cliente.idCliente);
    printf("Nome: ");
    scanf("%s",cliente.nome);
    printf("Morada: ");
    scanf("%s",cliente.morada);
    printf("Telefone: ");
    scanf("%s",cliente.morada);
    printf("\n\nCliente registado com sucesso!");
    getch();
}
