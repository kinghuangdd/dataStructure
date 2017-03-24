#ifndef _SL_hpp
#define _SL_hpp

#include <iostream>
#include <vector>

using namespace std;

#define MAXSIZE 1000

typedef struct
{
    char data;
    int cur;
}component,SLinkList[MAXSIZE];

//将一维数组各分量链成一个备用链表，space[0].cur为头指针
void InitSpace_SL(SLinkList &space)
{
    for(int i = 0;i < MAXSIZE-1;++i)
        space[i].cur = i+1;
    space[MAXSIZE-1].cur = 0;
}

int Malloc_SL(SLinkList &space)
{
    int i = space[0].cur;//将当前备用链表的第一个结点的下标值给i
    //判断条件为space[0].cur为真，即它不为0时执行if下操作，
    //space[0].cur为0是表示备用链表为空,此时i值为0.
    if(space[0].cur)
        space[0].cur = space[i].cur;
    return i;
}

void Free_SL(SLinkList &space,int k)
{
    space[k].cur = space[0].cur;
    space[0].cur = k;//注意，k是结点的下标
}

#endif
