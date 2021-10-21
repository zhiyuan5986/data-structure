#ifndef LINKQUEUE_H_INCLUDED
#define LINKQUEUE_H_INCLUDED
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
template <class elemType>
class linkQueue:public queue<elemType> {
private:
    struct node {
        elemType data;
        node *next;
        node(const elemType &x, node *n) {data = x;next = n;}
        node():next(NULL) {}
        ~node() {}
    };
    node *front, *rear;
public:
    linkQueue();
    ~linkQueue();
    bool isEmpty() const;
    void enQueue(const elemType &x);
    elemType deQueue();
    elemType getHead() const;
};

template <class elemType>
linkQueue<elemType>::linkQueue()
{
    front = rear = NULL;
}

template <class elemType>
linkQueue<elemType>::~linkQueue()
{
    node *tmp = front;
    while (front) {
        tmp = front;
        front = front->next;
        delete tmp;
    }
}

template <class elemType>
bool linkQueue<elemType>::isEmpty() const
{
    return front == NULL;
}

template <class elemType>
void linkQueue<elemType>::enQueue(const elemType &x)
{
    if (front == NULL) front = rear = new node(x,NULL);
    else {rear = rear->next = new node(x,NULL);}
}

template <class elemType>
elemType linkQueue<elemType>::deQueue()
{
    node *tmp = front;
    elemType x = tmp->data;
    if (front == rear) front = rear = NULL;
    else front = front->next;
    delete tmp;
    return x;
}
template <class elemType>
elemType linkQueue<elemType>::getHead() const
{
    return front->data;
}
#endif // LINKQUEUE_H_INCLUDED
