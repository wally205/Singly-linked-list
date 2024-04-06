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
		cout << "Cap phat bo nho that bai";
	}
	p->Info = x;
	p->next = NULL;
	return p;
}

void addHead(List& l, Node* p)
{
	if (l.Head == NULL)
	{
		l.Head = l.Tail = p;
	}
	else
	{
		p->next = l.Head;
		l.Head = p;
	}
}

void addTail(List& l, Node* p)
{
	if (l.Head == NULL)
	{
		l.Head = l.Tail = p;
	}
	else
	{
		l.Tail->next= p;
		l.Tail = p;
	}
}

void Xuat(List l)
{
	for (Node* k = l.Head; k != NULL; k = k->next)
	{
		cout << k->Info << " ";
	}
}

Node* findElement(List l, int x)
{
	Node* p = l.Head;

	while (p != NULL)
	{
		if (p->Info == x)
		{
			return p;  // Trả về phần tử nếu tìm thấy
		}
		p = p->next;
	}

	return NULL;  // Trả về NULL nếu không tìm thấy
}

int main()
{
	int n, x;
	cout << "Nhap so phan tu: ";
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
	int searchValue;
	cout << "\nNhap gia tri can tim: ";
	cin >> searchValue;

	Node* foundElement = findElement(l, searchValue);

	if (foundElement != NULL)
		cout << "Phan tu co gia tri " << searchValue << " duoc tim thay.";
	else
		cout << "Khong tim thay phan tu co gia tri " << searchValue << "." << endl;
	return 0;
}




