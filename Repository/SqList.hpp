#ifndef _SqList_hpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAXSIZE 100
#define LIST_INIT_SIZE 100//存储空间的初始分配量
#define LISTINCREMENT 10 //存储空间的分配增量
#define ERROR 0
#define OK 1

typedef int ElemType;
typedef bool Status;
typedef struct
{
    ElemType *elem;//存储空间基址
    int length;//当前长度
    int listsize;//当前分配的存储容量，以sizeof(ElemType)为单位
}SqList;

Status InitList_Sq(SqList &L)
{
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem)return ERROR;
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}//InitList_Sq

Status ListInsert_Sq(SqList &L,int i,ElemType e)
{
    //i的合理范围是i>=1 i<length(L)+1,注意是在第i个元素前插入
    if(i<1 || i>L.length+1)return ERROR;
    if(L.length >=L.listsize)
    {
        ElemType *newbase = (ElemType *)realloc(L.elem,
                (L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase)return ERROR;
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    ElemType *p,*q;
    q = &(L.elem[i-1]);
    for(p = &(L.elem[L.length-1]);p >=q;--p)//注意指针的加减操作含义与值的加减操作的不同
        *(p+1) = *p;
    *q = e;
    ++L.length;
    return OK;
}//ListInsert_Sq

Status ListDelete_Sq(SqList &L,int i,ElemType &e)
{
    //i的合理范围为i>=1,i<=length(L)
    if(i<1 || i>L.length)return ERROR;
    ElemType *p,*q;
    p = &L.elem[i-1];
    e = *p;
    q = L.elem+L.length-1;
    for(++p;p<=q;++p)
        *(p-1) = *p;
    --L.length;
    return OK;
}//ListDelete_Sq

Status CreateList_Sq(SqList &L,int n)
{
    //n合理范围是n>=1,<=L.listsize
    if(n<1)return ERROR;
    if(n>L.listsize)
    {
        ElemType *newbase = (ElemType *)realloc(L.elem,
                (L.listsize + LISTINCREMENT)
                *sizeof(ElemType));
        if(!newbase)return ERROR;
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    else
        InitList_Sq(L);
    ElemType *p;
    int i;
    p = L.elem;
    for(i = 0;i <= n;++i)
    {
        cout << "input the " << i+1 << "value: "<< endl;
        cin >> *p++;
        ++L.length;
    }
    return OK;
}
void PrintList_Sq(SqList L)
{
    ElemType *p;
    p = L.elem;
    while(p)
        cout << *p++ << endl;
}

#endif
