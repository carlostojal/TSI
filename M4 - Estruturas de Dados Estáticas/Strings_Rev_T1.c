#include <stdio.h>
#include <string.h>

void main()
{
    char str1[50], str2[50];
    int i, posicao;
    char caractere;
    char *ch;
    char str_esp[50];

    printf("Introduza uma string: ");
    gets(str1);
    printf("Conteudo: %s", str1);
    i = strlen(str1);
    printf(", tem %d caracteres", i);

    strcpy(str2,str1);
    printf("\nPor copia, str2 = str1 = %s",str2);

    strcat(str2, "321 alO");
    printf("\nPor concatenacao de str2 com 321 alO = %s",str2);

    strcpy(str2, "Daniel Manning");
    i = stricmp(str1, str2);
    printf("\nComparacao de str1 com str2 = %d",i);
    if(i == 0) printf("%s = %s", str1, str2);
    else if(i>0) printf("%s > %s", str1, str2);
    else printf("%s < %s",str1, str2);

    printf("\n\nIntroduza um caractere a procurar: ");
    scanf("%c",&caractere);

    for(i=0;str1[i]!=caractere;i++);
    printf("O caractere '%c' foi encontrado na %da posicao.",caractere,i+1);

    i=0;

    ch = strchr(str1,caractere);
    while(ch!=NULL)
    {
        printf("\nO caractere '%c' foi encontrado na %da posicao.",caractere,ch-str1+1);
        ch=strchr(ch+1,caractere);
    }

    printf("\n\n");
    for(i=0;str1[i]!=32;i++)
        printf("%c",str1[i]);

    *ch = strchr(str1,32);
    memset(str_esp, '\0', sizeof(str_esp));
    strncpy(str_esp, str1, &ch);
    printf("\n\n%s",str_esp);


    getch();
}
