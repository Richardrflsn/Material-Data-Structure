#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

void insert(int value){
    if (rear == MAX - 1)
    {
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }else
    {
        rear++;
    }
    queue[rear] = value;
}

void delete(){
    int val;
    if (front == -1)
    {
        return;
    }
    else
    {
        val = queue[front];
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
        printf("Deleted element: %d\n", val);
    }
}

void printQueue(){
    int i;
    if (front == -1)
    {
        printf("Empty\n");
    }else
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main()
{
    int value = 0;
    int loop = 0;
    while (loop < MAX)
    {
        printf("insert data : ");
        scanf("%d", &value);
        if (value == -1)
        {
            break;;
        }
        insert(value);
        loop++;
        if (loop == MAX)
        {
            printf("FULL");
        }
    }

    printQueue();
    delete();
    printQueue();
    delete();
    printQueue();
    return 0;
}