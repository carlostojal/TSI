#include <stdio.h>
#include <stdlib.h>
#include "MenuManager.h"
#include "ContactsManager.h"

int main()
{
    Contact *list = (Contact*) malloc(sizeof(Contact));
    list->next = NULL;
    list->prev = NULL;
    int id;
    int opt;
    do {
        opt = MainMenu();
        switch(opt)
        {
            case 1:
                id = GetLastId();
                ReadContact(list,id);
                break;
            case 2:
                CleanList(list);
                GetContacts(list);
                //scanf("%d",&opt);
                ListContacts(list);
                break;
        }
    }while(opt);
    return 0;
}
