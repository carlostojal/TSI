#include <stdio.h>

typedef struct Contacts {
    int id;
    char name[30];
    char email[50];
    char phone[30];
    struct Contacts *next;
    struct Contacts *prev;
}Contact;
