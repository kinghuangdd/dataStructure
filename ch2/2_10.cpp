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
Status DeleteK(sqList &a,int i,int k)
{
    if(i < 1 || i + k > a.length)
        return ERROR;
    for(int j = i+k; j < a.length; j++)
        a.data[j-k] = a.data[j];
    a.length -= k;
    return OK;
}

int main()
{
    int i,k;
    sqList a;
    cout << "please input length :" << endl;
    cin >> a.length;
    for(i = 0;i < a.length;i++)
        a.data[i] = i;
    for(i = 0;i < a.length;i++)
        cout << a.data[i] << " ";
    cout << endl;
    cout << "please input i :" << endl;
    cin >> i;
    cout << "please input k :" << endl;
    cin >> k;
    DeleteK(a, i, k);
    for(int i = 0;i < a.length;i++)
        cout << a.data[i] <<" ";
    cout << endl;
    return 0;

}
