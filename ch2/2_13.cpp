#include "../Repository/LinkList.hpp"

int main()
{
    LinkList L;
    int n;
    ElemType x;
    cout << "input n value:" << endl;
    cin >> n;
    cout << "input x value:" << endl;
    cin >> x;
    CreateList_L(L,n);
    Print_L(L);
    int l = Locate_L(L,x);
    l?(cout << "the location is " << l << endl):(cout << "NOT FOUND!" << endl);
    return 0;
}
