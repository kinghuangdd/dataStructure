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
        p->next =  L->next;
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
    LinkList La,Lb,Lc;
    LinkList pa,pb,pc;
    Lc = (LinkList)malloc(sizeof(Lnode));
    Lc->next = NULL;
    int i,j;
    cout << "please input the La length i : ";
    cin >> i;
    cout << "please input the La length j : ";
    cin >> j;
    cout << "now we create List La,Lb:" <<endl;
    createList(La,i);
    createList(Lb,j);
//归并La、Lb得到一个新的链表Lc
    pa = La->next;
    pb = Lb->next;
    Lc = pc = La;//用La得头结点作为Lc的头结点
    while(pa && pb)
    {
        if(pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa:pb;
    free(Lb);
    printList(Lc);
}

