// HÃY CÀI ĐẶT MỘT STACK SỐ NGUYÊN BẰNG DANH SÁCH MÓC NỐI. Tạo thành kiểu hàng đợi Queue
#include <iostream>
using namespace std;
struct StackNode
{
    int data;
    StackNode *next;
};

struct Queue
{
    StackNode *Front;
    StackNode *Rear;
};


Queue *creatQueue()
{
    Queue*q=new Queue;
    q->Front=q->Rear=nullptr;
    return q;
}

bool isEmpty(Queue *q)
{
    return (q->Front==nullptr);
}
void enQueue(Queue *q,int k)
{
    StackNode* newNode= new StackNode;
    newNode->next=nullptr;
    newNode->data=k;
    if(isEmpty(q))
    {
        q->Front=q->Rear=newNode;
    }
    else
    {
        q->Rear->next=newNode;
        q->Rear=newNode;
    }
}
void deQueue(Queue *q)
{
    if(isEmpty(q))
    {
        return;
    }
    StackNode *temp = q->Front;
    q->Front=q->Front->next;
    if(q->Front=nullptr)
    {
        q->Rear=nullptr;
    }
    delete temp;
    
}

void display(Queue *q)
{
    StackNode *temp;
    temp=q->Front;
    while(q!=nullptr)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
int main()
{
    Queue *q;
    q=creatQueue();
    enQueue(q,10);
    enQueue(q,12);
    enQueue(q,13);
    display(q);

}