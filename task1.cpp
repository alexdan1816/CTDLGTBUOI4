// HÃY CÀI ĐẶT MỘT STACK SỐ NGUYÊN BẰNG DANH SÁCH MÓC NỐI
#include <iostream>
using namespace std;
struct StackNode
{
    int data;
    StackNode *next;
};
typedef StackNode *Pnode;
/*
struct LinkedList
{
    Pnode head;
};*/


StackNode* InitSN(StackNode *H)
{
   return nullptr;
}

bool isEmpty(StackNode *H)
{
    return H==nullptr;
}

StackNode* insertBegin(StackNode *H, int k)
{
    StackNode *Q = new StackNode;
    if(isEmpty(H))
    {
        Q->data=k;
        Q->next=nullptr;
        return Q;
    }
    else
    {
        Q->data=k;
        Q->next=H;
        return Q;
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
    H=insertBegin(H,2);
    Peak(H);
    display(H);
    

}