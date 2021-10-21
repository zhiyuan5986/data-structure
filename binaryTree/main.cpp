#include <iostream>
#include "binaryTree.h"
using namespace std;

int main()
{
    binaryTree<char> tree;

    tree.createTree('@');
    tree.preOrder();
    cout << endl;
    tree.midOrder();
    cout << endl;
    tree.postOrder();
    cout <<endl;
    tree.levelOrder();
    cout <<endl;
    tree.printTree('@');
    tree.delLeft('L');
    tree.delRight('C');
    tree.delLeft('C');
    tree.preOrder();
    cout << endl;
    tree.midOrder();
    cout << endl;
    tree.postOrder();
    cout << endl;
    tree.printTree('@');
    return 0;
}
