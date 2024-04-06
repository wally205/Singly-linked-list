#include<iostream>
#include<cmath>
using namespace std;

struct DaThuc
{
	int x;
	int i;
	DaThuc* next;
};

class List
{
private:
	DaThuc* Head;
	DaThuc* Tail;
public:
	void createList()
	{
		Head = NULL;
		Tail = NULL;
	}
	DaThuc* createDaThuc(int x, int i)
	{
		DaThuc* temp = new DaThuc;
		temp->x = x;
		temp->i = i;
		temp->next = NULL;
		return temp;
	}
	void addTail( DaThuc* p)
	{
		if (Head == NULL)
			Head = Tail = p;
		else
		{
			Tail->next = p;
			Tail = p;
		}
	}

	double Sum()
	{
		double sum = 0;
		for (DaThuc* k = Head; k != NULL; k=k->next)
		{
			sum += pow(k->x, k->i);
		}
		return sum;
	}
	
	void printList()
	{
		cout << "Da thuc la: ";
		DaThuc* p =Head;
		while (p != NULL)
		{
			if (p->next != NULL)
				cout << p->x << "^" << p->i << "+";
			else
				cout << p->x << "^" << p->i;
			p = p->next;
		}
	}
};

int main()
{
	List l;
	l.createList();
	int n, x;
	cout << "Nhap so phan tu cua da thuc: ";
	cin >> n;
	cout << "Nhap co so: ";
	cin >> x;
	for (int i = 1; i <= n; i++)
	{
		DaThuc* p = l.createDaThuc(x, i);
		l.addTail(p);
	}
	l.printList();
	double result = l.Sum();
	cout << "\nTong cua da thuc la: " << result;
}
