#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ERROR 0
#define OK 1
#define Status int
#define maxsize 100
typedef struct
{
    int data[maxsize];
    int length;
}sqList;

//删除线性表中从第i个起的k个元素
Status InsertOrderList(sqList &a,int x)
{
    if(a.length == maxsize)
        return ERROR;
    else
    {
        int i = a.length - 1;
        //用while循环，由于是单调函数，故只需要判断左右两边中的一个大小即可；
        while(i >= 0&& x < a.data[i])
        {
            a.data[i+1] = a.data[i];//判断完之后顺便往后移一个位置
            i--;
        }
        a.data[i+1] = x;
        a.length++;
        return OK;
    }
}

int main()
{
    int i,x;
    sqList a;
    //创建顺序表
    cout << "please input length :" << endl;
    cin >> a.length;
    for(i = 0;i < a.length;i++)
        a.data[i] = i;
    for(i = 0;i < a.length;i++)
        cout << a.data[i] << " ";
    cout << endl;

    cout << "please input x:" << endl;
    cin >> x;
    InsertOrderList(a,x);
    for(int i = 0;i < a.length;i++)
        cout << a.data[i] <<" ";
    cout << endl;
    return 0;

}
