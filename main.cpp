#include "Node.h"
#include "DLinkedList.h"
#include <fstream>
#include <sstream>
#include <cassert>
#include <string>

int main()
{
	//Node<int>node;
	DLinkedList<string>list1,list2;
	ifstream infile1,infile2;
	string line;
	infile1.open("IntegerData.txt");                //���ļ�IntegerData.txt
	while (getline(infile1, line))
	{
		cout << line << endl;
		list1.insertAt(line);
	}
	infile2.open("Merge.txt");                       //���ļ�Merge.txt
	while (getline(infile2, line))
	{
		cout << line << endl;
		list2.insertAt(line);
	}
	string str = "data5:8";
	cout << "�ļ�IntegerData���������£�" << endl;
	list1.show();
	list1.remove(str);
	cout << endl<<"�ļ�IntegerData�Ƴ���data5:8������������£�";
	list1.show();
	list1.reverse();
	cout << endl<< "�ļ�IntegerData��ת����������£�";
	list1.show();
	list1.find(str);
	list1.sort();
	cout << endl << "�ļ�IntegerData�������������£�";
	list1.show();
	list1.merge(list2);
	cout << endl << "�ļ�IntegerData�ϲ��ļ�Merge����������£�";
	list1.show();
	return 0;
}