#include <iostream>
#include "linkQueue.h"

using namespace std;

int main()
{
    int length=0;
    linkQueue<int> arr;
    cout << arr.isEmpty() << endl;
    for (int i=0;i<7;++i) arr.enQueue(2*i+1);
    cout << arr.isEmpty() <<endl;
    while (! arr.isEmpty()) {length++;cout << arr.deQueue() << ' ';}
    cout << endl << length;
    return 0;
}
