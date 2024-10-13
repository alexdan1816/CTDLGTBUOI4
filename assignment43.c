// Hàng đợi ưu tiên
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct StackNode
{
    int data;
    int priority;
    struct StackNode *next;
} StackNode;

struct StackNode *
InitSN(struct StackNode *H) // hàm khởi tạo
{
    return NULL;
}

bool isEmpty(struct StackNode *H)
{
    return H == NULL;
}

struct StackNode *enQueue(struct StackNode *H, int k, int pri)
{

    struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    newNode->data = k;
    newNode->priority = pri;
    newNode->next = NULL;

    if (isEmpty(H) || pri > H->priority)
    {
        newNode->next = H;
        return newNode;
    }
    struct StackNode *T = H;
    struct StackNode *prev = NULL;

    while (T != NULL && T->priority > pri)
    {
        prev = T;
        T = T->next;
    }
    if (T != NULL && T->priority == pri)
    {
        newNode->next = T->next;
        T->next = newNode;
    }
    else
    {
        prev->next = newNode;
        newNode->next = T;
    }
    return H;
}

struct StackNode *deQueue(struct StackNode *H)
{
    if (isEmpty(H))
    {
        printf("STACK rong");
        return NULL;
    }
    else
    {
        struct StackNode *toDelete = H;
        H = H->next;
        free(toDelete);
        return H;
    }
}

void Peak(struct StackNode *H)
{
    if (isEmpty(H))
    {
        printf("Stack rong");
        return;
    }
    else
    {
        printf("Phan tu dau tien la %d\n", H->data);
    }
}

void display(struct StackNode *H)
{
    while (H != NULL)
    {
        printf("%d -> ", H->data);
        H = H->next;
    }
    printf("NULL\n");
}
int main()
{
    struct StackNode *H;
    H = InitSN(H);
    H = enQueue(H, 20, 5);
    H = enQueue(H, 19, 4);
    H = enQueue(H, 18, 4);
    H = enQueue(H, 17, 2);
    H = enQueue(H, 16, 1);
    display(H);

    H = deQueue(H);
    display(H);
}