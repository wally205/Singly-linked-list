#include<iostream>
#include<string>
using namespace std;

struct SinhVien
{
	int MSSV;
	char Name[30];
	float DTB;
};

struct Node
{
	SinhVien Info;
	Node* next;
};

struct List
{
	Node* Head;
	Node* Tail;
};

void createList(List&l)
{
	l.Head = NULL;
	l.Tail = NULL;
}

Node* createNode(SinhVien x)
{
	Node* temp = new Node;
	temp->Info.MSSV = x.MSSV;
	strcpy(temp->Info.Name, x.Name);
	temp->next = NULL;
	return temp;
}

void addTail(List& l,Node*p)
{
	if (l.Head == NULL)
		l.Head = l.Tail = p;
	else
	{
		l.Tail->next = p;
		l.Tail = p;
	}
}

void Nhap(SinhVien x)
{
	cout << "Nhap ma so sinh vien: ";
	cin >> x.MSSV;
	cout << "Nhap ho va ten: ";
	cin.getline(x.Name, 30);
	cout << "Nhap diem trung binh";
	cin >> x.DTB;
}

void inputList(List& l)
{
	int n;
	SinhVien s;
	cout << "Nhap so luong sinh vien: ";
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin sinh vien thu " << i << " : ";
		Nhap(s);
		Node*p=createNode(s);
		addTail(l, p);
	}
}

void printList(List l)
{
	for (Node* k = l.Head; k != NULL; k = k->next)
	{
		cout << "Sinh vien: " << k->Info.Name << ",MSSV:  " << k->Info.MSSV << ", DTB: " << k->Info.DTB << endl;
	}
}

int main()
{
	List l;
	createList(l);
	inputList(l);
	printList(l);
	return 0;
}