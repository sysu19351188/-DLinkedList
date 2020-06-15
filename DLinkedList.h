#pragma once
#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#include "Node.h"
#include<iostream>
using namespace std;

template<class T>
class DLinkedList
{
private:
	Node<T>* front, * rear;
	Node<T>* prevPtr, * currPtr;
	int size;                                //����ڵ�����
	int position;                            //��ǰԪ���ڱ��е�λ�����
	Node<T>* NewNode(const T& item, Node<T>* ptrNext = 0);
	void freeNode(Node<T>* p);                //�ͷŽڵ�
	void copy(const DLinkedList<T>& L);
public:
	DLinkedList();
	DLinkedList(const DLinkedList<T>& L);
	~DLinkedList() {};
	DLinkedList<T>& operator=(const DLinkedList& L);
	void init();                               //��ʼ������
	bool empty();                              //�пղ���
	Node<T> remove(T p);                 //ɾ������,���ر�ɾ���Ľڵ�
	Node<T> first();                           //�����׽ڵ�
	Node<T> last();                            //����ĩ�ڵ�
	void insertAsFirst(const T& item);         //ǰͷ�ڵ�������
	void insertAsLast(const T& item);          //��β�ڵ�������
	void insertAt(const T& item);              //������ڵ�
	void next();
	void reset(int pos);
	Node<T> find(T d);                         //���Ҳ���
	void sort();                               //��date��С����
	void reverse();                            //����ת
	void merge(DLinkedList<T> L);              //�ϲ���һ��������
	void show();                               //������ӡ����
	void clear();
};


template <class T> 
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList<T>& L)
{
	if (this == &L)
		return *this;
	clear();
	copy(L);
	return *this;
}

template <class T> 
void DLinkedList<T>::copy(const DLinkedList<T>& L)
{
	Node<T>* p = L.front;
	int pos;
	while (p != NULL)
	{
		insertRear(p->data);
		p = p->nextNode();
	}
	if (position == -1)
		return;
	prevPtr = NULL;
	currPtr = front;
	for (pos = 0; pos != position; pos++)
	{
		prevPtr = currPtr;
		currPtr = currPtr->nextNode();
	}
}

template<class T>
Node<T>* DLinkedList<T>::NewNode(const T& item, Node<T>* ptrNext)
{
	Node<T>* newNode;
	newNode = new Node<T>(item, ptrNext);
		return newNode;
}

template<class T>
DLinkedList<T>::DLinkedList()
{
	front =rear=NULL;
	prevPtr = currPtr = front;
	size = 0;
	position = -1;
}

template<class T>
DLinkedList<T>::DLinkedList(const DLinkedList<T>& L)
{
	front = L.front;
	rear = L.rear;
	prevPtr = L.prePtr;
	currPtr = L.currPtr;
	size = L.size;
	position = L.position;
}

template<class T>
void DLinkedList<T>::init()
{
	front = rear = NULL;
	prevPtr = currPtr = front;
	size = 0;
	position = 0;
}

template<class T>
bool DLinkedList<T>::empty()
{
		return (size==0);
}

template<class T>
Node<T> DLinkedList<T>::remove(T p)
{
	currPtr = front;
	while (currPtr != 0)
	{
		if (currPtr->date == p)
		{
			currPtr->pred->succ = currPtr->succ;
			delete currPtr;

		}currPtr = currPtr->succNode;
	}
	return p;
}

template<class T>
Node<T> DLinkedList<T>::first()
{
	return front;
}

template<class T>
Node<T> DLinkedList<T>::last()                            //����ĩ�ڵ�
{
	return rear;
}

template<class T>
void DLinkedList<T>::next()
{
	position++;
	prevPtr = currPtr;
	if (currPtr != 0)
		currPtr = currPtr->succNode();
}

template<class T>
void DLinkedList<T>::reset(int pos)
{
	if (0 <= pos && pos <= size)
	{
		position = 0;
		prevPtr = nullptr;
		currPtr = front;                      //�α귵��ͷ�ڵ㣬����ǰ��
		while (pos--)
			next();
	}
	else
	{
		position = pos;
		prevPtr = nullptr;
		currPtr = nullptr;
	}
}

template<class T>
void DLinkedList<T>::insertAsFirst(const T& item)                      //ǰ��������
{
	front = NewNode(item, front);
	if (empty())
		rear = front;
	size++;
}

template<class T>
void DLinkedList<T>::insertAsLast(const T& item)                       //���������
{
	Node<T>* newnode = NewNode(item);
	if (empty())
		front = rear = newnode;
	else
	{
		rear->insertAfter(newnode);
		rear = newnode;
	}
	size++;
}

template<class T>
void DLinkedList<T>::insertAt(const T& item)
{
	Node<T>* nNode;
	if (prevPtr == 0)
	{
		nNode = NewNode(item, front);
		front = nNode;
	}
	else
	{
		nNode = NewNode(item);
		currPtr-> insertAfter(nNode);
	}
	currPtr = nNode;
	size++;
}

template<class T>
Node<T> DLinkedList<T>::find(T d)                            //���Ҳ���
{
	currPtr = front;
	while (currPtr != 0)
	{
		if (currPtr->date == d)
		{
			return currPtr;
			break;
		}
		else
			currPtr = currPtr->succNode;
	}
}

template<class T>
void DLinkedList<T>::sort()                               //��date��С����
{
	Node<T>* p;
	T t;
	p= front;
	for (int i = 0; i < size; i++)
	{
		currPtr = p->succNode;
		for (int j = i + 1; j<size;j++)
		{
			if (p->date > currPtr->date)
			{
				t = p->date;
				p->date = currPtr->date;
				currPtr->date = t;
			}
			currPtr = currPtr->predNode;
		}
		p = p->succNode;
	}
}

template<class T>
void DLinkedList<T>::reverse()                            //����ת
{
	Node<T> *p1,*p2,*p3,*p4;
	T t;
	if (size % 2 == 0)
	{
		p1 = front->succNode;                       //�Ƚ�����β
		p2 = front;
		front->predNode = rear->predNode;
		front = rear;
		rear->succNode = p1;
		rear = front;
		currPtr = front->succNode;                //currPtr������λ��ǰ��Ҫ�滻��
		p4 = rear->predNode;                      //p4������λ������Ҫ�滻��
		for (int i = 1; i < (size / 2); i++)
		{
			p1 = currPtr->predNode;
			p2 = currPtr->succNode;
			p3 = currPtr;
			currPtr->predNode=p4->predNode;
			currPtr->succNode=p4->succNode;
			currPtr=p4;
			p4->predNode=p1;
			p4->succNode=p2;
			p4=p3;                                //һ���滻���
			currPtr = p4->succNode;
			p4 = currPtr->predNode;
		}	
	}
	if (size % 2 == 1)
	{
		p1 = front->succNode;                       //�Ƚ�����β
		p2 = front;
		front->predNode = rear->predNode;
		front = rear;
		rear->succNode = p1;
		rear = front; 
		currPtr = front->succNode;                //currPtr������λ��ǰ��Ҫ�滻��
		p4 = rear->predNode;                      //p4������λ������Ҫ�滻��
		for (int i = 1; i < (size - 1) / 2; i++)
		{
			p1 = currPtr->predNode;
			p2 = currPtr->succNode;
			p3 = currPtr;
			currPtr->predNode = p4->predNode;
			currPtr->succNode = p4->succNode;
			currPtr = p4;
			p4->predNode = p1;
			p4->succNode = p2;
			p4 = p3;                                //һ���滻���
			currPtr = p4->succNode;
			p4 = currPtr->predNode;
		}
	}
}

template <class T>
void DLinkedList<T>::clear()
{
	Node<T>* currPosition, * nextPosition;
	currPosition = front;
	while (currPosition != NULL)
	{
		nextPosition = currPosition->nextNode();
		freeNode(currPosition);
		currPosition = nextPosition;
	}
	front = rear = NULL;
	prevPtr = currPtr = NULL;
	size = 0;
	position = -1;
}


template<class T>
void DLinkedList<T>::merge(DLinkedList<T> L)         //�ϲ���һ��������
{
	rear->succNode = L.front;
	rear = L.rear;
	size = size + L.size;
}

template<class T>
void DLinkedList<T>::show()                               //������ӡ����
{
	currPtr = rear;
	for (int i = 0; i < size;i++)
	{
		cout <<currPtr->date<<endl;
		currPtr = currPtr->succNode();
	}
}


#endif