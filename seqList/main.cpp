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
     //����һ��SeqList��Ķ�������ElemType����Ϊchar��
     //�ռ��СΪ21�������±�Ϊ0������Ԫ���⣬������
     //��20����㡣
	char ctemp;
	int i, n, result;// ����һ���������������� Enter ��Ϊ������־��
    cout << "number of the elements:"<< endl;
    cin >> n;
    cin.get(ctemp);	//  �� Enter ������
    cout << "input the elements:\n" << endl; // ���ַ�������뵽��chlist�У������β��뵽��β��
	for (i=0;i<=n-1;i++) {
        cin.get(ctemp);
        chlist.insert(i,ctemp);
    }
	ctemp = chlist.visit(0); //����׽��.
	chlist.remove(0);
    chlist.insert(chlist.length( )/2, ctemp); // ��ɾ�����׽����뵽�м䡣
	cout << "output the elements:\n" << endl;
    for (i=0;i<chlist.length();i++)
        cout.put(chlist.visit(i));	// ��ȡ��i������ֵ�������
    cout << "\n";
	return 0;
}

