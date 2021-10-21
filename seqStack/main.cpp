#include <iostream>
#include "seqStack.h"
using namespace std;

int main()
{
    seqStack<int> arr(10);
    for (int i=0;i<7;++i) arr.push(2*i+1);
    cout << arr.pop() << endl;
    cout << arr.top() << endl;
    return 0;
}
