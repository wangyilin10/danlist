#ifndef __QGFORWARD_LIST_H__
#define __QGFORWARD_LIST_H__
#include<iostream>
using namespace std;
template <typename T>
class Node {
public:
	/* ��������ڵ�Ķ��� */
	T data; // ��ʾ������
	Node<T>* next;  // ��ʾָ���򣬴洢��һ���ڵ��λ��
	Node<T>* prior;
};


template <class T>
class QGForwardList {
private:
	Node<T>* head;
	Node<T>* tail;
	Node<T>* p;
public:
	/*
	 * ��ʼ������
	 */
	QGForwardList();
	
	bool Init();
	/*
	 * ��������
	 */
	~QGForwardList();

	/*
	 * ������
	 */
	Node<T>* ApplyNode(T x);

	/*
	 * ���������е�һ��Ԫ�ص�����
	 */
	T& front();

	/*
	 * �������������һ��Ԫ�ص�����
	 */
	T& back();

	/*
	 * �������һ��Ԫ��ǰ���Ԫ��e
	 */
	bool push_front(T& e);

	/*
	 * ɾ�������һ��Ԫ��
	 */
	bool pop_front();

	/*
	 * ���������һ��Ԫ�غ����Ԫ��e
	 */
	bool push_back(T& e);

	/*
	 * ɾ���������һ��Ԫ��
	 */
	bool pop_back();


	/*
	 * ������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
	 */
	bool insert(unsigned int index, T& e);

	/*
	 * ɾ������λ��Ԫ��
	 */
	bool erase(unsigned int index);

	/*
	 * �������
	 */
	bool clear();

	/*
	 * �������
	 */
	bool destory();


	/*
	 * ����Ԫ���Ƿ����
	 */
	bool contain(T& e);

	/*
	 * ����������Ԫ�ص�����
	 */
	unsigned int size();

	/*
	 * ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
	 */
	bool traverse(void (*visit)(T& e));

	/*
	 * ��ת����1234��ת����4321
	 */
	bool reverse();

	/*
	 * �����л�
	 */
	bool isLoop();

	/*
	 * ż�ڵ㷴ת��1234��ת����2143
	 */
	bool reverseEven();

	/*
	 * �����м�ڵ�
	 */
	T& middleElem();
};


template<class T>
QGForwardList<T>::QGForwardList()
{
	head = nullptr;
	p = nullptr;
	tail = nullptr;
}

template<class T>
inline bool QGForwardList<T>::Init()
{
	head = new Node<T>;
	head->next = nullptr;
	return true;
}


template<class T>
QGForwardList<T>::~QGForwardList()
{
	destory();
}


//�����㲢��ֵ
template<class T>
Node<T>* QGForwardList<T>::ApplyNode(T x)
{
	p = new Node<T>;
	p->data = x;
	p->next = nullptr;
	return(p);
}



//���������е�һ��Ԫ�ص�����
template <class T>
T& QGForwardList<T>::front()
{
	T& t = head->next->data;
	return t;
}

//�������������һ��Ԫ�ص�����
template <class T>
T& QGForwardList<T>::back()
{
	p = head->next;
	while (p->next != nullptr)
	{
		p = p->next;
	}
	tail = p;
	T& t = tail->data;
	return t;
}

//�������һ��Ԫ��ǰ���Ԫ��e
template <class T>
bool QGForwardList<T> ::push_front(T& e)
{
	if (head == nullptr)
	{
		cout << "����δ��ʼ����" << endl;
		return false;
	}
	else
	{
		Node<T>* p = new Node<T>;
		p->data = e;
		p->next = head->next;
		head->next = p;
		return true;
	}
}

//ɾ������ĵ�һ��Ԫ��
template<class T>
bool QGForwardList<T> ::pop_front()
{
	if (head->next == nullptr)
	{
		cout << "������Ϊ�ա�" << endl;
		return false;
	}
	else
	{
		p = head->next;
		head->next = p->next;
		delete(p);
		return true;
	}
}

// ���������һ��Ԫ�غ����Ԫ��e
template <class T>
bool QGForwardList<T>::push_back(T& e)
{
	if (head == nullptr)
	{
		cout << "����δ��ʼ����" << endl;
		return false;
	}
	else
	{
		Node<T>* q = new Node <T>;
		p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		q->data = e;
		q->next = p->next;
		p->next = q;
		return true;
	}
}

//ɾ����������һ��Ԫ��
template<class T>
bool QGForwardList<T> ::pop_back()
{
	if (head->next == nullptr)
	{
		cout << "������Ϊ�ա�" << endl;
		return false;
	}
	else
	{
		Node<T>* q = nullptr;
		q = head;
		while (q->next != nullptr)
		{
			q = q->next;
		}
		p = head;
		while (p->next != q)
		{
			p = p->next;
		}
		p->next = nullptr;
		delete(q);
		return true;
	}
}

//������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
template<class T>
bool QGForwardList<T> ::insert(unsigned int index, T& e)
{
	if (head == nullptr)
	{
		cout << "����δ��ʼ����" << endl;
		return false;
	}
	else 
	{
		Node<T>* q = new Node <T>;
		q->data = e;
		p = head;
		while (index--)
		{
			p = p->next;
		}
		q->next = p->next;
		p->next = q;
		return true;
	}
}

//ɾ������λ��Ԫ��
template<class T>
bool QGForwardList<T>::erase(unsigned int index)
{
	if (head->next == nullptr)
	{
		cout << "������Ϊ�ա�" << endl;
		return false;
	}
	else
	{
		Node<T>* q = nullptr;
		index--;
		p = head;
		while (index--)
		{
			p = p->next;
		}
		q = p->next;
		p->next = q->next;
		delete(q);
		return true;
	}
}

//�������
template<class T>
bool QGForwardList<T>::clear()
{
	if (head->next == nullptr)
	{
		cout << "������Ϊ�ա�" << endl;
		return false;
	}
	else
	{
		Node<T>* q = nullptr;
		p = head->next;
		while (p->next != nullptr)
		{
			q = p->next;
			delete(p);
			p = q;
		}
		head->next = nullptr;
		p = nullptr;
		tail = nullptr;
		return true;
	}
}

template<class T>
inline bool QGForwardList<T>::destory()
{
	if (head->next == nullptr)
	{
		cout << "������Ϊ�ա�" << endl;
		return false;
	}
	else
	{
		Node<T>* q = nullptr;
		p = head;
		while (p->next != nullptr)
		{
			q = p->next;
			delete(p);
			p = q;
		}
		head = nullptr;
		p = nullptr;
		tail = nullptr;
		return true;
	}
}

//����Ԫ���Ƿ����
template <class T>
bool QGForwardList<T>::contain(T& e)
{
	if (head == nullptr)
	{
		cout << "����δ��ʼ����" << endl;
		return false;
	}
	else
	{
		p = head->next;
		bool a = false;
		while (p != nullptr)
		{
			if (p->data == e)
			{
				a = true;
			}
			p = p->next;
		}
		if (a)
		{
			cout << "Ԫ�ش�����������" << endl;
		}
		else
		{
			cout << "Ԫ�ز�������������" << endl;
		}

		return true;
	}
}

//����������Ԫ�ص�����
template <class T>
unsigned int QGForwardList<T>::size()
{
	p = head->next;
	int counter = 0;
	while (p != nullptr)
	{
		p = p->next;
		counter++;
	}
	return counter;
}


//��������
template <class T>
void visit(T &e)
{
	cout << e << "  ";
}
template<class T>
bool QGForwardList<T>::traverse(void (*visit)(T& e))
{
	if (head == nullptr)
	{
		cout << "����δ��ʼ����" << endl;
		return false;
	}
	else
	{
		p = head->next;
		while (p != nullptr)
		{
			visit(p->data);
			p = p->next;
		}
		cout << endl;
		cout << "������ӡ��ϣ�" << endl;
		return true;
	}
}

//��ת����1234��ת����4321
template<class T>
bool QGForwardList<T>::reverse()
{

	if (head == nullptr)
	{
		cout << "����δ��ʼ����" << endl;
		return false;
	}
	else
	{
		Node<T>* beg = nullptr;
		Node<T>* mid = head->next;
		Node<T>* end = head->next->next;
		while (1)
		{
			mid->next = beg;
			if (end == nullptr)
			{
				break;
			}
			beg = mid;
			mid = end;
			end = end->next;
		}
		head->next = mid;
		return true;
	}
}

//�����л�
template<class T>
bool QGForwardList<T>::isLoop()
{

	if (head == nullptr)
	{
		cout << "����δ��ʼ����" << endl;
		return false;
	}
	else
	{
		Node<T>* slow, * fast;
		slow = fast = head;
		while (fast != nullptr && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
			{
				return true;
			}
		}
		return fast;
	}
}

//ż�ڵ㷴ת��1234��ת����2143
template<class T>
bool QGForwardList<T>::reverseEven()
{

	if (head == nullptr)
	{
		cout << "����δ��ʼ����" << endl;
		return false;
	}
	else
	{
		Node<T>* ji, * ou, * t;
		t = head;
		while (t->next != nullptr && t->next->next != nullptr)
		{
			ji = t->next;
			ou = ji->next;

			t->next = ou;
			ji->next = ou->next;
			ou->next = ji;

			t = ji;
		}
		return true;
	}
}

//����������м�ڵ�
template<class T>
T& QGForwardList<T>::middleElem()
{
	Node<T>* slow, * fast;
	slow = fast = head;
	while (1)
	{
		fast = fast->next;
		if (fast == nullptr)
		{
			break;
		}
		slow = slow->next;
		fast = fast->next;
		if (fast == nullptr)
		{
			break;
		}
	}
	T& a = slow->data;
	return a;
}
void menu();

#endif