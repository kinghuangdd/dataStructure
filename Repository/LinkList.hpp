#ifndef _LINKLIST_hpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define OK 1;
#define ERROR 0;
#define NOTFOUND 0;

typedef int Status;
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
        cout << "input the " << i << " value :"<< endl;
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
    for(int i = 0 ;i<n;)
    {
        LinkList p = (LinkList)malloc(sizeof(Lnode));
        cout << "input the " << ++i << " value :"<< endl;
        cin >> p->data;
        r->next = p;
        p->next = NULL;
        r = p;
    }
}//CreateList_L

Status Length_L(LinkList L)
{
    int j = 0;
    LinkList p = L;
    while(p->next)
    {
        p = p->next;
        ++j;
    }
    return j;
}
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

Status Locate_L(LinkList L,ElemType x)
{
    LinkList p = L->next;
    int j =1;
    while(p && p->data != x)//***注意必须先判断p是否为空才能判断p->data!=x操作，&&是有先后顺序的！！！！！
    {
        p = p->next;
        ++j;
    }
    if(!p) return NOTFOUND;//j=0表示未找到与x相等的元素
    return j;
}

Status DeleteAndInsertSub(LinkList &la,LinkList &lb,int i,int j,int len)
{//i合理范围为i>0,<=length(la)-len+1;j>0,<length(lb)+1
    int k = 1;
    LinkList p,q,s;
    p = la->next;
    while(p->next && k<i)//***删除判断p->next
    {
        p = p->next;
        ++k;
    }
    if(i<=0 || j<=0 || len <= 0) return ERROR;
    q = p;
    k = 1;
    while(q && k<len)
    {
        q = q->next;
        ++k;
    }
    if(!q)return ERROR;
    s = lb;
    k = 0;
    while(s && k<j-1)//***插入判断s,而不是s->next
    {
        s = s->next;
        ++k;
    }
    if(!s)return ERROR;
    q->next = s->next;
    s->next = p;
    return OK;
}//DeleteAndInsertSub

Status ListDelete_Lsamenode(LinkList &L)
{//***L中元素按递增的顺序排列的
    LinkList p,r,q;
    p = L->next;
    r = L;
    while(p)
    {
        r = p;
        p = p->next;
        if(p && p->data == r->data)
        {
            q = p;
            r->next = p->next;
            p = p->next;
            free(q);
        }
    }
}//ListDelete_Lsamenode

Status ListDelete_L2(LinkList &L,ElemType min,ElemType max)
{//L的元素为有序递增的
    LinkList p,r,q;
    if(min > max)return ERROR;
    p = L->next;
    r = L;
    while(p && p->data < max)
    {
        if(p->data <min)
        {
            r = p;
            p = p->next;
        }
        else
        {
            q = p;
            r->next = p->next;
            p = p->next;
            free(q);
            /*
            q = p;
            p = p->next;
            r->next = p;
            free(q);
            */
        }
    }
    return OK;
}

void Print_L(LinkList L)
{
    LinkList p = L->next;
    cout << "the L data is :" << endl;
    while(p)
    {
        cout << p->data << "  ";
        p = p->next;
    }
    cout << endl;
    cout << "And the length of L is : "<< Length_L(L) <<endl;
}
#endif
