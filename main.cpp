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
	infile1.open("IntegerData.txt");                //打开文件IntegerData.txt
	while (getline(infile1, line))
	{
		cout << line << endl;
		list1.insertAt(line);
	}
	infile2.open("Merge.txt");                       //打开文件Merge.txt
	while (getline(infile2, line))
	{
		cout << line << endl;
		list2.insertAt(line);
	}
	string str = "data5:8";
	cout << "文件IntegerData的数据如下：" << endl;
	list1.show();
	list1.remove(str);
	cout << endl<<"文件IntegerData移除“data5:8”后的数据如下：";
	list1.show();
	list1.reverse();
	cout << endl<< "文件IntegerData反转后的数据如下：";
	list1.show();
	list1.find(str);
	list1.sort();
	cout << endl << "文件IntegerData排序后的数据如下：";
	list1.show();
	list1.merge(list2);
	cout << endl << "文件IntegerData合并文件Merge后的数据如下：";
	list1.show();
	return 0;
}