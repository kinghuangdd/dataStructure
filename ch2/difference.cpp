#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAXSIZE 1000
typedef struct
{
    char data;
    int cur;
}SLinkList[MAXSIZE];

void InitSpace_SL(SLinkList &space)
{
//将一维数组spac各分量链成一个备用的链表，space[0].cur表示头指针
//0为空指针
    for(int i = 0;i<MAXSIZE-1;++i)
        space[i].cur = i+1;
    space[MAXSIZE-1].cur = 0;
}

int Malloc_SL(SLinkList &space)
{
    int i;
    i = space[0].cur;
    if(space[0].cur)
        space[0].cur = space[i].cur;
    return i;
}//若被用链表非空，返回分配结点的下标，否则返回0

void Free_SL(SLinkList &space,int k)
{//将下标为k的空闲结点回收到备用链表
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

void difference(SLinkList &space,int &S)
{
    int m,n;
    InitSpace_SL(space);
    S = Malloc_SL(space);//S为space的头结点
    int r = S;//r指向当前的最后结点
    cout << "please input A and B number:"<<endl;
    cin >> m >> n;
    //生成A集合链表
    for(int j = 1;j <=m;++j)
    {
        int i = Malloc_SL(space);//分配结点
        cout << "input the A "<< j <<" data" <<endl;
        cin >> space[i].data;
        space[r].cur = i;//插到表尾
        r = i;
    }
    space[r].cur = 0;//表示尾结点，指针为空
    char b;
    //插入B元素
    for(int j = 1;j<=n;++j)
    {
         cout <<"input the B "<<j<<" data" <<endl;
         cin >>b;
         int p = S,k = space[S].cur;//k指向A链表的第一个结点
         while(k!=space[r].cur && space[k].data != b)//在当前表中查找，指的是A表，准确的说r是A的尾指针
         {
             //将k的值给p，k指向下一个值
             p = k;
             k = space[k].cur;
         }
         if(k == space[r].cur)//当前表中没有该元素，插入到表中，space[r].cur表示尾结点
         {
            int i = Malloc_SL(space);
            space[i].data = b;
            space[i].cur = space[r].cur;
            space[r].cur = i;
         }
         else//删除该结点并回收
         {
             space[p].cur = space[k].cur;//此时就晓得p的用处了！！！
             Free_SL(space,k);
             if(r == k)
                 r = p;//若删除的是r结点，需修改尾指针，循环需要！！
         }
    }
}

void Print_SL(SLinkList &space,int S)
{
    int t = S;
    while(t)
    {
        cout << space[t].data << endl;
        t = space[t].cur;
    }
    cout << "that's all!" << endl;
}

int main()
{
    SLinkList space;
    int S;
    difference(space,S);
    Print_SL(space,S);
    return 0;

}
