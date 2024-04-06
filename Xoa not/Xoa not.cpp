#include<iostream>
using namespace std;

struct Node
{
	int Info;
	Node* next;
};

struct List
{
	Node* Head;
	Node* Tail;
};

void createList(List& l)
{
	l.Head = NULL;
	l.Tail = NULL;
}

Node* createNode(int x)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "cap phat bo nho that bai";
		return NULL;
	}
	p->Info = x;
	p->next = NULL;
	return p;
}

void addHead(List& l, Node* p)
{
	if (l.Head == NULL)
		l.Head = l.Tail = p;
	else
		p->next = l.Head;
	l.Head = p;
}

void addTail(List& l, Node* p)
{
	if (l.Head == NULL)
		l.Head = l.Tail = p;
	else
		l.Tail->next = p;
	l.Tail = p;
}

void deleteHead(List& l)
{
	if (l.Head == NULL)
		return;
	Node* p = l.Head;
	l.Head = l.Head->next;
	delete(p);
	if (l.Head == NULL)//th danh sách chỉ có 1 nút
		l.Head = NULL;// cập nhật lại nếu không danh sách sẽ bị xóa.
}

void deleteTail(List& l)
{
	if (l.Head == NULL)
		return;
	if(l.Head->next==NULL)
	{ 
		l.Head = l.Tail = NULL;//trường hợp dslk chỉ có 1 nút
	}
	for (Node* k = l.Head; k != NULL; k = k->next)
	{
		if (k->next == l.Tail)
		{
			delete(l.Tail);
			k->next = NULL;
			l.Tail = k;
		}
	}
}

void deleteAfterNode(List& l, Node* q)
{
	if (q != NULL)
	{
		Node* temp = q->next;
		if (temp == NULL)
			return;
		if (temp == l.Tail)
		{
			delete(l.Tail);
			l.Tail = temp;
		}
		else
		{
			q->next = q->next->next;
			delete temp;
		}
	}
}

void deleteAt(List& l, Node* p, int k)
{
	for (int i = 0; i < k - 1; i++)
	{
		p = p->next;
	}
	Node* temp = p->next;
	p->next = p->next->next;
	delete(temp);
	if (p->next=NULL)
		l.Tail = temp;
	return;
}

void Xuat(List& l)
{
	for (Node* k = l.Head; k != NULL; k = k->next)
	{
		cout << k->Info << " ";
	}
}


int main()
{
	int n, x, k;
	cin >> n;
	List l;
	createList(l);
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		Node* p = createNode(x);
		addTail(l, p);
	}
	cout << "Danh sach lien ket vua nhap la: ";
	Xuat(l);
	cout << "Nhap vi tri can xoa: ";
	cin >> k;
	Node* p = l.Head;
	deleteAt(l, p, k);
	cout << endl;
	Xuat(l);
}