#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include <iostream>
using namespace std;
//linkQueue
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

//binaryTree

template <class T>
class bTree {
public:
    virtual void clear() = 0;
    virtual bool isEmpty() const = 0;
    virtual T Root (T flag) const = 0;
    virtual T parent(T x, T flag) const = 0;
    virtual T lchild(T x, T flag) const = 0;
    virtual T rchild(T x, T flag) const = 0;
    virtual void delLeft(T x) = 0;
    virtual void delRight(T x) = 0;
    virtual void preOrder() const = 0;
    virtual void midOrder() const = 0;
    virtual void postOrder() const = 0;
    virtual void levelOrder() const = 0;
};
template <class T>
class binaryTree:public bTree<T> {
private:
    struct node {
        T data;
        node *left, *right;
        node():left(NULL),right(NULL) {}
        node(T d,node *l=NULL,node *r=NULL) {data = d;left = l;right = r;}
    };
    node *root;
    void clear(node* &t);
    void preOrder(node *t) const;
    void midOrder(node *t) const;
    void postOrder(node *t) const;
    node* find(T x, node *t) const;
public:
    binaryTree():root(NULL) {}
    binaryTree(T x) {root = new node(x);}
    ~binaryTree();
    void clear();
    bool isEmpty() const;
    T Root(T flag) const;
    T parent(T x, T flag) const;
    T lchild(T x, T flag) const;
    T rchild(T x, T flag) const;
    void delLeft(T x);
    void delRight(T x);
    void preOrder() const;
    void midOrder() const;
    void postOrder() const;
    void levelOrder() const;
    void createTree(T flag);
    void printTree(T flag) const;
};

//template <class T>
//binaryTree<T>::binaryTree()
//{
//    root = NULL;
//}

template <class T>
binaryTree<T>::~binaryTree()
{
    clear(root);
}

template <class T>
void binaryTree<T>::clear(typename binaryTree<T>::node *&t)
{
    if (t == NULL) return;
    clear(t->left);
    clear(t->right);
    delete t;
    t = NULL;
}

template <class T>
void binaryTree<T>::clear()
{
    clear(root);
}


template <class T>
bool binaryTree<T>::isEmpty() const
{
    return root == NULL;
}

template <class T>
T binaryTree<T>::Root(T flag) const
{
    return (root == NULL ? flag : root->data);
}

template <class T>
T binaryTree<T>::parent(T x, T flag) const
{
    return flag;
}

template <class T>
T binaryTree<T>::lchild(T x, T flag) const
{
    node *tmp = find(x,root);
    if (tmp == NULL || tmp->left == NULL) return flag;
    return tmp->left->data;
}

template <class T>
T binaryTree<T>::rchild(T x, T flag) const
{
    node *tmp = find(x, root);
    if (tmp == NULL || tmp->right == NULL) return flag;
    return tmp->right->data;
}

template <class T>
void binaryTree<T>::delLeft(T x)
{
    node *tmp = find(x, root);
    if (tmp->left == NULL) return;
    clear(tmp->left);
}

template <class T>
void binaryTree<T>::delRight(T x)
{
    node *tmp = find(x, root);
    if (tmp->right == NULL) return;
    clear(tmp->right);
}

template <class T>
typename binaryTree<T>::node* binaryTree<T>::find(T x, binaryTree<T>::node *t) const
{
    node *tmp;
    if (t == NULL) return NULL;
    if (t->data == x) return t;
    if (tmp=find(x,t->left)) return tmp;
    else return find(x,t->right);
}

template <class T>
void binaryTree<T>::preOrder(typename binaryTree<T>::node *t) const
{
    if (t == NULL) return;
    cout << t->data << ' ';
    preOrder(t->left);
    preOrder(t->right);
}

template <class T>
void binaryTree<T>::preOrder() const
{
    preOrder(root);
}

template <class T>
void binaryTree<T>::midOrder(typename binaryTree<T>::node *t) const
{
    if (t == NULL) return;
    midOrder(t->left);
    cout << t->data << ' ';
    midOrder(t->right);
}

template <class T>
void binaryTree<T>::midOrder() const
{
    midOrder(root);
}

template <class T>
void binaryTree<T>::postOrder(typename binaryTree<T>::node *t) const
{
    if (t == NULL) return;
    postOrder(t->left);
    postOrder(t->right);
    cout << t->data << ' ';
}

template <class T>
void binaryTree<T>::postOrder() const
{
    postOrder(root);
}

template <class T>
void binaryTree<T>::levelOrder() const
{
    linkQueue< node* > q;
    node *tmp;

    cout << "\nlevelOrder:";
    q.enQueue(root);

    while (!q.isEmpty()) {
        tmp = q.deQueue();
        cout << tmp->data << ' ';
        if (tmp->left) q.enQueue(tmp->left);
        if (tmp->right) q.enQueue(tmp->right);//两个if判断条件不能少
    }
}

template <class T>
void binaryTree<T>::createTree(T flag)
{
    linkQueue< node* > q;
    node *tmp;
    T x, ldata, rdata;
    cout << "\nenter the root:" ;
    cin >>x;
    root = new node(x);
    q.enQueue(root);

    while (!q.isEmpty()) {
        tmp = q.deQueue();
        cout << "\nenter " << tmp->data << "'''s two sons, with " << flag << " stands for NULL:";
        cin >> ldata >> rdata;
        if (ldata != flag) q.enQueue(tmp->left = new node(ldata));
        if (rdata != flag) q.enQueue(tmp->right = new node(rdata));
    }
    cout << "\ncompleted.";
}

template <class T>
void binaryTree<T>::printTree(T flag) const
{
    linkQueue<T> q;
    q.enQueue(root->data);
    cout << endl;
    while (!q.isEmpty()) {
        T p,l,r;
        p = q.deQueue();
        l = lchild(p,flag);
        r = rchild(p,flag);
        cout << p << ' ' << l << ' ' << r <<endl;
        if (l != flag) q.enQueue(l);
        if (r != flag) q.enQueue(r);
    }
}
#endif // BINARYTREE_H_INCLUDED
