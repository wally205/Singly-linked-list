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

void createList(List& l)
{
	l.Head = NULL;
	l.Tail = NULL;
}

Node* createNode(SinhVien x)
{
	Node* temp = new Node;
	temp->Info.MSSV = x.MSSV;
	strcpy_s(temp->Info.Name, x.Name);
	temp->Info.DTB = x.DTB;
	temp->next = NULL;
	return temp;
}

void addHead(List& l, Node* p)
{
	if (l.Head == NULL)
		l.Head = l.Tail = p;
	else
	{
		p->next = l.Head;
		l.Head = p;
	}
}

void addTail(List& l, Node* p)
{
	if (l.Head == NULL)
		l.Head = l.Tail = p;
	else
	{
		l.Tail->next = p;
		l.Tail = p;
	}
}


void Nhap(SinhVien& x)
{
	cout << "Nhap ma so sinh vien: ";
	cin >> x.MSSV;
	cin.ignore();
	cout << "Nhap ho va ten: ";
	cin.getline(x.Name, 30);
	cout << "Nhap diem trung binh: ";
	cin >> x.DTB;
}

void Xuat(SinhVien x)
{
	cout << "Ma so sinh vien: ";
	cout << x.MSSV;
	cin.ignore();
	cout << "Ho va ten: ";
	cout << x.Name;
	cout << "Diem trung binh: ";
	cout << x.DTB;
}

void inputList(List& l)
{
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		SinhVien s{};
		cout << "Nhap thong tin sinh vien thu " << i+1 << " : " << endl;
		Nhap(s);
		Node* p = createNode(s);
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

void TimKiem(List l)
{
	int x;
	cout << "Nhap mssv can tim: ";
	cin >> x;
	for (Node* k = l.Head; k != NULL; k = k->next)
	{
		if (k->Info.MSSV == x)
			cout << "Tim thay: "<<endl; Xuat(k->Info);
		return;
	}
	cout << "Khong ton tai sinh vien nay";
}

void SapXep(List l)
{

	for (Node* i = l.Head; i != l.Tail; i = i->next)

		for (Node* j = i->next; j != NULL; j = j->next)

			if (i->Info.MSSV > j->Info.MSSV)

				swap(i->Info, j->Info);

}

void ChenThem(List& l)
{
	SinhVien s;
	cout << "Nhap thong tin sinh vien can them: ";
	Nhap(s);
	Node* p = createNode(s);
	if (p->Info.MSSV <= l.Head->Info.MSSV)
		addHead(l, p);
	else if (p->Info.MSSV >= l.Tail->Info.MSSV)
		addTail(l, p);
	else
	{
		Node* r = l.Head;
		Node*q =l.Head->next;
		while (q != NULL)
		{
			if (q->Info.MSSV < p->Info.MSSV)
			{
				r = q;
				q = q->next;
			}
			else
			{
				r->next = p;
				p->next = q;
				break;
			}

		}
	}
}

void deleteHead(List& l)
{
	if (l.Head == NULL)
		return;
	Node* p = l.Head;
	l.Head = l.Head->next;
	delete(p);
}

void deleteTail(List& l)
{
	if (l.Head == NULL)
		return;
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

void XoaSV(List& l)
{
	int x;
	cout << "Nhap mssv can xoa: ";
	cin >> x;
	if (l.Head->Info.MSSV == x)
		deleteHead(l);
	else if (l.Tail->Info.MSSV == x)
		deleteTail(l);
	else
	{
		Node* r = l.Head;
		Node* q = l.Head->next;
		while (q != NULL)
		{
			if (q->Info.MSSV == x)
			{
				r->next = q->next;
				delete(q);
				return;
			}
			r = q;
			q = q->next;
		}

	}

}

int main()
{
	List l;
	createList(l);
	inputList(l);
	printList(l);
	SapXep(l);
	cout << "Danh sach sau khi sap xep la: " << endl;
	printList(l);
	ChenThem(l);
	cout << "Danh sach sau khi them la: " << endl;
	/*XoaSV(l);
	cout << "Danh sach sau khi xoa la: " << endl;
	*/
	printList(l);
	return 0;
}