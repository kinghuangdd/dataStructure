#ifndef _LINKLIST_hpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define OK 1;
#define ERROR 0;

typedef bool Status;
typedef int ElemType;

typedef struct Lnode
{
    ElemType data;
    struct Lnode *next;
}Lnode,*LinkList;

void CreateList_headL(LinkList &L,int n)
{//头插法
    L = (LinkList)malloc(sizeof(Lnode));
    L->next = NULL;
    for(int i = n;i>0;--i)
    {
        LinkList p = (LinkList)malloc(sizeof(Lnode));
        cout << "input L " << i+1 << "value :"<< endl;
        cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}//CreateList)L

void CreateList_L(LinkList &L,int n)
{
    L = (LinkList)malloc(sizeof(Lnode));
    L->next = NULL;
    LinkList r = L;
    for(int i = n;i>0;--i)
    {
        LinkList p = (LinkList)malloc(sizeof(Lnode));
        cout << "input L " << i+1 << "value :"<< endl;
        cin >> p->data;
        r->next = p;
        p->next = NULL;
        r = p;
    }
}//CreateList_L

Status GetElem_L(LinkList L,int i,ElemType &e)
{//i的合理范围是i>0,<length(L)
    LinkList p = L->next;
    int j = 1;
    while(p && j<i)
    {
        p = p->next;
        ++j;
    }
    if(!p || j>i)return ERROR;//第i个元素不存在！!p保证i<length,j>i保证i取零
    e = p->data;
    return OK;
}//GetElem_L

Status ListInsert_L(LinkList &L,int i,ElemType e)
{//i的合理范围是i>0,i<length(L)+1
    LinkList p = L;
    int j =0;
    while(p && j<i-1)
    {
        p = p->next;
        ++j;
    }
    if(!p || j>i-1)return ERROR;//i小于1或者大于表长+1
    LinkList q = (LinkList)malloc(sizeof(Lnode));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return OK;
}//ListInsert_L

Status ListDelete_L(LinkList &L,int i,ElemType &e)
{//i合理范围为i>1,<length(L)
    LinkList p = L;
    int j = 0;
    while(p->next && j<i-1)
    {
        p = p->next;
        ++j;
    }
    if(!p->next || j>i-1)return ERROR;//找到删除结点的前一个结点
    LinkList q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return OK;
}//ListDelete_L

#endif
