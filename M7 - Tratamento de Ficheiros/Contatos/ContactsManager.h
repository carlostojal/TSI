#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataStructures.h"

int GetLastId()
{
    FILE *fp;
    int id;
    fp = fopen("last.id","r");
    fscanf(fp,"%d",&id);
    fclose(fp);
    return id;
}

void InsertContact(Contact *list,Contact *new)
{
    Contact *p = (Contact*) malloc(sizeof(Contact));
    Contact *last = (Contact*) malloc(sizeof(Contact));
    p->next = NULL;
    p->prev = NULL;
    strcpy(p->name,"");
    strcpy(p->email,"");
    strcpy(p->phone,"");
    last->next = NULL;
    last->prev = NULL;
    strcpy(last->name,"");
    strcpy(last->email,"");
    strcpy(last->phone,"");

    if(list->next == NULL)
    {
        printf("primeiro elemento\n");
        new->prev = list;
        list->next = new;
    }
    else
    {
        for(p=list->next;p!=NULL;p=p->next)
        {
            if(strcmp(p->name,new->name)>0)
                break;
        }
        if(p==NULL) //se deve ser inserido à cauda
        {
            printf("a cauda\n");
            for(last=list->next;last->next!=NULL;last=last->next){}
            p=last;
            new->prev = p;
            p->next = new;
            list = p;
        }
        else if(p==list->next)
        {
            printf("a cabeca\n");
            list->next->prev = new;
            new->next = list->next;
            list->next = new;
        }
        else
        {
            //printf("no meio\n");
            new->next = p;
            new->prev = p->prev;
            p->prev->next = new;
            p->prev = new;
            list = p;
        }
    }
}

void ReadContact(Contact *list,int id)
{
    Contact *new = (Contact*) malloc(sizeof(Contact));
    new->next = NULL;
    new->prev = NULL;
    new->id = id;
    Contact *p = (Contact*) malloc(sizeof(Contact));
    FILE *fp;
    char filename[50];

    printf("\n** Ler Contato %d **\n\n",new->id);
    printf("Nome: ");
    scanf("%s",new->name);
    printf("Email: ");
    scanf("%s",new->email);
    printf("Numero de telemovel: ");
    scanf("%s",new->phone);
    InsertContact(list,new);
    sprintf(filename,"%d.ct",new->id);
    fp = fopen(filename,"w");
    fprintf(fp,"%s\n%s\n%s\n",new->name,new->email,new->phone);
    fclose(fp);
    fp = fopen("last.id","w");
    fprintf(fp,"%d\n",new->id+1);
    fclose(fp);
}

void ListContact(Contact *p)
{
    //Contact *p = (Contact*) malloc(sizeof(Contact));
    //for(p=list->next;p!=NULL;p=p->next)
    {
        printf("\n** Contato %d **\n\n",p->id);
        printf("Nome: %s\n",p->name);
        printf("Email: %s\n",p->email);
        printf("Numero de telemovel: %s\n\n",p->phone);
    }
}

void GetContacts(Contact *list)
{
    FILE *fp;
    Contact *new = (Contact*) malloc(sizeof(Contact));
    Contact *p = (Contact*) malloc(sizeof(Contact));
    int id;
    int lastid = GetLastId();
    char filename[50];
    int i;
    int state=1;
    char temp[50];
    for(id=1;id<lastid;id++)
    {
        sprintf(filename,"%d.ct",id);
        fp = fopen(filename,"r");
        if(fp)
        {
            state=1;
            strcpy(new->name,"");
            strcpy(new->email,"");
            strcpy(new->phone,"");
            new->next = NULL;
            new->prev = NULL;
            new->id = id;
            while(fgets(temp,50,fp))
            {
                if(state==1)
                {
                    for(i=0;temp[i]!='\n';i++)
                        new->name[i] = temp[i];
                    printf("name:%s\n",new->name);
                }
                if(state==2)
                {
                    for(i=0;temp[i]!='\n';i++)
                        new->email[i] = temp[i];
                    printf("email: %s\n",new->email);
                }
                if(state==3)
                {
                    for(i=0;temp[i]!='\n';i++)
                        new->phone[i] = temp[i];
                    printf("phone: %s\n",new->phone);
                }
                state++;
                printf("temp: %s\n",temp);
                strcpy(temp,"");
            }
            //ListContact(new);
            InsertContact(list,new);
        }
        fclose(fp);
    }
}

void ListContacts(Contact *list)
{
    Contact *p = (Contact*) malloc(sizeof(Contact));
    for(p=list->next;p!=NULL;p=p->next)
    {
        printf("\n** Contato %d **\n\n",p->id);
        printf("Nome: %s\n",p->name);
        printf("Email: %s\n",p->email);
        printf("Numero de telemovel: %s\n\n",p->phone);
    }
}

void CleanList(Contact *list)
{
    Contact *p = (Contact*) malloc(sizeof(Contact));
    list->next = NULL;
}
