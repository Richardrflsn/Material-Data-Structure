#include <stdio.h>
#include <stdlib.h>

struct stack{
    int data;
    struct stack *next;
};
struct stack *top = NULL;

struct stack *push(struct stack *top, int value){
    struct stack *new;
    new = (struct stack*)malloc(sizeof(struct stack));
    new->data = value;
    if (top == NULL)
    {
        top = new;
        top->next = NULL;
    } else
    {
        new->next = top;
        top = new;
    }
    return top;
}

struct stack *pop(struct stack *pop){
    if (pop == NULL)
    {
        printf("Empty");
        return NULL;
    }
    struct stack *temp;
    temp = pop;
    top = pop->next;
    free(temp);
    return top;
}

void printStack(){
    printf("%d ", top->data);
    printf("\n\n");
}

int main()
{
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);
    top = push(top, 50);
    printStack();
    pop(top);
    printStack();
    pop(top);
    printStack();
    pop(top);
    printStack();
    pop(top);
    printStack();
    
    return 0;
}