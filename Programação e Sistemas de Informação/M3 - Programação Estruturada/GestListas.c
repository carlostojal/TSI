#include <stdio.h>
#include <limits.h>

int menu();
int lernumero();
void listavet();
void OrdenaAsc();
void OrdenaDesc();

void main()
{
    int op, tam, num;
    int i=tam=0;
    int j, x;
    int vet[50];
    do{
        system("cls");
        op=menu();
        switch(op)
        {
            case 1: {
                num = lernumero(0,999);
                vet[tam]=num;
                tam++;
                listavet(vet, tam);
                break;
            }
            case 2: {
                num = lernumero(0, 999);
                i=tam;
                if(tam==0) vet[tam]=num;
                else while(i>0)
                {
                    vet[i]=vet[i-1];
                    i--;
                }
                vet[0]=num;
                tam++;
                listavet(vet, tam);
                break;
            }
            case 3:
            {
                num = lernumero(0, 999);
                for(i=0;i<tam;i++)
                    if(num<vet[i]) break;
                for(x=tam;x>=i;x--)
                    vet[x]=vet[x-1];
                vet[i]=num;
                tam++;
                listavet(vet, tam);
                break;
            }
            case 4:
            {
                vet[tam-1]="";
                tam--;
                listavet(vet, tam);
                break;
            }
            case 5:
            {
                for(x=0;x<tam-2;x++)
                    vet[x]=vet[x+1];
                vet[tam-1]="";
                tam--;
                listavet(vet, tam);
                break;
            }
            case 6:
            {
                printf("\nElemento a remover: ");
                num=lernumero(0,999);

                for(i=0;i<tam;i++)
                {
                    if(num==vet[i])
                        break;
                }
                for(;vet[i]!='\0';i++)
                    vet[i]=vet[i+1];

                tam--;

                listavet(vet,tam);
            }
            case 7:
                OrdenaAsc(vet, tam);
                listavet(vet, tam);
                break;
            case 8:
                OrdenaDesc(vet, tam);
                listavet(vet, tam);
                break;
        }
    }while(op|=0);
}

int menu()
{
    int op;
    do{
        system("cls");
        printf("\n\t1. Inserir no final");
        printf("\n\t2. Inserir no inicio");
        printf("\n\t3. Inserir ordenadamente");
        printf("\n\t4. Remover no final");
        printf("\n\t5. Remover no inicio");
        printf("\n\t6. Remover ordenadamente");
        printf("\n\t7. Ordenacao ascendente");
        printf("\n\t8. Ordenacao descendente");
        printf("\n\t0. Terminar");
        printf("\n\nOP: ");
        scanf("%d",&op);
    }while(op<0 || op>8);
    return op;
}

int lernumero(int min, int max)
{
    int num;
    do{
        printf("Introduza um numero entre %d e %d: ",min, max);
        scanf("%d",&num);
    }while(num<min || num>max);
    return num;
}

void listavet(int vet[], int tam)
{
    int i;
    if(tam==0) printf("\n **VETOR VAZIO**");
    else for(i=0;i<tam;i++)
    {
        printf("[%d]=%d\t",i,vet[i]);
    }
    getch();
}

void OrdenaAsc(int array[], int n)
{
    int c,d,position,swap;

    for(c=0;c<(n-1);c++)
    {
        position=c;
        for(d=c+1:d<n;d++)
        {
            if(array[position]>array[d])
            {
                position=d;
            }
        }
    }
    if(position!=c)
    {
        swap=array[c];
        array[c]=array[position];
        array[position]=swap;
    }
}

void OrdenaDesc(int array[], int n)
{
    int c,d,position,swap;

    for(c=0;c<(n-1);c++)
    {
        position=c;
        for(d=c+1:d<n;d++)
        {
            if(array[position]>array[d])
            {
                position=d;
            }
        }
    }
    if(position!=c)
    {
        swap=array[c];
        array[c]=array[position];
        array[position]=swap;
    }
}
