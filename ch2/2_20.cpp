#include "../Repository/LinkList.hpp"

int main()
{
    LinkList L,p,r,q;
    int m = 8;
    CreateList_L(L,m);
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
    Print_L(L);
    return 0;
}
