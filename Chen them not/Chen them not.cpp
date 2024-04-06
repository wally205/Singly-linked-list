#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

struct List
{
    node* Head;
    node* Tail;
};

void createList(List& l)
{
    l.Head = NULL;
    l.Tail = NULL;
}

node* createNode(int x)
{
    node* p = new node;
    if (p == NULL)
    {
        cout << "Cap phat bo nho that bai";
    }
    p->data = x;
    p->next = NULL;
    return p;
}

void addHead(List& l, node* p)
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

void addTail(List& l, node* p)
{
    if (l.Head == NULL)
    {
        l.Head = l.Tail = p;
    }
    else
    {
        l.Tail->next = p;
        l.Tail = p;
    }
}

void addAt(List& l, node* p, int k, int x)
{

    for (int i = 0; i < k - 1; i++)
    {
        p = p->next;
    }
    node* temp = new node;
    temp->data = x;
    temp->next = p->next;
    p->next = temp;
}


void Xuat(List l)
{
    for (node* k = l.Head; k != NULL; k = k->next)
    {
        cout << k->data << " ";
    }
}


int main()
{
    List l;
    createList(l);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        node* p = createNode(x);
        addTail(l, p);
    }
    cout << "Danh sach lien ket vua nhap la: ";
    Xuat(l);
    int k, y;
    cout << "Nhap vi tri can chen: ";
    cin >> k;
    if (k == 0)
    {
        int y;
        cout << "Nhap gia tri can chen: ";
        cin >> y;
        node* p = createNode(y);
        addHead(l, p);
    }
    else if (k == n-1)
    {
        int y;
        cout << "Nhap gia tri can chen: ";
        cin >> y;
        node* p = createNode(y);
        addTail(l, p);
    } 
    else
    {
        int y;
        cout << "Nhap gia tri can chen: ";
        cin >> y;
        node* p = l.Head;
        addAt(l, p, k, y);
    }
    Xuat(l);
    cout << "\n" << sizeof(l.Tail);
    return 0;
}
