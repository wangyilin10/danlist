#include<iostream>
#include"qgdanlist.h"
int main()
{
	menu();
	cout << "��������δ��������������1��" << endl;
	int choice;
	QGForwardList<int> intlist;
	while (cin >> choice)
	{
		switch (choice)
		{
		case 0:
			return 0;
		case 1:
		{
			intlist.Init();
			int n, i, x;
			cout << "��������Ҫ��������Ԫ�ص�������" << endl;
			cin >> n;
			cout << "�����������е�Ԫ�أ�";
			for (i = 0; i < n; i++)
			{
				cin >> x;
				intlist.push_back(x);
			}
			cout << "���������ɹ���" << endl;

			break;
		}
		case 2:
		{
			intlist.destory();
			cout << "�����������١�" << endl;
			break;
		}
		case 3:
		{
			int b;
			b = intlist.front();
			cout << "������ĵ�һ��Ԫ���ǣ�" << b << endl;
			break;
		}
		case 4:
		{
			int b;
			b = intlist.back();
			cout <<"����������һ��Ԫ���ǣ�"<< b << endl;
			break;
		}
		case 5:
		{
			cout << "������Ҫ��������λ��Ԫ�����ݣ�" << endl;
			int c;
			cin >> c;
			intlist.push_front(c);
			cout << "��Ԫ���Ѳ���������λ��" << endl;
			break;
		}
		case 6:
		{
			intlist.pop_front();
			cout << "��ɾ������ĵ�һ��Ԫ�ء�" << endl;
			break;
		}
		case 7:
		{
			cout << "������Ҫ����������β����Ԫ�����ݣ�" << endl;
			int c;
			cin >> c;
			intlist.push_back(c);
			cout << "��Ԫ���Ѳ�������β����" << endl;
			break;
		}
		case 8:
		{
			intlist.pop_back();
			cout << "��ɾ���������һ��Ԫ�ء�" << endl;
			break;
		}
		case 9:
		{
			cout << "�ڵ�mλ������Ԫ��n��������m��n��" << endl;
			unsigned int m; int n;
			cin >> m >> n;
			intlist.insert(m, n);
			cout << "���ڵ�" << m << "λԪ�غ����Ԫ��" << n << endl;
			break;
		}
		case 10:
		{
			cout << "������Ҫɾ���ڼ�λԪ�أ�" << endl;
			unsigned int b;
			cin >> b;
			intlist.erase(b);
			cout << "��Ԫ����ɾ����" << endl;
			break;
		}
		case 11:
		{
			intlist.clear();
			cout << "����ո�����" << endl;
			break;
		}
		case 12:
		{
			cout << "��������Ҫ���ҵ�Ԫ�أ�" << endl;
			int b;
			cin >> b;
			intlist.contain(b);
			break;
		}
		case 13:
		{
			cout << "�������к��е�Ԫ������Ϊ��" << intlist.size() << endl;
			break;
		}
		case 14:
		{
			intlist.traverse(visit);
			break;

		}
		case 15:
		{
			intlist.reverse();
			cout << "�������ѷ�ת��" << endl;
			break;
		}
		case 16:
		{
			bool b = intlist.isLoop();
			if (b)
			{
				cout << "���������л���" << endl;
			}
			else
			{
				cout << "���������޻���" << endl;
			}
			break;
		}
		case 17:
		{
			intlist.reverseEven();
			cout << "����������ż����ѷ�ת��" << endl;
			break;
		}
		case 18:
		{
			int c = intlist.middleElem();
			cout << "��������м���Ϊ��" << c << endl;
			break;
		}
		}
		cout << "��������һ��Ҫ�������������ţ�" << endl;
	}
	/*QGForwardList<int> intlist;
	int n, i, x;
	cin >> n;
	Node<int>* head, * p, * tail;
	head = tail = intlist.InitList();
	for (i = 0; i < n; i++)
	{
		cin >> x;
		p = intlist.ApplyNode(x);
		tail->next = p;
		tail = p;
	}
	intlist.traverse(visit);
	/*int b;
	b = intlist.front();
	cout << b << endl;
	b = intlist.back();
	cout << b << endl;
	int c;
	cin >> c;
	intlist.push_front(c);
	intlist.traverse(visit);
	intlist.pop_front();
	intlist.traverse(visit);
	int c;
	cin >> c;
	intlist.push_back(c);
	intlist.traverse(visit);
	intlist.pop_back();
	int c; unsigned int b;
	cin >> b;
	intlist.erase(b);
	intlist.traverse(visit);
	intlist.clear();
	intlist.traverse(visit);
	int b;
	cin >> b;
	intlist.contain(b);
	cout << intlist.size() << endl;
	intlist.reverse();
	intlist.traverse(visit);
	bool a = intlist.isLoop();
	cout << a << endl;
	int c = intlist.middleElem();
	cout << c << endl;
	intlist.reverseEven();
	intlist.traverse(visit);*/
	
}