#include <iostream>
#include "seqQueue.h"

using namespace std;

int main()
{
    seqQueue<int> arr;
    for (int i=0;i<7;++i) arr.enQueue(2*i+1);
    cout << arr.getHead() << endl;
    while (! arr.isEmpty()) cout << arr.deQueue() << ' ';
    return 0;
}
