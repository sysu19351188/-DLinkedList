#pragma once
#ifndef NODE_H
#define NODE_H
//#include<iostream>
//using namespace std;

template<class T>
class Node
{
private:
	Node<T>* pred;                   //ָ��ǰ������ָ��
	Node<T>* succ;                   //ָ���̽���ָ��
public:
	T date;
	Node() { date = 0; pred = succ = 0; }
	Node(const T& date, Node<T>* succ = 0, Node<T>* pred = 0);
	void insertAfter(Node<T>* p);      //�ڱ����֮�����һ��ͬ����p
	void insertBefore(Node<T>* p);     //�ڱ����֮ǰ����һ��ͬ����p
	Node<T>* succNode();               //��ȡ��̽ڵ�ĵ�ַ
	Node<T>* predNode();               //��ȡǰ���ڵ�ĵ�ַ
	Node<T>& operator=(const Node<T>& N);
};

template<class T>
Node<T>::Node(const T& date, Node<T>* succ, Node<T>* pred )
{
	this->date = date;
	this->pred=pred;
	this->succ = succ;
}

template<class T>
void Node<T>::insertAfter(Node<T>* p)
{
	p->succ = succ;
	succ = p;
	p->pred = this;
}

template<class T>
void Node<T>::insertBefore(Node<T>* p)
{
	p->pred = pred;
	p->succ = this;
	pred = p;
}

template<class T>
Node<T>& Node<T>::operator=(const Node<T>& N)
{
	Node<T>A;
	A.pred = N.pred;
	A.succ = N.succ;
	A.date = N.date;
	return A;
}


template<class T>
Node<T>* Node<T>::predNode()               //��ȡ��̽ڵ�ĵ�ַ
{
	return pred;
}

template<class T>
Node<T>* Node<T>::succNode()
{
	return succ;
}


#endif