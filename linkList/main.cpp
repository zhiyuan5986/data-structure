#include <iostream>
#include "linkList.h"
using namespace std;

int main()
{
    linkList<int> a;
    for (int i=0;i<7;++i) a.insert(i,2*i+1);
    cout << a.visit(3) << ' ' << a.search(5) << ' ' << a.length() << endl;
    a.insert(5,13);
    a.traverse();
    a.remove(3);
    a.traverse();
    return 0;
}
