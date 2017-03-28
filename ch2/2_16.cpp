#include "../Repository/LinkList.hpp"

int main()
{
    LinkList la,lb;
    int m,n;
    cout << "create la :"<<endl;
    cin >> m;
    CreateList_L(la,m);
    cout << "create lb :"<<endl;
    cin >> n;
    CreateList_L(lb,n);

    int i,j,len;
    cin >> i >> j >> len;
    int point = DeleteAndInsertSub(la,lb,i,j,len);
    if(!point)
        cout << "something is ERROR!" <<endl;
    else
        Print_L(lb);
    return 0;
}
