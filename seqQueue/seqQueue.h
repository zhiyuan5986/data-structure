#ifndef SEQQUEUE_H_INCLUDED
#define SEQQUEUE_H_INCLUDED
#include <iostream>
using namespace std;
template <class elemType>
class queue {
public:
    virtual bool isEmpty() const = 0;
    virtual void enQueue(const elemType &x) = 0;
    virtual elemType deQueue() = 0;
    virtual elemType getHead() const = 0;
    virtual ~queue() {}
};
//采用头结点后一个才是实际结点而尾结点直接指向实际结点
template <class elemType>
class seqQueue:public queue<elemType>
{
private:
    elemType *elem;
    int front, rear;
    int maxSize;
    void doubleSpace();
public:
    seqQueue(int initSize = 10);
    ~seqQueue();
    bool isEmpty() const;
    void enQueue(const elemType &x);
    elemType deQueue();
    elemType getHead() const;
};

template <class elemType>
seqQueue<elemType>::seqQueue(int initSize)
{
    elem = new elemType [initSize];
    maxSize = initSize;
    front = rear = 0;
}

template <class elemType>
seqQueue<elemType>::~seqQueue()
{
    delete [] elem;
}

template <class elemType>
void seqQueue<elemType>::enQueue(const elemType &x)
{
    if (front == (rear+1)%maxSize) doubleSpace();
    rear = (rear+1)%maxSize;
    elem[rear] = x;
}
template <class elemType>
elemType seqQueue<elemType>::deQueue()
{
    front = (front+1)%maxSize;
    return elem[front];
}
template <class elemType>
bool seqQueue<elemType>::isEmpty() const
{
    return rear == front;//注意此处不是等于front的后一位，因为rear和front不等的时候一定非空
}
template <class elemType>
elemType seqQueue<elemType>::getHead() const
{
    return elem[(front+1)%maxSize];
}

template <class elemType>
void seqQueue<elemType>::doubleSpace()
{
    elemType *tmp = elem;
    elem = new elemType[2*maxSize];
    for (int i=0;i<maxSize;++i) elem[i] = tmp[(front+i)%maxSize];
    front = 0;rear = maxSize-1;
    maxSize *= 2;
    delete [] tmp;
}
#endif // SEQQUEUE_H_INCLUDED
