#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node* next;
};
struct node* head = NULL;

void push(int node){
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->next = NULL;
    new_node->value = node;
    if (head == NULL)
    {
        head = new_node;
    } else
    {
        struct node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

void pushHead(int node){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = node;
    new_node->next = head;
    head = new_node;
}

void pushMiddle(int node){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->next = NULL;
    new_node->value = node;
    struct node *curr = head;
    int count = 0;
    while (curr->next != NULL)
    {
        count++;
        curr = curr->next;
    }
    int middle = count/2;
    curr = head;
    int i;
    for ( i = 0; i < middle; i++)
    {
        curr = curr->next;
    }
    new_node->next = curr->next;
    curr->next = new_node;
}

void pushEnd(int node){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->next = NULL;
    new_node->value = node;
    struct node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
}

void pop(int node){
    int value = 0;
    value = node;
    struct node *curr = head;
    struct node *temp = NULL;
    if (head == NULL)
    {
        return;
    }
    if (value == head->value)
    {
        temp = head;
        head = head->next;
        free(temp);
    } else
    {
        curr = head;
        while (curr->next != NULL)
        {
            if (value == curr->next->value)
            {
                temp = curr->next;
                curr->next = temp->next;
                free(temp);
            }
            curr = curr->next;
        }
    }
    if (temp == NULL)
    {
        return;
    }
}

void sortList(){
    struct node *curr = head;
    struct node *index = NULL;
    int temp;
    if (head == NULL)
    {
        return;
    } else
    {
        while (curr != NULL)
        {
            index = curr->next;
            while (index != NULL)
            {
                if (curr->value > index->value)
                {
                    temp = curr->value;
                    curr->value = index->value;
                    index->value = temp;
                }
                index = index->next;
            }
            curr =  curr->next;
        }
    }
}

void searchList(int key){
    struct node *curr = head;
    int found = 0;
    while (curr != NULL)
    {
        if (curr->value == key)
        {
            found = 1;
        }
        
        curr = curr->next;
    }
    if (found == 1)
    {
        printf("found\n");
    } else
    {
        printf("not found\n");
    }
}

void printList(){
    struct node *curr = head;
    while (curr != NULL)
    {
        printf("%d ---> ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    push(5);
    push(10);
    push(20);
    push(30);
    push(40);
    printList();
    pop(30);
    printList();
    pushMiddle(99);
    printList();
    sortList();
    printList();
    searchList(20);
    searchList(30);
    pushEnd(17);
    pushEnd(22);
    printList();
    pushHead(1);
    printList();
    return 0;
}