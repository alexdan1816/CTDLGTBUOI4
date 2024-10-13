// HÃY CÀI ĐẶT MỘT STACK SỐ NGUYÊN BẰNG DANH SÁCH MÓC NỐI. Tạo thành kiểu hàng đợi Queue
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct StackNode
{
    int data;
    struct StackNode *next;
};

typedef struct Queue
{
    struct StackNode *Front;
    struct StackNode *Rear;
};

struct Queue *creatQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->Front = q->Rear = NULL;
    return q;
}

bool isEmpty(struct Queue *q)
{
    return (q->Front == NULL);
}
void enQueue(struct Queue *q, int k)
{
    struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    newNode->next = NULL;
    newNode->data = k;
    if (isEmpty(q))
    {
        q->Front = q->Rear = newNode;
    }
    else
    {
        q->Rear->next = newNode;
        q->Rear = newNode;
    }
}
void deQueue(struct Queue *q)
{
    if (isEmpty(q))
    {
        return;
    }
    struct StackNode *temp = q->Front;
    q->Front = q->Front->next;
    if (q->Front = NULL)
    {
        q->Rear = NULL;
    }
    free(temp);
}

void display(struct Queue *q)
{
    struct StackNode *temp;
    temp = q->Front;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
int main()
{
    struct Queue *q;
    q = creatQueue();
    enQueue(q, 10);
    enQueue(q, 12);
    enQueue(q, 13);
    display(q);
}