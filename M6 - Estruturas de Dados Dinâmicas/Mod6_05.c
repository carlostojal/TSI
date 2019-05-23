//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estruturas
//Estrutura telenovela (simples)
typedef struct telenovela {
    int num;
    char titulo[50];
    char autor[25];
    int ano;
    char pais[20];
    struct telenovela *prox;
}telenovela;

//Funções
void ler_obra(int id,telenovela *lista);
void listar_obra(telenovela *ficha);
void elimina_obra(int id,telenovela *lista);

//Main
int main()
{
    int id=1;
    int menu_opt;
    int num;
    telenovela *p;
    telenovela *lista;
    lista = (telenovela*)malloc(sizeof(telenovela));
    if(!lista)
        printf("\nMemoria insuficiente.\n");
    lista->prox = NULL;
    do{
        printf("\n** Telenovelas **\n\n");
        printf("1. Ler obra\n");
        printf("2. Listar obras\n");
        printf("3. Eliminar obra\n");
        printf("0. Sair\n\n");
        printf("Opcao: ");
        do{
            scanf("%d",&menu_opt);
        }while(menu_opt<0||menu_opt>3);
        switch(menu_opt)
        {
            case 1:
                ler_obra(id,lista);
                id++;
                break;
            case 2:
                if(lista->prox == NULL) printf("\nLISTA VAZIA\n\n");
                else
                {
                    for(p=lista->prox;p!=NULL;p=p->prox)
                    {
                        listar_obra(p);
                    }
                }
                break;
            case 3:
                printf("\n** Remover Obra **\n\n");
                if(lista->prox == NULL) printf("\nLISTA VAZIA\n\n");
                else
                {
                    for(p=lista->prox;p!=NULL;p=p->prox)
                    {
                        listar_obra(p);
                    }
                }
                printf("\nInsira o numero a remover: ");
                scanf("%d",&num);
                elimina_obra(num,lista);
                break;
        }
    }while(menu_opt);
    return 0;
}

void ler_obra(int id,telenovela *lista) //Recebe um novo registo, aloca espaço na memória, e associa-o ao próximo elemento do último inserido
{
    telenovela *novo;
    telenovela *atual;
    telenovela *anterior;
    atual = lista;
    anterior = NULL;
    novo = malloc(sizeof(telenovela));
    if(!novo)
        printf("\nMemoria insuficiente.\n");
    novo->prox = NULL;

    //Inserção sequêncial (à cauda)
    /*
    if(lista->prox==NULL) lista->prox = novo;
    else
    {
        p = lista;
        while(p->prox!=NULL) p=p->prox;
        p->prox = novo;
        lista = p;
    }*/

    //Inserção ordenada (a funcionar) (versão do teste 2018)
    if(atual==NULL) //se a lista estiver vazia
    {
        novo->prox = NULL; //o próximo do elemento adicionado é o fim da lista (NULL)
        lista = novo; //atualiza a lista
    }
    else
    {
        while(atual!=NULL&&strcmp(atual->titulo,novo->titulo)<=0) //enquanto a lista não chegar ao fim e o título atual não for "maior" que o novo
        {
            anterior = atual;
            atual = atual->prox;
        }
        novo->prox = atual;
        if(anterior==NULL) lista = novo;
        else anterior->prox = novo;
    }

    //Leitura dos dados
    novo->num = id;

    printf("\n** Ler Obra **\n\n");
    printf("Titulo: ");
    fflush(stdin);
    //fgets(novo->titulo,255,stdin);
    scanf("%s",novo->titulo);
    printf("Autor: ");
    fflush(stdin);
    //fgets(novo->autor,255,stdin);
    scanf("%s",novo->autor);
    printf("Ano de Edicao: ");
    scanf("%d",&novo->ano);
    printf("Pais de origem: ");
    fflush(stdin);
    //fgets(novo->pais,255,stdin);
    scanf("%s",novo->pais);

    telenovela *temp;
    int flag=0;

    //Inserção ordenada (a funcionar incorretamente)
    /*
    if(lista->prox==NULL) //se for o primeiro elemento
        lista->prox = novo;
    else
    {
        p = lista;
        for(p=p->prox;p!=NULL;p=p->prox)
        {
            if(strcmp(p->titulo,novo->titulo)>0) //se o título atual é "maior" que o novo
            {
                flag = 1; //estava desordenado
                p->prox = p; //o sucessor do elemento passa a ser o que estava como atual
                p = novo; //o elemento atual passa a ser o novo
                lista = p; //atualiza a lista
            }
        }
        if(!flag) //se não detetou que estava desordenado
        {
            p = lista;
            while(p->prox!=NULL) p=p->prox;
            p->prox = novo;
            lista = p;
        }
    }*/
}

void listar_obra(telenovela *ficha) //Lista uma obra passada por argumento
{
    printf("\n** Obra %d **\n\n",ficha->num);
    printf("Titulo: %s\n",ficha->titulo);
    printf("Autor: %s\n",ficha->autor);
    printf("Ano de Edicao: %d\n",ficha->ano);
    printf("Pais de Origem: %s\n",ficha->pais);
}

void elimina_obra(int id,telenovela *lista) //Elimina o elemento com o id passado como argumento (a funcionar incorretamente)
{
    /*
    telenovela *p;
    int flag=0;
    for(p=lista->prox;p!=NULL;p=p->prox)
    {
        if(p->num==id) //encontrou o id na lista
        {
            flag=1;
            p=p->prox; //o elemento com o id pedido passa a ser o que estava como seu sucessor
            lista = p; //atualiza a lista
        }
    }
    if(!flag)
        printf("\nO numero pedido nao foi encontrado na lista\n");
    */

    telenovela *atual;
    telenovela *seguinte;
    int flag=0;
    atual = lista;
    seguinte = NULL;
    while(atual!=NULL&&atual->num!=id)
    {
        if(atual->num==id)
        {
            flag = 1;
            break;
        }
        atual = atual->prox;
        seguinte = atual;
    }
    if(!flag)
        printf("\nTelenovela não encontrada.\n");
    lista->prox = seguinte;
}
