#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <E:\PSI\1ºTSI\Socios_Est.h>

#define MAX 10

int menu();
void inserir_socio();
void inserir_quota();
int menu_listagens();
void listar_socios();

Socio socios[MAX];
Quota quotas[MAX];
int ts=0, tq=0;

void main()
{
    int opMenu;
    int subOp;
    do{
        opMenu = menu();
        switch(opMenu)
        {
            case 1:
                socios[ts].idSocio = ts+1;
                inserir_socio(&socios[ts]);
                ts++;
                break;
            case 2:
                inserir_quota();
                break;
            case 3:
                do{
                    subOp = menu_listagens();
                    switch(subOp)
                    {
                        case 1:
                            listar_socios();
                            break;
                    }
                }while(subOp!=0);
                break;
        }
    }while(opMenu!=0);
}

int menu()
{
    int opt;
    do{
        system("cls");
        printf("\n\t** SOCIOS **\n\n");
        printf("1. Inserir Socios\n");
        printf("2. Inserir Quota\n");
        printf("3. Menu Listagens\n");
        printf("0. Sair\n\n");
        printf("Selecione uma opcao: ");
        scanf("%d",&opt);
    }while(opt<0 || opt>3);
    return opt;
}

int menu_listagens()
{
    int opt;
    do{
        system("cls");
        printf("\n\t** LISTAGENS **\n\n");
        printf("1. Socios\n");
        printf("2. Quota por socio\n");
        printf("3. Total de Quotas\n");
        printf("0. Sair\n\n");
        printf("Selecione uma opcao: ");
        scanf("%d",&opt);
    }while(opt<0||opt>3);
}

void inserir_socio(Socio *socio)
{
    system("cls");
    printf("\n\t** INSERIR SOCIO **\n\n");
    printf("ID: %d\n",(*socio).idSocio);
    printf("Nome: ");
    gets((*socio).nome);
    printf("Morada: ");
    gets((*socio).morada);
    printf("NIF: ");
    gets((*socio).NIF);
    printf("Telefone:");
    gets((*socio).telefone);
    printf("Data de Nascimento (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&(*socio).dtnascSocio.dia,&(*socio).dtnascSocio.mes,&(*socio).dtnascSocio.ano);
    printf("\nSocio salvo com sucesso.");
    getch();
}

void listar_socios(Socio *socios)
{
    int i;
    system("cls");
    printf("\n\t** LISTAR SOCIOS **\n\n");
    for(i=0;i<ts;i++)
    {
        printf("ID: %d\n",socios[i].idSocio);
        printf("Nome: %s\n",socios[i].nome);
        printf("Morada: %s\n",socios[i].morada);
        printf("NIF: %s\n",socios[i].NIF);
        printf("Telefone: %s\n",socios[i].telefone);
        printf("Data de Nascimento: %d/%d/%d",socios[i].dtnascSocio.dia,socios[i].dtnascSocio.mes,socios[i].dtnascSocio.ano);
        printf("\n\n");
    }
    getch();
}

void inserir_quota(Socio socio)
{
    int idSocio;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("\n\t** INSERIR QUOTA **\n\n");
    printf("Insira o ID do socio: ");
    scanf("%d",&(*socio).idSocio);
    getch();
}
