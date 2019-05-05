#include <stdio.h>

void bubble_sort(int n, int* v)
{
    int i, j, k;
    for(i=n-1;i>=1;i--)
    {
        for(j=0;j<i;j++)
        {
            if(v[j]>v[j+1])
            {
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                printf("\nA trocar o valor %d por %d", v[j], v[j+1]);
            }
        }
        printf("\nDepois da %d passagem pelo Bubble Sort temos:\n", n-i);
        for(k=0;k<n;k++) printf("%d\t", v[k]);
        printf("\n");
    }
}

void bubble_mod(int n, int* v)
{
    int i, j, k;
    for(i=n-1;i>=1;i--)
    {
        int troca = 0;
        for(j=0;j<i;j++)
        if(v[j]>v[j+1])
        {
            int temp = v[j];
            v[j] = v[j+1];
            v[j+1] = temp;
            printf("\nA trocar o valor %d por %d", v[j], v[j+1]);
            troca = 1;
        }
        printf("\nDepois da %d passagem pelo Bubble Sort temos:\n", n-i);
        for(k=0;k<n;k++) printf("%d\t", v[k]);
        printf("\n");
        if(troca==0)
            return;
    }
}

void selection_sort(int n, int *v)
{
    int i, temp, min, max, j, k;
    for(i=0;i<(n-1);i++)
    {
        printf("\nPassagem %d pelo Selection Sort - ", i+1);
        min = i;
        for(j=i;j<n;j++)
        {
            if (v[j]<v[min])
                min = j;
        }
        if (min != i)
        {
            temp = v[i];
            v[i] = v[min];
            v[min] = temp;
            printf("\nA trocar o valor %d por %d\n", v[min], v[i]);
        } else printf("\nSem troca\n");
        for(k=0;k<n;k++) printf("%d\t", v[k]);
        printf("\n");
    }
}

void selection_mod(int n, int *v)
{
    int i, temp, min, max, j, k;
    for(i=0;i<(n-1);i++)
    {
        int troca = 0;
        printf("\nPassagem %d pelo Selection Sort - ", i+1);
        min = i;
        for(j=i;j<n;j++)
        {
            if (v[j]<v[min])
                min = j;
        }
        if (min != i)
        {
            temp = v[i];
            v[i] = v[min];
            v[min] = temp;
            printf("\nA trocar o valor %d por %d\n", v[min], v[i]);
            troca = 1;
        } else
        {
            if(troca==0)
            {
                return;
            }
        }
        for(k=0;k<n;k++) printf("%d\t", v[k]);
        printf("\n");
    }
}

int main(void)
{
    int i;
    int v[5] = {5,12,1,7,19};
    printf("Vetor desordenado:\n");
    for(i=0;i<5;i++) printf("%d\t", v[i]);
    //bubble_sort(5, v);
    //bubble_mod(5, v);
    //selection_sort(5, v);
    selection_mod(5, v);
}
