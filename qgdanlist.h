#ifndef __QGFORWARD_LIST_H__
#define __QGFORWARD_LIST_H__
#include<iostream>
using namespace std;
template <typename T>
class Node {
public:
	/* 用于链表节点的定义 */
	T data; // 表示数据域
	Node<T>* next;  // 表示指针域，存储下一个节点的位置
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
	 * 初始化链表
	 */
	QGForwardList();
	
	bool Init();
	/*
	 * 销毁链表
	 */
	~QGForwardList();

	/*
	 * 申请结点
	 */
	Node<T>* ApplyNode(T x);

	/*
	 * 返回链表中第一个元素的引用
	 */
	T& front();

	/*
	 * 返回链表中最后一个元素的引用
	 */
	T& back();

	/*
	 * 在链表第一个元素前添加元素e
	 */
	bool push_front(T& e);

	/*
	 * 删除链表第一个元素
	 */
	bool pop_front();

	/*
	 * 在链表最后一个元素后添加元素e
	 */
	bool push_back(T& e);

	/*
	 * 删除链表最后一个元素
	 */
	bool pop_back();


	/*
	 * 在链表的第index + 1个元素前插入元素e
	 */
	bool insert(unsigned int index, T& e);

	/*
	 * 删除任意位置元素
	 */
	bool erase(unsigned int index);

	/*
	 * 清空链表
	 */
	bool clear();

	/*
	 * 清空链表
	 */
	bool destory();


	/*
	 * 查找元素是否存在
	 */
	bool contain(T& e);

	/*
	 * 返回链表中元素的数量
	 */
	unsigned int size();

	/*
	 * 遍历链表, 对每个元素调用visit指向的函数
	 */
	bool traverse(void (*visit)(T& e));

	/*
	 * 反转链表，1234反转后变成4321
	 */
	bool reverse();

	/*
	 * 链表判环
	 */
	bool isLoop();

	/*
	 * 偶节点反转，1234反转后变成2143
	 */
	bool reverseEven();

	/*
	 * 返回中间节点
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


//申请结点并赋值
template<class T>
Node<T>* QGForwardList<T>::ApplyNode(T x)
{
	p = new Node<T>;
	p->data = x;
	p->next = nullptr;
	return(p);
}



//返回链表中第一个元素的引用
template <class T>
T& QGForwardList<T>::front()
{
	T& t = head->next->data;
	return t;
}

//返回链表中最后一个元素的引用
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

//在链表第一个元素前添加元素e
template <class T>
bool QGForwardList<T> ::push_front(T& e)
{
	if (head == nullptr)
	{
		cout << "链表未初始化。" << endl;
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

//删除链表的第一个元素
template<class T>
bool QGForwardList<T> ::pop_front()
{
	if (head->next == nullptr)
	{
		cout << "该链表为空。" << endl;
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

// 在链表最后一个元素后添加元素e
template <class T>
bool QGForwardList<T>::push_back(T& e)
{
	if (head == nullptr)
	{
		cout << "链表未初始化。" << endl;
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

//删除链表的最后一个元素
template<class T>
bool QGForwardList<T> ::pop_back()
{
	if (head->next == nullptr)
	{
		cout << "该链表为空。" << endl;
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

//在链表的第index + 1个元素前插入元素e
template<class T>
bool QGForwardList<T> ::insert(unsigned int index, T& e)
{
	if (head == nullptr)
	{
		cout << "链表未初始化。" << endl;
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

//删除任意位置元素
template<class T>
bool QGForwardList<T>::erase(unsigned int index)
{
	if (head->next == nullptr)
	{
		cout << "该链表为空。" << endl;
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

//清空链表
template<class T>
bool QGForwardList<T>::clear()
{
	if (head->next == nullptr)
	{
		cout << "该链表为空。" << endl;
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
		cout << "该链表为空。" << endl;
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

//查找元素是否存在
template <class T>
bool QGForwardList<T>::contain(T& e)
{
	if (head == nullptr)
	{
		cout << "链表未初始化。" << endl;
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
			cout << "元素存在于链表当中" << endl;
		}
		else
		{
			cout << "元素不存在于链表当中" << endl;
		}

		return true;
	}
}

//返回链表中元素的数量
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


//遍历链表
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
		cout << "链表未初始化。" << endl;
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
		cout << "遍历打印完毕！" << endl;
		return true;
	}
}

//反转链表，1234反转后变成4321
template<class T>
bool QGForwardList<T>::reverse()
{

	if (head == nullptr)
	{
		cout << "链表未初始化。" << endl;
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

//链表判环
template<class T>
bool QGForwardList<T>::isLoop()
{

	if (head == nullptr)
	{
		cout << "链表未初始化。" << endl;
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

//偶节点反转，1234反转后变成2143
template<class T>
bool QGForwardList<T>::reverseEven()
{

	if (head == nullptr)
	{
		cout << "链表未初始化。" << endl;
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

//返回链表的中间节点
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