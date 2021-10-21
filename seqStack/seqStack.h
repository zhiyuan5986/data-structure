#ifndef SEQSTACK_H_INCLUDED
#define SEQSTACK_H_INCLUDED
#include <iostream>
template <class elemType>
class stack {
public:
    virtual bool isEmpty() const = 0;
    virtual void push(const elemType &x)=0;
    virtual elemType pop() = 0;
    virtual elemType top() const = 0;
    virtual ~stack() {}
};

template <class elemType>
class seqStack :public stack<elemType> {
private:
    elemType *data;
    int currentLength;
    int maxSize;
    void doubleSpace();
public:
    seqStack(int init = 10);
    ~seqStack();
    bool isEmpty() const;
    void push(const elemType &x);
    elemType pop();
    elemType top() const;
};

template <class elemType>
seqStack<elemType>::seqStack(int init)
{
    data = new elemType[init];
    currentLength = 0;
    maxSize = init;
}

template <class elemType>
seqStack<elemType>::~seqStack()
{
    delete [] data;
}
template <class elemType>
void seqStack<elemType>::doubleSpace()
{
    elemType *data_ = new elemType[maxSize*2];
    for (int i=0;i<currentLength;++i) data_[i] = data[i];
    delete [] data;
    data = data_;
    maxSize*=2;
}
template <class elemType>
bool seqStack<elemType>::isEmpty() const
{
    return (currentLength == 0);
}

template <class elemType>
void seqStack<elemType>::push(const elemType &x)
{
    if (currentLength == maxSize) doubleSpace();
    data[currentLength] = x;
    ++currentLength;
}
template <class elemType>
elemType seqStack<elemType>::pop()
{
    if (!this->isEmpty()) {
        --currentLength;
        return data[currentLength];
    }
}
template <class elemType>
elemType seqStack<elemType>::top() const
{
    return data[currentLength-1];
}
#endif // SEQSTACK_H_INCLUDED
