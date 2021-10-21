#ifndef SEQLIST_H_INCLUDED
#define SEQLIST_H_INCLUDED
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
class seqList:public list<elemType> {
private:
    elemType *data;
    int currentLength;
    int maxSize;
    void doubleSpace();
public:
    seqList(int initSize=10);
    ~seqList();
    void clear();
    int length() const;
    void insert(int i, const elemType &x);
    void remove(int i);
    int search(const elemType &x) const;
    elemType visit(int i) const;
    void traverse() const;
};

class OutOfBound {};
#endif // SEQLIST_H_INCLUDED
