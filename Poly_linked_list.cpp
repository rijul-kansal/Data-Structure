#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int pow;
    int exp;
    Node *next;
};
class Polynomial
{
public:
    Node *p1;
    Node *p2;
    Node *p3;
    Polynomial()
    {
        p1 = NULL;
        p2 = NULL;
        p3 = NULL;
    }
    void Create1()
    {
        int n;
        cout << "Enter the no of terms ";
        cin >> n;
        int e, p;
        Node *last;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter coff and power resp ";
            cin >> e >> p;
            if (p1 == NULL)
            {
                Node *t = new Node;
                t->exp = e;
                t->pow = p;
                t->next = NULL;
                p1 = last = t;
            }
            else
            {
                Node *t = new Node;
                t->exp = e;
                t->pow = p;
                t->next = NULL;
                last->next = t;
                last = t;
            }
        }
        cout << endl;
    }
    void Create2()
    {
        int n;
        cout << "Enter the no of terms ";
        cin >> n;
        int e, p;
        Node *last;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter coff and power resp ";
            cin >> e >> p;
            if (p2 == NULL)
            {
                Node *t = new Node;
                t->exp = e;
                t->pow = p;
                t->next = NULL;
                p2 = last = t;
            }
            else
            {
                Node *t = new Node;
                t->exp = e;
                t->pow = p;
                t->next = NULL;
                last->next = t;
                last = t;
            }
        }
        cout << endl;
    }
    void Display(Node *p)
    {
        while (p)
        {
            cout << p->exp << "*x^" << p->pow << " + ";
            p = p->next;
        }
        cout << endl;
    }
    void Add()
    {
        Node *p = p1;
        Node *q = p2;
        Node *last;
        if (p->pow > q->pow)
        {
            p3 = new Node;
            p3->pow = p->pow;
            p3->exp = p->exp;
            p3->next = NULL;
            last = p3;
            p = p->next;
        }
        else if (p->pow < q->pow)
        {
            p3 = new Node;
            p3->pow = q->pow;
            p3->exp = q->exp;
            p3->next = NULL;
            last = p3;
            q = q->next;
        }
        else
        {
            p3 = new Node;
            p3->pow = q->pow;
            p3->exp = q->exp + p->exp;
            p3->next = NULL;
            last = p3;
            p = p->next;
            q = q->next;
        }
        while (p && q)
        {
            if (p->pow > q->pow)
            {
                Node *t = new Node;
                t->pow = p->pow;
                t->exp = p->exp;
                t->next = NULL;
                last->next = t;
                last = t;
                p = p->next;
            }
            else if (p->pow < q->pow)
            {
                Node *t = new Node;
                t->pow = q->pow;
                t->exp = q->exp;
                t->next = NULL;
                last->next = t;
                last = t;
                q = q->next;
            }
            else
            {
                Node *t = new Node;
                t->pow = p->pow;
                t->exp = p->exp + q->exp;
                t->next = NULL;
                last->next = t;
                last = t;
                p = p->next;
                q = q->next;
            }
        }
        if (p)
        {

            last->next = p;
        }
        if (q)
        {

            last->next = q;
        }
    }
    int eval(int x)
    {
        Node *p = p1;
        int e = 0;
        while (p)
        {
            e += p->exp * pow(x, p->pow);
            p = p->next;
        }
        return e;
    }
};
int main()
{
    class Polynomial p;
    p.Create1();
    p.Display(p.p1);
    return 0;
}