//Hàng đợi ưu tiên
#include <iostream>
using namespace std;
struct StackNode
{
    int priority;
    int data;
    StackNode *next;
};



StackNode* InitSN(StackNode *H)
{
   return nullptr;
}

bool isEmpty(StackNode *H)
{
    return H==nullptr;
}

StackNode* insertBegin(StackNode *H, int k,int pri)
{
    StackNode *Q = new StackNode;
    if(isEmpty(H))
    {
        Q->data=k;
        Q->next=nullptr;
        Q->priority=pri;
        return Q;
    }
    if(pri>H->priority)
    {
        StackNode *NewNode = new StackNode;
        NewNode->data=k;
        NewNode->priority=pri;
        NewNode->next=H;
        return NewNode;
    }
    else
    {
        while(H->priority>pri)
        {
            H=H->next;
        }
        if(H->priority<pri)
        {
        StackNode *NewNode = new StackNode;
        NewNode->data=H->data;
        NewNode->priority=H->priority;
        NewNode->next=H->next;
        H->data=k;
        H->priority=pri;
        H->next=NewNode;
        return H;
        }
        else
        {
        StackNode *NewNode = new StackNode;
        NewNode->data=k;
        NewNode->priority=pri;
        NewNode->next=H->next;
        H->next=NewNode;

        }

    }

}
StackNode* pop(StackNode *H)
{
    if(isEmpty(H))
    {
        printf("STACK rong");
        return 0;
    }
    else
    {
        StackNode* toDelete = new StackNode;
        toDelete=H;
        H=H->next;
        delete toDelete;
        return H;
    }
}

void Peak(StackNode*H)
{
    if(isEmpty(H))
    {
        printf("Stack rong");
        return;
    }
    else
    {
        printf("Phan tu dau tien la %d\n", H->data);
    }
}

void display(StackNode *H)
{
    while(H!=nullptr)
    {
        printf("%d -> ",H->data);
        H=H->next;
    }
    printf("NULL");
}
int main()
{
    StackNode *H;
    H=InitSN(H);
    H=insertBegin(H,20,5);
    H=insertBegin(H,19,4);
    H=insertBegin(H,18,4);
    H=insertBegin(H,17,2);
    H=insertBegin(H,16,1);
    display(H);
    

}