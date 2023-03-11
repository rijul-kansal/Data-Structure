#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};
class Linked_list
{
public:
    Node *root;
    Linked_list()
    {
        root = NULL;
    }
    void Create(int arr[], int n)
    {
        Node *t = new Node;
        Node *last;
        t->data = arr[0];
        t->prev = t->next = NULL;
        root = last = t;
        for (int i = 1; i < n; i++)
        {
            Node *t = new Node;
            t->data = arr[i];
            t->next = NULL;
            t->prev = last;
            last->next = t;
            last = t;
        }
    }
    void Display_front()
    {
        Node *p = root;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
    void Display_back()
    {
        Node *p = root;
        while (p->next)
        {
            p = p->next;
        }
        while (p)
        {
            cout << p->data << " ";
            p = p->prev;
        }
    }
    int Count()
    {
        Node *p = root;
        int c = 0;
        while (p)
        {
            c++;
            p = p->next;
        }
        return c;
    }
    void Insert(int index, int key)
    {
        Node *t = new Node;
        t->data = key;
        if (index < 0 || index > Count())
            return;
        if (index == 0)
        {
            if (root == NULL)
            {
                t->prev = t->next = NULL;
                root = t;
                return;
            }
            else
            {
                root->prev = t;
                t->next = root;
                root = t;
                return;
            }
        }
        else
        {
            Node *p = root;
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            if (p->next == NULL)
            {
                t->next = NULL;
                p->next = t;
                t->prev = p;
            }
            else
            {
                t->next = p->next;
                p->next->prev = t;
                p->next = t;
                t->prev = p;
            }
        }
    }
    int Delete(int index)
    {
        Node *q=root;
        int x = -1;
        if (index < 0 || index > Count())
            return x;
        if (index == 1)
        {
            if (root == NULL)
            {
                return x;
            }
            else if (root->next == NULL)
            {
                x = root->data;
                delete root;
                root = NULL;
                return x;
            }
            else
            {
                Node *qq = root;
                x = qq->data;
                root = root->next;
                root->prev = NULL;
                delete qq;
                return x;
            }
        }
        else
        {
            Node *p = root;
            for (int i = 0; i < index - 1; i++)
            {
                q = p;
                p = p->next;
            }
            if (p->next == NULL)
            {
                q->next = NULL;
                p->prev = NULL;
                x = p->data;
                delete p;
                return x;
            }
            else
            {
                q->next = p->next;
                p->next->prev = q;
                p->next=NULL;
                p->prev=NULL;
                x = p->data;
                delete p;
                return x;
            }
        }
    }
};
int main()
{
    Linked_list l1;
    int arr[]{2, 3, 4, 5, 6};
    l1.Create(arr, 5);
    l1.Delete(3);
    l1.Display_front();
    return 0;
}