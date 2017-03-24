#include <iostream>
#include <string>
#include <vector>
#define MAXSIZE 100

using namespace std;

typedef struct
{
    char data[MAXSIZE];
    int length;
}SqList;

int main()
{
    SqList a,b;
    int i = 0,j = 0,k;
// 创建a、b顺序表
    cout << "please input the a.length ：" << endl;
    cin >> a.length;
    cout << "please input the b.length : " << endl;
    cin >> b.length;
    while(i < a.length)
    {
        cout << "please input a.data value :" << endl;
        cin >> a.data[i];
        i++;
    }
    cout << a.data << endl;

    while(j < b.length)
    {
        cout << "please input b.data value :" << endl;
        cin >> b.data[j];
        j++;
    }
    cout << b.data << endl;

    if(a.length < b.length)
        cout << "a < b" << endl;
    else if(a.length > b.length)
        cout << "a > b" << endl;
    else if(a.length = b.length)
    {
        for(k = 0;k < a.length;k++)
        {
            if(a.data[k] > b.data[k])
                cout << "a > b" << endl;
            else if(a.data[k] < b.data[k])
                cout << "a < b" << endl;
        }
        if(k = a.length)
            cout << "a = b" << endl;

    }
    return 0;
}
