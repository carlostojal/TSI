//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Estruturas
typedef struct Datas {
    int dia;
    int mes;
    int ano;
}Data;
typedef struct PCs {
    int id;
    char marca[30];
    char modelo[50];
    float preco;
    int quantidade;
    struct PCs *prox;
}PC;
typedef struct Vendas_Compras {
    int id_produto;
    float preco;
    int quantidade;
    Data data;
    struct Vendas_Compras *prox;
}venda_compra;

//Protótipos
int menu();
void vender(int id,PC *stock,venda_compra *vendas);
void mostrar_pc(PC *pc);
void comprar(int id,PC *stock,venda_compra *compras);
void mostrar_venda_compra(venda_compra *venda,char *opcao);

//Main
int main()
{
    PC *stock = (PC*)malloc(sizeof(PC));
    venda_compra *vendas = (venda_compra*)malloc(sizeof(venda_compra));
    venda_compra *compras = (venda_compra*)malloc(sizeof(venda_compra));
    PC *p;
    venda_compra *q;
    stock->prox = NULL;
    vendas->prox = NULL;
    compras->prox = NULL;
    int id=1;
    int id_pesquisado;
    int flag=0;

    int opt;
    do{
        opt = menu();
        switch(opt)
        {
            case 1:
                for(p=stock->prox;p!=stock;p=p->prox)
                {
                    if(p->quantidade>0)
                        mostrar_pc(p);
                }
                printf("ID do PC a vender: ");
                scanf("%d",&id_pesquisado);
                vender(id_pesquisado,stock,vendas);
                break;
            case 2:
                for(p=stock->prox;p!=stock;p=p->prox)
                {
                    if(p->quantidade>0)
                        mostrar_pc(p);
                }
                break;
            case 3:
                printf("\nID a pesquisar: ");
                scanf("%d",&id_pesquisado);
                for(p=stock->prox;p!=stock;p=p->prox)
                {
                    if(p->id==id_pesquisado)
                    {
                        flag=1;
                        mostrar_pc(p);
                        break;
                    }
                }
                break;
            case 4:
                comprar(id,stock,compras);
                id++;
                break;
            case 5:
                for(q=vendas->prox;q!=vendas;q=q->prox)
                    mostrar_venda_compra(q,"Venda");
                break;
            case 6:
                for(q=compras->prox;q!=compras;q=q->prox)
                    mostrar_venda_compra(q,"Compra");
                break;
        }
    }while(opt);
    return 0;
}

//Funções
int menu()
{
    int opt;
    printf("\n** Loja de Informatica **\n\n");
    printf("1. Vender\n");
    printf("2. Listar stock\n");
    printf("3. Pesquisar no stock\n");
    printf("4. Comprar\n");
    printf("5. Consultar vendas\n");
    printf("6. Consultar compras\n");
    printf("0. Sair\n\n");
    printf("Opcao: ");
    do{
        scanf("%d",&opt);
    }while(opt<0||opt>6);
    return opt;
}

void vender(int id,PC *stock,venda_compra *vendas)
{
    PC *p = (PC*)malloc(sizeof(PC));
    PC *produto;
    venda_compra *q;
    venda_compra *venda = (venda_compra*)malloc(sizeof(venda_compra));
    venda->prox = vendas;
    int flag=0;
    int quantidade;

    printf("\nQuantidade: ");
    scanf("%d",&quantidade);
    printf("Data (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&venda->data.dia,&venda->data.mes,&venda->data.ano);

    for(p=stock->prox;p!=stock;p=p->prox)
    {
        if(p->id==id)
        {
            if(p->quantidade-quantidade>=0)
            {
                flag=1;
                p->quantidade-=quantidade;
                produto = p;
            }
            else
                printf("\nNao foi possivel vender tantas unidades do produto. Apenas %d unidades estao disponiveis.\n",p->quantidade);
            break;
        }
    }
    if(flag)
    {
        stock = p;

        venda->id_produto = id;
        venda->preco = produto->preco;
        venda->quantidade = quantidade;

        if(vendas->prox==NULL) vendas->prox = venda;
        else
        {
            for(q=vendas->prox;q->prox!=vendas;q=q->prox){}
            q->prox = venda;
            vendas = q;
        }
    }
}

void comprar(int id,PC *stock,venda_compra *compras)
{
    PC *novo = (PC*)malloc(sizeof(PC));
    novo->prox = stock;
    PC *p;
    venda_compra *compra = (venda_compra*)malloc(sizeof(venda_compra));
    compra->prox = compras;
    venda_compra *q;

    novo->id = id;
    printf("\n** Comprar **\n\n");
    printf("Marca: ");
    scanf("%s",novo->marca);
    printf("Modelo: ");
    scanf("%s",novo->modelo);
    printf("Preco: ");
    scanf("%f",&novo->preco);
    printf("Quantidade: ");
    scanf("%d",&novo->quantidade);
    printf("Data (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&compra->data.dia,&compra->data.mes,&compra->data.ano);

    compra->id_produto = id;
    compra->preco = novo->preco;
    compra->quantidade = novo->quantidade;

    if(stock->prox==NULL) stock->prox = novo;
    else
    {
        for(p=stock->prox;p->prox!=stock;p=p->prox){}
        p->prox = novo;
        stock = p;
    }

    if(compras->prox==NULL) compras->prox = compra;
    else
    {
        for(q=compras->prox;q->prox!=compras;q=q->prox){}
        q->prox = compra;
        compras = q;
    }
}

void mostrar_pc(PC *pc)
{
    printf("\n** PC %d **\n\n",pc->id);
    printf("Marca: %s\n",pc->marca);
    printf("Modelo: %s\n",pc->modelo);
    printf("Preco: %.2f\n",pc->preco);
    printf("Quantidade: %d\n",pc->quantidade);
}

void mostrar_venda_compra(venda_compra *venda,char *opcao)
{
    printf("\n** %s de %d/%d/%d **\n\n",opcao,venda->data.dia,venda->data.mes,venda->data.ano);
    printf("ID do produto: %d\n",venda->id_produto);
    printf("Quantidade: %d\n",venda->quantidade);
}
