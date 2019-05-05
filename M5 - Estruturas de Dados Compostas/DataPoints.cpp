//DATAPOINTS
//Calcula quadrado e raíz quadrada de números introduzidos pelo utilizador em estruturas de dados


//BIBLIOTECAS
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <conio.h>


//ESTRUTURAS DE DADOS
typedef struct DPs {
    int num;
    int quadrado;
    float raiz;
}DP;


//PROTÓTIPOS
int menu(void);
int inserir(DP *r);
void listar(DP *r,int count);
void remover(DP *r,int *count,int flag);
void ordenar(DP *r,int count);

int main() //manipula opções do menu
{
    DP vet[20];
    int count=0,i,x,op=0,resp=0,flag=0;
    do
    {
        op=menu();
        switch(op)
        {
            case 1:
            {
                resp=inserir(&vet[count]);
                count++;
                break;
            }
            case 2:
            {
                listar(vet,count);
                break;
            }
            case 3:
            {
                remover(vet,&count,flag);
                break;
            }
            case 4:
            {
                ordenar(vet,count);
                break;
            }
        }
    }while(op!=0);
    return 0;
}

int menu() //lê opção do menu e retorna-a
{
    system("cls");
    int op;
    printf("\n\t** DataPoints\n\n");
    printf("1. Inserir\n");
    printf("2. Listar\n");
    printf("3. Remover\n");
    printf("4. Ordenar\n");
    printf("0. Sair\n\n");
    printf("Selecione uma opcao: ");
    scanf("%d",&op);
    return op;
}

int inserir(DP *r) //lê valores e calcula os respetivos quadrados e raízes
{
    system("cls");
    printf("\n\nIntroduza um numero: ");
    scanf("%d",&(*r).num);
    (*r).quadrado = (*r).num * (*r).num;
    (*r).raiz = sqrt((*r).num);
}

void listar(DP *r,int count) //recebe um vetor de DPs e mostra-o
{
    system("cls");
    int i;
    printf("\nIndice\tNum\tQuadrado\tRaiz\n");
    for(i=0;i<count;i++)
        printf("%d\t%d\t%d\t\t%.2f\n",i,r[i].num,r[i].quadrado,r[i].raiz);
    getch();
}

void remover(DP *r,int *count,int flag) //recebe o vetor de DPs, lê número a remover do vetor e remove-o
{
    int num;
    int i,j;
    listar(r,(*count));
    printf("\nNumero a remover: ");
    scanf("%d",&num);
    for(i=0;i<(*count);i++)
    {
        if(r[i].num == num)
        {
            printf("\nEncontrado na %da posicao.",i+1);
            flag=1;
            for(j=i;j<(*count)-1;j++)
            {
                r[i].num = r[i+1].num;
                r[i].quadrado = r[i+1].quadrado;
                r[i].raiz = r[i+1].raiz;
            }
            (*count)--;
        }
        else
            printf("\nNao foi encontrado.");

        if(flag==1)
            break;
    }
    listar(r,(*count));
    getch();
}

void ordenar(DP *r,int count) //recebe o vetor de DPs e ordena-o crescentemente pelo número
{
    int i,j;
    int tempNum,tempQuad;
    float tempRaiz;

    for(i=0;i<count-1;i++)
    {
       for(j=0;j<count-i-1;j++)
       {
           if(r[j].num > r[j+1].num)
           {
                tempNum = r[j].num;
                r[j].num = r[j+1].num;
                r[j+1].num = tempNum;
                tempQuad = r[j].quadrado;
                r[j].quadrado = r[j+1].quadrado;
                r[j+1].quadrado = tempQuad;
                tempRaiz = r[j].raiz;
                r[j].raiz = r[j+1].raiz;
                r[j+1].raiz = tempRaiz;
           }
       }
    }
    listar(r,count);
}
