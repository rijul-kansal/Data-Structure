#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
class Linked_list
{

public:
    Node *root;
    Node *second;
    Node *third;
    Linked_list();
    Node *getNode() { return root; }
    void Create(int arr[], int n);
    void Create2(int arr[], int n);
    void Display_I();
    void Display_I2();
    void Display_I3();
    void Display_R1(Node *p);
    void Display_R2(Node *p);
    int Count_I();
    int Count_R(Node *);
    int Sum_I();
    int Sum_R(Node *);
    int Max();
    int Min();
    int Linear_search(int);
    int Linear_search_improved(int);
    void Insert(int index, int key);
    void Insert_last_1(int key);
    void Insert_last_2(int key);
    void Inserted_sorted(int key);
    int Delete(int index);
    void Remove_duplicate();
    void Reversing_1();
    void Reversing_I();
    void merging(Node *p);
    Node *concat(Node *p, Node *q);
    bool isloop();
    Node *Middle_node();
    Node *Intersection();
};
Linked_list ::Linked_list()
{
    root = NULL;
    second = NULL;
}
// Tc will be O(N)
void Linked_list ::Create(int arr[], int n)
{
    root = new Node;
    root->data = arr[0];
    root->next = NULL;
    Node *last = root;
    for (int i = 1; i < n; i++)
    {
        Node *t = new Node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
// Tc will be O(N)
void Linked_list ::Create2(int arr[], int n)
{
    second = new Node;
    second->data = arr[0];
    second->next = NULL;
    Node *last = second;
    for (int i = 1; i < n; i++)
    {
        Node *t = new Node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
// Tc will be O(N)
void Linked_list ::Display_I()
{
    Node *p = root;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
// Tc will be O(N)
void Linked_list ::Display_I2()
{
    Node *p = second;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
// Tc will be O(N)
void Linked_list ::Display_I3()
{
    Node *p = third;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
// Tc will be O(N)
void Linked_list ::Display_R1(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        Display_R1(p->next);
    }
}
// Tc will be O(N)
void Linked_list ::Display_R2(Node *p)
{
    if (p)
    {
        Display_R2(p->next);
        cout << p->data << " ";
    }
}
// Tc will be O(N)
int Linked_list ::Count_I()
{
    int c = 0;
    Node *p = root;
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}
// Tc will be O(N)
int Linked_list ::Count_R(Node *p)
{
    if (p)
    {
        return Count_R(p->next) + 1;
    }
    return 0;
}
// Tc will be O(N)
int Linked_list ::Sum_I()
{
    int c = 0;
    Node *p = root;
    while (p)
    {
        c += p->data;
        p = p->next;
    }
    return c;
}
// Tc will be O(N)
int Linked_list ::Sum_R(Node *p)
{
    if (p)
    {
        return Sum_R(p->next) + p->data;
    }
    return 0;
}
// Tc will be O(N)
int Linked_list ::Max()
{
    Node *p = root;
    int max = p->data;
    p = p->next;
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}
// Tc will be O(N)
int Linked_list ::Min()
{
    Node *p = root;
    int min = p->data;
    p = p->next;
    while (p)
    {
        if (p->data < min)
            min = p->data;
        p = p->next;
    }
    return min;
}
int Linked_list ::Linear_search(int key)
{
    Node *p = root;
    while (p)
    {
        if (p->data == key)
            return 1;
        p = p->next;
    }
    return 0;
}
int Linked_list ::Linear_search_improved(int key)
{
    Node *p = root;
    Node *q = NULL;
    while (p)
    {

        if (p->data == key)
        {
            q->next = p->next;
            p->next = root;
            root = p;
            return 1;
        }
        q = p;
        p = p->next;
    }
    return 0;
}
// Tc will be O(N)
void Linked_list ::Insert(int index, int key)
{
    Node *p = root;
    if (index < 0 || index > Count_I())
    {
        return;
    }

    if (index == 0)
    {
        Node *t = new Node;
        t->data = key;
        t->next = NULL;
        t->next = root;
        root = t;
        return;
    }

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
    }
    if (p)
    {
        Node *t = new Node;
        t->data = key;
        t->next = NULL;
        t->next = p->next;
        p->next = t;
    }
}
// Tc will be O(N)
void Linked_list ::Insert_last_1(int key)
{
    Node *t = new Node;
    t->data = key;
    t->next = NULL;
    Node *p = root;
    Node *last = NULL;
    if (p == NULL)
    {

        t->next = root;
        root = t;
        return;
    }
    while (p->next)
    {
        p = p->next;
    }
    p->next = t;
    p = t;
}
// Tc will be O(1)
void Linked_list ::Insert_last_2(int key)
{
    Node *t = new Node;
    t->data = key;
    t->next = NULL;
    Node *last;
    if (root == NULL)
    {
        root = t;
        last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}
// Tc will be O(N)
void Linked_list ::Inserted_sorted(int key)
{
    Node *t = new Node;
    t->data = key;
    t->next = NULL;
    if (root == NULL)
    {
        root = t;
    }
    else
    {
        Node *p = root;
        Node *q;
        while (p && key > p->data)
        {
            q = p;
            p = p->next;
        }
        if (p == root)
        {
            t->next = root;
            root = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}
// Tc will be O(N)
int Linked_list ::Delete(int index)
{
    int x;
    if (index < 0 || index > Count_I())
        return -1;
    if (index == 0)
    {
        Node *q = root;
        root = root->next;
        x = q->data;
        delete q;
    }
    else
    {
        Node *p = root;
        Node *q = NULL;
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}
// Tc will be O(N)
void Linked_list ::Remove_duplicate()
{
    Node *q = root->next;
    Node *p = root;
    while (q)
    {
        if (p->data == q->data)
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
        else
        {
            p = q;
            q = q->next;
        }
    }
}
// Tc will be O(N)
void Linked_list ::Reversing_1()
{
    vector<int> v;
    Node *p = root;
    while (p)
    {
        v.push_back(p->data);
        p = p->next;
    }
    p = root;
    int i = v.size() - 1;
    while (p)
    {
        p->data = v[i--];
        p = p->next;
    }
}
// Tc will be O(N)
void Linked_list ::Reversing_I()
{
    Node *q = NULL;
    Node *r = NULL;
    Node *p = root;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    root = q;
}
void Linked_list ::merging(Node *pp)
{
    Node *p = root;
    third = p;
    while (p->next)
    {
        p = p->next;
    }

    p->next = pp;
}
Node *Linked_list ::concat(Node *p, Node *q)
{
    Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else if (p->data > q->data)
    {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            p = p->next;
            last = last->next;
            last->next = NULL;
        }
        else if (p->data > q->data)
        {
            last->next = q;
            q = q->next;
            last = last->next;
            last->next = NULL;
        }
    }
    while (p)
    {
        last->next = p;
        last = p;
        p = p->next;
    }
    while (q)
    {
        last->next = q;
        last = q;
        q = q->next;
    }
    return third;
}
bool Linked_list ::isloop()
{
    Node *p;
    Node *q;
    p = q = root;
    do
    {
        p = p->next;
        q = q->next;
        if (q)
            q = q->next;
    } while (p && q && p != q);
    if (p == q)
        return true;
    else
        return false;
}
Node *Linked_list ::Middle_node()
{
    Node *p = root;
    Node *q = root;
    while (p)
    {
        p = p->next;
        if (p)
            p = p->next;
        if (p)
            q = q->next;
    }
    return q;
}
Node *Linked_list ::Intersection()
{
    stack<Node *> stk1;
    stack<Node *> stk2;

    Node *p = root;
    Node *q = second;

    while (p)
    {
        stk1.push(p);
        p = p->next;
    }
    while (q)
    {
        stk1.push(q);
        q = q->next;
    }
    Node *pp = NULL;
    while (!stk1.empty() && !stk2.empty())
    {
        if (stk1.top() == stk2.top())
        {
            pp = stk2.top();
            stk2.pop();
            stk1.pop();
        }
        else
        {
            break;
        }
    }
    return pp;
}
int main()
{
    int arr[]{0, 1, 2, 5, 15, 25, 35, 45};
    class Linked_list l;
    l.Create(arr, 8);
    l.Display_I3();
    return 0;
}