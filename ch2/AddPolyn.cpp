#include "LinkList.hpp"
typedef LinkList Polynomial;

//将pa、pb两个多项式相加
void AddPolyn(Polynomial &pa,Polynomial &pb)
{
    Polynomial La,Lb,p,q;
    //La Lb 初始指向两表的第一个结点，进行判断和操作
    La = pa->next;
    Lb = pb->next;
    p = pa;//最终将两表合并成pa并输出pa。
    while(La && Lb)
    {
        if(La->data.expn < Lb->data.expn)
        {
            p = La;
            La = La->next;
        }
        else if(La->data.expn == Lb->data.expn)
        {
            float k = La->data.coef +Lb->data.coef;
            Polynomial r;
            if(k)
            {
                La->data.coef = k;
                r = Lb;//此时将Lb赋给r表示两者均指向同一个地址，如果对r所指向的地址操作则Lb也会改变，注意！！
                Lb = Lb->next;//注意顺序，该步骤不能在free之后
                free(r);
            }
            else
            {
                r = La;
                La= La->next;
                free(r);
                p->next = La;
                r = Lb;
                Lb = Lb->next;
                free(r);
            }
        }
        else
        {
            q = Lb;//这里的先后顺序也非常重要，不能弄反了！！！
            Lb = Lb->next;
            p->next = q;
            q->next =La;
        }
    }
    if(Lb)
    {
        La = p;
        La->next = Lb;
    }
}

int main()
{
    Polynomial pa,pb;
    int m,n;
    cout << "input m value :" << endl;
    cin >> m;
    CreateList_L(pa,m);
    cout << "input m value :" << endl;
    cin >> n;
    CreateList_L(pb,n);
    AddPolyn(pa,pb);
    PrintList(pa);
    return 0;
}
