#include "seqList.h"
template <class elemType>
seqList<elemType>::seqList(int initSize)
{
    data = new elemType[initSize];
    maxSize = initSize;
    currentLength=0;
}

template <class elemType>
seqList<elemType>::~seqList()
{
    delete data;
}

template <class elemType>
void seqList<elemType>::clear()
{
    currentLength=0;
}

template <class elemType>
int seqList<elemType>::length() const
{
    return currentLength;
}

template <class elemType>
void seqList<elemType>::insert(int i, const elemType &x)
{
    if (currentLength == maxSize)
        doubleSpace();
    for (int j=currentLength;j>i;--j) data[j]=data[j-1];
    data[i]=x;
    ++currentLength;
}

template <class elemType>
void seqList<elemType>::remove(int i)
{
    for (int j=i;j<currentLength-1;++j) data[j]=data[j+1];
    --currentLength;
}

template <class elemType>
int seqList<elemType>::search(const elemType &x) const
{
    for (int i=0;i<currentLength;++i)
        if (data[i] == x) return i;
    return -1;
}
template <class elemType>
elemType seqList<elemType>::visit(int i) const
{
    if (i >= 0 && i < currentLength)
        return data[i];
    else
        throw OutOfBound();
}
template <class elemType>
void seqList<elemType>::traverse() const
{
    for (int i=0;i<currentLength;++i) std::cout << data[i] << ' ';
}
template <class elemType>
void seqList<elemType>::doubleSpace()
{
    elemType *p = data;
    data = new elemType[2*maxSize];
    for (int i=0;i<currentLength;++i) data[i]=p[i];
    delete [] p;
    maxSize *= 2;
}
