#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Stack
{
    int data;
    struct Stack *next;
};

struct Stack *Initialize() // HÀM KHỞI TẠO
{
    return NULL;
}

bool isEmpty(struct Stack *H)
{
    return (H == NULL);
}

struct Stack *InsertBegin(struct Stack *H, int k)
{
    if (isEmpty(H))
    {
        struct Stack *newNode = (struct Stack *)malloc(sizeof(struct Stack));
        newNode->data = k;
        newNode->next = NULL;
        return newNode;
    }
    else
    {
        struct Stack *newNode = (struct Stack *)malloc(sizeof(struct Stack));
        newNode->data = k;
        newNode->next = H;

        return newNode;
    }
}
struct Stack *pop(struct Stack *H)
{
    if (isEmpty(H))
    {
        printf("Hang doi rong");
        return NULL;
    }
    else if (H->next == NULL)
    {
        return NULL;
    }
    else
    {
        struct Stack *toDelete = H;
        H = H->next;
        free(toDelete);
        return H;
    }
}

void Peek(struct Stack *H)
{
    if (isEmpty(H))
    {
        printf("hang doi rong");
        return;
    }
    else
    {
        printf("Phan tu dau tien la [%d]", H->data);
    }
}

void display(struct Stack *H)
{
    if (isEmpty(H))
    {
        printf("Hang doi rong");
        return;
    }
    else
    {
        while (H != NULL)
        {
            printf("[%d] - >", H->data);
            H = H->next;
        }
        printf("NULL");
    }
}
int main()
{
    struct Stack *H;
    H = Initialize();
    H = InsertBegin(H, 10);
    H = InsertBegin(H, 11);
    H = InsertBegin(H, 13);
    H = pop(H);
    display(H);
}