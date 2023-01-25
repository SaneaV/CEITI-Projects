/*
Self-referential Structures
made by Ioan Jeleascov && Mihai Redco
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctime>
#include <chrono>

typedef struct phonebook
{
    int roll;
    char name[30];
    char phone_number[20];
    struct phonebook *next;
} node;

node *create_list()
{
    int k, n;
    node *p, *head;

    printf("How many pers to enter: ");
    scanf("%i", &n);
    for(k=0; k<n; k++)
    {
        if(k==0)
        {
            head = (node *)malloc(sizeof(node));
            p=head;
        }
        else
        {
            p->next = (node *)malloc(sizeof(node));
            p=p->next;
        }
        printf("[%i] Pers(pos name num): ", k+1);
        scanf("%i %s %s", &p->roll, p->name, p->phone_number);
    }
    p->next=NULL;

    return (head);
}

void display(node *head)
{
    int count=1, i;
    node *p;

    p=head;
    while(p != NULL)
    {
        printf("Node %i: %i %s %s\n", count, p->roll, p->name, p->phone_number);
        count++;
        p=p->next;
    }
}

void insert(node **head)
{
    int k = 0, rno;
    node *p, *q, *new;

    new = (node *)malloc(sizeof(node));
    printf("Input new pers(pos name num): ");
    scanf("%i %s %s", &new->roll, new->name, new->phone_number);
    printf("Insert before roll(-ve for end): ");
    scanf("%i", &rno);

    p = *head;
    if(p->roll == rno)
    {
        new->next = p;
        *head = new;
    }
    else
    {
        while((p != NULL) && (p->roll != rno))
        {
            q=p;
            p=p->next;
        }
        /* At the end */
        if(p == NULL)
        {
            q->next=new;
            new->next=NULL;
        }
        /* In the middle */
        else if(p->roll == rno)
        {
            q->next=new;
            new->next=p;
        }
    }
}

void delete(node **head)
{
    int rno;
    node *p, *q;

    printf("Delete roll: ");
    scanf("%i", &rno);

    p = *head;
    /* Delete the first element */
    if(p->roll == rno)
    {
        *head = p->next;
        free (p);
    }
    else
    {
        while((p != NULL) && (p->roll != rno))
        {
            q=p;
            p=p->next;
        }
        /* Element not found */
        if(p == NULL)
            printf ("No match: deletion failed\n");
        /* Delete any other element */
        else if (p->roll == rno)
        {
            q->next = p->next;
            free (p);
        }
    }
}

int main(void)
{
    node *head;
    char c;

    system("clear");

    printf("WELCOME TO CORTEX v0.3\n");
    printf("[1] Create\n");
    printf("[2] Insert\n");
    printf("[3] Delete\n");
    printf("[4] Show\n");
    printf("[5] Quit\n");

    do
    {
        fflush(stdin);
        printf("> ");
        scanf("%c", &c);
        switch(c)
        {
        case '1':
            std::chrono::steady_clock::time_point _start(std::chrono::steady_clock::now());
            head = create_list();
            std::chrono::steady_clock::time_point _end(std::chrono::steady_clock::now());

            cout<<"Продолжительность исполнения функции: ";
            cout << std::chrono::duration_cast<std::chrono::duration<double>>(
            _end - _start).count();

            break;
        case '2':
            insert(&head);
            break;
        case '3':
            delete(&head);
            break;
        case '4':
            display(head);
            break;
        case '5':
            exit(0);
            break;
        }
    }
    while(c!=5);

    return 0;
}

