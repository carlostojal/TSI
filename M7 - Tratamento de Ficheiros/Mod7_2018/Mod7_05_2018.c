//Carlos Tojal, nº5, 1ºTSI

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estruturas de Dados
typedef struct Tlm {
    int Numero;
    char Marca[20];
    char Modelo[20];
    char SO[20];
    char Tamanho[20];
    int Bateria;
}Tlm;

//Protótipos
int menu();
void new_tlm(Tlm *novo);
void show_tlm(Tlm tlm);
void del_tlm(Tlm stock[1000],Tlm tlm,int tam);


//Função main
int main()
{
    Tlm stock[1000]; //Vetor de stock
    Tlm pesquisa; //Elemento utilizado nas pesquisas
    int opt; //opção do menu
    int x=0; //guarda o número total de registos
    int i; //variável para controlar os ciclos de repetição

    FILE *fp = fopen("stock.csv","r");
    while(!feof(fp)&&x<1000) //guarda os dados do ficheiro no vetor, além de assim obter o número total de resultados
    {
        fscanf(fp,"%d %s %s %s %s %d",&stock[x].Numero,stock[x].Marca,stock[x].Modelo,stock[x].SO,stock[x].Tamanho,&stock[x].Bateria);
        x++;
    }
    fclose(fp);

    do{
        opt=menu();
        switch(opt)
        {
            case 1:
                new_tlm(&stock[x-1]);
                x++; //adiciona mais um ao número total de telemóveis
                break;
            case 2:
                printf("\n** Listar Telemoveis por Marca **\n\n");
                printf("Marca: ");
                scanf("%s",pesquisa.Marca);
                for(i=0;i<x;i++) //percorre toda a lista
                {
                    if(strcmp(stock[i].Marca,pesquisa.Marca)==0) //se a marca for igual à procurada...
                        show_tlm(stock[i]); //mostra o telemóvel
                }
                break;
            case 3:
                printf("\n** Eliminar Telemovel **\n\n");
                printf("Numero: ");
                scanf("%d",&pesquisa.Numero);
                del_tlm(stock,pesquisa,x);
                x--;
                break;
            case 4:
                printf("\n** Listar Telemoveis com Bateria Superior a... **\n\n");
                printf("Bateria: ");
                scanf("%d",&pesquisa.Bateria);
                for(i=0;i<x;i++) //percorre toda a lista
                {
                    if(stock[i].Bateria>pesquisa.Bateria) //se a bateria for superior à procurada...
                        show_tlm(stock[i]); //mostra o telemóvel
                }
                break;
        }
    }while(opt);
    fp = fopen("stock.csv","w");
    fprintf(fp,"");
    fclose(fp);
    fp = fopen("stock.csv","a");
    for(i=0;i<x;i++) //rescreve o ficheiro com os novos dados
        fprintf(fp,"%d %s %s %s %s %d\n",stock[i].Numero,stock[i].Marca,stock[i].Modelo,stock[i].SO,stock[i].Tamanho,stock[i].Bateria);
    fclose(fp);
    return 0;
}

//Funções
//Menu (retorna a oppção selecionada)
int menu()
{
    int opt;
    do{
        printf("\n** Telemoveis **\n\n");
        printf("1. Adicionar Telemovel\n");
        printf("2. Listar Telemoveis por Marca\n");
        printf("3. Eliminar Telemovel\n");
        printf("4. Listar Telemoveis com Bateria Superior a...\n");
        printf("0. Terminar o programa\n\n");
        printf("Opcao: ");
        scanf("%d",&opt);
    }while(opt<0||opt>4);
    return opt;
}

//Lê os dados para um novo registo
void new_tlm(Tlm *novo)
{
    printf("\n** Adicionar Telemovel **\n\n");
    printf("Numero: ");
    scanf("%d",&novo->Numero);
    printf("Marca: ");
    scanf("%s",novo->Marca);
    printf("Modelo: ");
    scanf("%s",novo->Modelo);
    printf("SO: ");
    scanf("%s",novo->SO);
    printf("Tamanho: ");
    scanf("%s",novo->Tamanho);
    printf("Bateria: ");
    scanf("%d",&novo->Bateria);
}

//Mostra os dados de um telemóvel recebido
void show_tlm(Tlm tlm)
{
    printf("\nNumero: %d\n",tlm.Numero);
    printf("Marca: %s\n",tlm.Marca);
    printf("Modelo: %s\n",tlm.Modelo);
    printf("SO: %s\n",tlm.SO);
    printf("Dimensoes: %s\n",tlm.Tamanho);
    printf("Bateria: %d mAh\n",tlm.Bateria);
}

//Elimina um registo
void del_tlm(Tlm stock[1000],Tlm tlm,int tam)
{
    int i,j;
    for(i=0;i<tam;i++)
    {
        if(stock[i].Numero==tlm.Numero)
        {
            for(j=i;j<tam;j++)
                stock[j]=stock[j+1];
            break;
        }
    }
}
