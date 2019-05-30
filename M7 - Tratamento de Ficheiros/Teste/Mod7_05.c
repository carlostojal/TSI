//Carlos Tojal, nº5, 1ºTSI

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estruturas de Dados
typedef struct Aluno {
    int Numero;
    char Nome[20];
    char Turma[10];
    int Idade;
    float Altura;
    float Peso;
} Aluno;

//Protótipos
int menu();
void ler_aluno(Aluno *novo);
void listar_aluno(Aluno aluno);

//Código principal
int main()
{
    int opt;
    int tam=0;
    int x;
    Aluno pesquisa;
    Aluno alunos[111];
    FILE *fp;
    do{
        opt = menu();
        switch(opt)
        {
            case 1:
                fp = fopen("alunos05.csv","r");
                if(!fp)
                    printf("\nErro: Nao foi possivel abrir o ficheiro. Talvez nao exista.\n");
                else
                {
                    while(!feof(fp)) //guarda o conteúdo do ficheiro no vetor
                    {
                        fscanf(fp,"%s %s %d %d %f %f",alunos[tam].Turma,alunos[tam].Nome,&alunos[tam].Numero,&alunos[tam].Idade,&alunos[tam].Altura,&alunos[tam].Peso);
                        tam++;
                    }
                }
                fclose(fp);
                printf("\nDados carregados com sucesso. %d registos.\n",tam-1);
                break;
            case 2:
                printf("tam: %d\n",tam);
                ler_aluno(&alunos[tam-1]); //recebe os dados de um novo aluno, para a posição a seguir à do último valor introduzido
                tam++; //aumenta o tamanho
                break;
            case 3:
                if(tam-1<=0) //se nunca foram carregados dados
                    printf("\nAviso: Ainda nao carregou a lista ou a mesma esta vazia. Adicione alguns dados primeiro.\n");
                else
                {
                    printf("\n** Listar alunos por Turma **\n\n");
                    printf("Turma: ");
                    scanf("%s",pesquisa.Turma);
                    for(x=0;x<tam-1;x++)
                    {
                        if(strcmp(alunos[x].Turma,pesquisa.Turma)==0)
                            listar_aluno(alunos[x]);
                    }
                }
                break;
            case 4:
                if(tam-1<=0) //se nunca foram carregados dados
                    printf("\nAviso: Ainda nao carregou a lista ou a mesma esta vazia. Adicione alguns dados primeiro.\n");
                else
                {
                    printf("\n** Listar alunos por Idade **\n\n");
                    printf("Idade: ");
                    scanf("%d",&pesquisa.Idade);
                    for(x=0;x<tam-1;x++)
                    {
                        if(alunos[x].Idade==pesquisa.Idade)
                            listar_aluno(alunos[x]);
                    }
                }
                break;
        }
    }while(opt);
    fp = fopen("alunos05.csv","w");
    fprintf(fp,""); //limpa o conteúdo existente
    fclose(fp);
    fp = fopen("alunos05.csv","a");
    for(x=0;x<tam-1;x++) //descarrega o vetor no ficheiro
        fprintf(fp,"%s %s %d %d %f %f\n",alunos[x].Turma,alunos[x].Nome,alunos[x].Numero,alunos[x].Idade,alunos[x].Altura,alunos[x].Peso);
    fclose(fp);
    return 0;
}

//Funções
int menu()
{
    int opt;
    do{
        printf("\n** Mod7_05 **\n\n");
        printf("1. Ler ficheiro\n");
        printf("2. Adicionar Aluno\n");
        printf("3. Listar alunos por Turma\n");
        printf("4. Listar alunos por Idade\n");
        printf("0. Terminar o programa\n\n");
        printf("Opcao: ");
        scanf("%d",&opt);
    }while(opt<0||opt>4); //repete enquanto a opção for inválida
    return opt;
}

void ler_aluno(Aluno *novo)
{
    printf("\n** Ler Aluno **\n\n");
    printf("Numero: ");
    scanf("%d",&novo->Numero);
    printf("Nome: ");
    scanf("%s",novo->Nome);
    printf("Turma: ");
    scanf("%s",novo->Turma);
    printf("Idade: ");
    scanf("%d",&novo->Idade);
    printf("Altura: ");
    scanf("%f",&novo->Altura);
    printf("Peso: ");
    scanf("%f",&novo->Peso);
}

void listar_aluno(Aluno aluno)
{
    printf("\n** Listar Aluno **\n\n");
    printf("Numero: %d\n",aluno.Numero);
    printf("Nome: %s\n",aluno.Nome);
    printf("Turma: %s\n",aluno.Turma);
    printf("Idade: %d\n",aluno.Idade);
    printf("Altura: %.2f\n",aluno.Altura);
    printf("Peso: %.2f\n",aluno.Peso);
}
