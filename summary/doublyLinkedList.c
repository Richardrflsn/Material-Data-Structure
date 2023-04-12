#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
    struct node *prev;
};
struct node* head = NULL;
struct node* tail = NULL;

void push(int node){
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->value = node;
    if (head == NULL)
    {
        new_node->prev = new_node->next = NULL;
        head = tail = new_node;
    } else
    {
        new_node->prev = tail;
        new_node->next = NULL;
        tail->next = new_node;
        tail = new_node;
    }
}

void pushHead(int node){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = node;
    new_node->prev = NULL;
    new_node->next = head;
    head = new_node;
}

void pushEnd(int node){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = node;
    new_node->next = NULL;
    new_node->prev = NULL;
    struct node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
    new_node->prev = curr;
}

void pushMiddle(int node) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = node;
    new_node->prev = NULL;
    new_node->next = NULL;
    
    if (head == NULL) {
        head = new_node;
        return;
    }
    
    struct node *curr = head;
    int count = 0;
    while (curr->next != NULL) {
        count++;
        curr = curr->next;
    }
    
    int middle = count / 2;
    curr = head;
    int i;
    for (i = 0; i < middle; i++) {
        curr = curr->next;
    }
    
    new_node->next = curr->next;
    new_node->prev = curr;
    if (curr->next != NULL) {
        curr->next->prev = new_node;
    }
    curr->next = new_node;
}

void deleteBySearching(int valueToDelete) {
    struct node* current = head;
    while (current != NULL && current->value != valueToDelete) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Value not found in the list.\n");
        return;
    }
    if (current == head) {
        head = current->next;
    } else {
        current->prev->next = current->next;
    }
    if (current == tail) {
        tail = current->prev;
    } else {
        current->next->prev = current->prev;
    }
    free(current);
}

void reverse(){
    struct node *temp = NULL;
    struct node *curr = head;
    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != NULL)
    {
        head = tail;
        tail = curr;
    }
}

void reverse2(){
    struct node *ptr1 = head;
    struct node *ptr2 = ptr1->next;
    
    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while (ptr2 != NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;
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
    push(1);
    push(7);
    push(10);
    push(2);
    printList();
    deleteBySearching(10);
    printList();
    reverse();
    printList();
    pushHead(11);
    printList();
    pushMiddle(90);
    printList();
    pushEnd(22);
    printList();
    pushEnd(35);
    printList();
    reverse2();
    printList();
    return 0;
}