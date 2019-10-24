//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Estruturas
//Datas
typedef struct Datas {
    int dia;
    int mes;
    int ano;
}Data;

//Cartão de Cidadão
typedef struct cc {
    char nome[15];
    char apelidos[30];
    char sexo;
    float altura;
    char nacionalidade[3];
    Data data_nascimento;
    char n_documento[12];
    Data validade;
    char pais[2][60];
    int nif[9];
    int ss[11];
    int utente[9];
    struct cc *prox;
}cc;

//Protótipos
int menu();
void ler_cc(cc *lista);
void listar_cc(cc *CC);

//Main
int main()
{
    cc *lista = (cc*)malloc(sizeof(cc));
    cc *p;
    int opt=0;
    do{
        opt = menu();
        switch(opt)
        {
            case 1:
                ler_cc(lista);
                break;
            case 2:
                for(p=lista->prox;p!=NULL;p=p->prox)
                    listar_cc(p);
                break;
        }
    }while(opt);
}

//Funções
int menu()
{
    int opt;
    printf("\n** Registo Civil **\n\n");
    printf("1. Ler Cartao\n");
    printf("2. Listar Cartoes\n");
    printf("0. Sair\n\n");
    printf("Opcao: ");
    do{
        scanf("%d",&opt);
    }while(opt<0||opt>2);
    return opt;
}
void ler_cc(cc *lista)
{
    cc * p = (cc*)malloc(sizeof(cc));
    cc *novo = (cc*)malloc(sizeof(cc));
    printf("\n** Ler Cartao de Cidadao **\n\n");
    printf("Nome: ");
    scanf("%s",novo->nome);
    printf("Apelido(s): ");
    scanf("%s",novo->apelidos);
    /*
    printf("Sexo: ");
    scanf("%s",novo->sexo);*/
    printf("Altura: ");
    scanf("%f",&novo->altura);
    printf("Nacionalidade: ");
    scanf("%s",novo->nacionalidade);
    printf("Data de Nascimento (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&novo->data_nascimento.dia,&novo->data_nascimento.mes,&novo->data_nascimento.ano);
    printf("No. Documento: ");
    scanf("%s",novo->n_documento);
    printf("Validade: ");
    scanf("%d/%d/%d",&novo->validade.dia,&novo->validade.mes,&novo->validade.ano);
    printf("Pai: ");
    scanf("%s",novo->pais[0]);
    printf("Mae: ");
    scanf("%s",novo->pais[1]);
    printf("NIF: "),
    scanf("%s",novo->nif);
    printf("Seguranca Social: ");
    scanf("%s",novo->ss);
    printf("N Utente: ");
    scanf("%s",novo->utente);

    if(lista->prox==NULL) lista->prox = novo;
    else
    {
        p=lista->prox;
        p->prox = novo;
        for(p=lista->prox;p!=NULL;p=p->prox)
        {

        }
        p = novo;
        lista = p;
    }
    printf("\nterminou\n");
}

void listar_cc(cc *CC)
{
    printf("\n** CC %s **\n\n",CC->n_documento);
    printf("Nome: %s\n",CC->nome);
    printf("Apelidos: %s\n",CC->apelidos);
    printf("Sexo: %c\n",CC->sexo);
    printf("Altura: %.2f\n",CC->altura);
    printf("Nacionalidade: %s\n",CC->nacionalidade);
    printf("Data de Nascimento: %d/%d/%d\n",CC->data_nascimento.dia,CC->data_nascimento.mes,CC->data_nascimento.ano);
    printf("No. Documento: %s\n",CC->n_documento);
    printf("Validade: %d/%d/%d\n",CC->data_nascimento.dia,CC->data_nascimento.mes,CC->data_nascimento.ano);
    printf("Pais: %s * %s\n",CC->pais[0],CC->pais[1]);
    printf("NIF: %s\n",CC->nif);
    printf("Seguranca social: %s\n",CC->ss);
    printf("No. Utente: %s\n",CC->utente);
}
