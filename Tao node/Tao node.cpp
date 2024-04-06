#include<iostream>
using namespace std;

struct Node
{
    int data;
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
    p->data = x;
    p->next = NULL;
    return p;
}

void addHead(List& l, Node* p)
{
    if (l.Head == NULL)//Trường hợp danh sách rỗng
    {
        l.Head = l.Tail = p;
    }
    else
    {
        p->next = l.Head;
        l.Head = p;//Cập nhật lại nút đầu tiên
    }
}

void addTail(List& l, Node* p,int x)
{
    if (l.Head == NULL)//Trường hợp danh sách rỗng
    {
        l.Head = l.Tail = p;
    }
    else
    {
        l.Tail->next = p;
        l.Tail = p;//Cập nhật lại nút cuối 
    }
}


int main()
{
    List l;
    createList(l);
    int n, x;
    cout << "Nhap so phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        Node* p = createNode(x);
        addHead(l, p);
    }
    cout << "Danh sach lien ket vua nhap la: ";
    for (Node* k = l.Head; k != NULL; k = k->next)
    {
        cout << k->data << " ";
    }
    /*cout << "\nNhap gia tri can chen: ";
    cin >> x;
    node* p = createNode(x);
    addTail(l, p);
    cout << "Danh sach lien ket sau khi chen: ";
    for (node* k = l.Head; k != NULL; k = k->next)
    {
        cout << k->data << " ";
    }
    */
}


