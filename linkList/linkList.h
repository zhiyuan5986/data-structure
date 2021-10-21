#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#include <iostream>
template <class elemType>
class list {
public:
    virtual void clear()=0;
    virtual int length() const = 0;
    virtual void insert(int i, const elemType &x)=0;
    virtual void remove(int i)=0;
    virtual int search(const elemType &x)const=0;
    virtual elemType visit(int i)const=0;
    virtual void traverse()const=0;
    virtual ~list() {}
};

template <class elemType>
class linkList : public list<elemType> {
private:
    struct node {
        elemType data;
        node *next;
        node(const elemType &x, node *n) {data = x;next = n;}
        node():next(NULL) {}
        ~node() {}
    };
    node *head;
    int currentLength;
    node *move(int i) const;
public:
    linkList();
    ~linkList();
    void clear();
    int length() const;
    void insert(int i, const elemType &x);
    void remove(int i);
    int search(const elemType &x) const;
    elemType visit(int i) const;
    void traverse() const;
};

template <class elemType>
linkList<elemType>::linkList()
{
    head = new node;
    currentLength = 0;
}
template <class elemType>
linkList<elemType>::~linkList()
{
    clear();
    delete head;

}
template <class elemType>
int linkList<elemType>::length() const
{
    return currentLength;
}
template <class elemType>
void linkList<elemType>::clear()
{
    node *p = head,*q;
    while (p != NULL) {
        q = p->next;
        delete p;
        p = q;
    }
    head->next = NULL;
    currentLength = 0;
}

template <class elemType>
typename linkList<elemType>::node *linkList<elemType>::move(int i) const
{
    node *p = head;
    while (i > 0) {p = p->next;--i;}
    return p;
}
template <class elemType>
void linkList<elemType>::insert(int i, const elemType &x)
{
    node *p = move(i);
    p->next= new node(x,p->next);

    ++currentLength;
}

template <class elemType>
void linkList<elemType>::remove(int i)
{
    node *p = move(i);
    node *q = p->next;
    p->next = p->next->next;
    delete q;
    --currentLength;
}

template <class elemType>
int linkList<elemType>::search(const elemType &x) const
{
    node *p = head->next;
    int i=0;
    while (p != NULL && p->data != x) {
        ++i;
        p=p->next;
    }
    if (p == NULL) return -1;
    return i;
}

template <class elemType>
elemType linkList<elemType>::visit(int i) const
{
    return move(i+1)->data;
}

template <class elemType>
void linkList<elemType>::traverse() const
{
    node *p = head->next;
    while (p != NULL) {
        std::cout << p->data << ' ';
        p = p->next;
    }
    std::cout << std::endl;
}

#endif // LINKLIST_H_INCLUDED
