#include "../Repository/LinkList.hpp"

int main()
{
    LinkList ha,hb,hc;
    LinkList p,q;
    int m,n;
    cout << "the length of ha is :"<<endl;
    cin >> m;
    cout << "the length of hb is :"<<endl;
    cin >> n;
    CreateList_L(ha,m);
    CreateList_L(hb,n);
    p = ha->next;
    q = hb->next;
    /*
    if(m <= n)
    {
        hc = ha;
        p = ha->next;
        q = hb->next;
        while(p->next)p = p->next;
        p->next = q;
    }
    else
    {
        hc = hb;
        q = hb->next;
        p = ha->next;
        while(q->next)q = q->next;
        q->next = p;
    }*/
    //在已知ha hb情况下，应该这么做
    while(p->next && q->next)
    {
        p = p->next;
        q = q->next;
    }
    if(!p->next)
    {
        hc = hb;//****为什么不是hc = ha?不是更快么？
        while(q->next)q = q->next;
        q->next = ha->next;;
    }
    else
    {
        hc = ha;
        while(p->next)p = p->next;
        p->next = hb->next;
    }
    Print_L(hc);
    return 0;
}
