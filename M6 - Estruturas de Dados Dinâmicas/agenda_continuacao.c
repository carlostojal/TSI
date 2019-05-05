void ler_fich(Ficha *LISTA)
{
    FILE *fp;
    Ficha *tmp;
    LISTA->prox=NULL;
    fp = fopen("agenda.txt","r");
    if(fp==NULL)
    {
        printf("Impossivel abrir ficheiro...");
        getch();
    }
    while(!feof(fp))
    {
        Ficha *novo=(Ficha*)malloc(sizeof(Ficha));
        if(!novo)
        {
            printf("Sem memoria disponivel\n");
            exit(1);
        }
        else
        {
            fscanf(fp,"%d %s %s %s %d/%d/%d",&novo->num,&novo->Nome,&novo->Telef,&novo->Email);
            novo->prox = NULL;
            if(LISTA->prox==NULL)
                LISTA->prox = novo;
            else
            {
                Ficha *tmp = LISTA->prox;
                while(tmp->prox != NULL)
                    tmp = tmp->prox;
                tmp->prox = novo;
            }
            tam++;
            last++;
        }
    }
    fclose(fp);
}
