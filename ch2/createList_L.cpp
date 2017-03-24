#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct Lnode
{
    int data;
    struct Lnode *next;
}Lnode,*LinkList;

void createList(LinkList &L,int n)
{
    //逆序输入n个值，建立带头结点得单链线性表L
    L = (LinkList)malloc(sizeof(Lnode));
    L->next = NULL;
    for(int i = n;i>0;--i)
    {
        LinkList p;
        p =(LinkList)malloc(sizeof(Lnode));
        cout << "please input the data :"<<endl;
        cin >> (p->data);
        p->next = L->next;
        L->next = p;
    }

}

void printList(LinkList L)
{
    LinkList p = L->next;
    int i = 0;
    cout << "the L data is :"<<endl;
    while(p)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

int main()
{
    LinkList L;
    int n= 10;
    createList(L,n);
    printList(L);
}

