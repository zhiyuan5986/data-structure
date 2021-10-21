#include <iostream>
#include "seqList.h"
#include "seqList.cpp"
using namespace std;

//int main()
//{
//    seqList<int> a(15);
//    for (int i=0;i<20;++i) a.insert(i,i);
//    std::cout << a.length() << std::endl;
//    a.remove(3);
//    std::cout << a.search(6) <<std::endl;
//    std::cout << a.visit(8) << std::endl;
//    a.traverse();
//    return 0;
//}

int main() {
	seqList<char> chlist(21);
     //定义一个SeqList类的对象，其中ElemType定义为char，
     //空间大小为21，即除下标为0的数组元素外，最多可以
     //放20个结点。
	char ctemp;
	int i, n, result;// 输入一个正整数，并输入 Enter 作为结束标志。
    cout << "number of the elements:"<< endl;
    cin >> n;
    cin.get(ctemp);	//  将 Enter 抛弃。
    cout << "input the elements:\n" << endl; // 将字符逐个输入到表chlist中，并依次插入到表尾。
	for (i=0;i<=n-1;i++) {
        cin.get(ctemp);
        chlist.insert(i,ctemp);
    }
	ctemp = chlist.visit(0); //获得首结点.
	chlist.remove(0);
    chlist.insert(chlist.length( )/2, ctemp); // 将删除的首结点插入到中间。
	cout << "output the elements:\n" << endl;
    for (i=0;i<chlist.length();i++)
        cout.put(chlist.visit(i));	// 读取第i个结点的值并输出。
    cout << "\n";
	return 0;
}

