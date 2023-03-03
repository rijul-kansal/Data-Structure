#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
class Circular_linked_list
{
public:
    Node *root;
    Circular_linked_list()
    {
        root = NULL;
    }
    void create(int arr[], int n)
    {
        root = new Node;
        root->data = arr[0];
        root->next = root;
        Node *last = root;
        for (int i = 1; i < n; i++)
        {
            Node *t = new Node;
            t->data = arr[i];
            last->next = t;
            last = t;
            t->next = root;
        }
    }
    void display()
    {
        if (root == NULL)
            return;
        Node *p = root;
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p && p != root);
    }
    int count()
    {
        if (root == NULL)
            return NULL;
        int c = 0;
        Node *p = root;
        do
        {
            c++;
            p = p->next;
        } while (p != root);
        return c;
    }
    void Insert(int index, int key)
    {
        if (index < 0 || index > count())
            return;
        if (index == 0)
        {
            if (root == NULL)
            {
                root = new Node;
                root->data = key;
                root->next = root;
            }
            else
            {
                Node *p = root;
                while (p->next != root)
                {
                    p = p->next;
                }
                Node *t = new Node;
                t->data = key;
                p->next = t;
                t->next = root;
                root = t;
            }
        }
        else
        {
            Node *p = root;
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
    }
    int Delete(int index)
    {
        int x = 0;
        if (index == 1)
        {
            if (root == NULL)
            {
                return -1;
            }
            else if (root->next == root)
            {
                x = root->data;
                root = NULL;
            }
            else
            {
                Node *p = root;
                while (p->next != root)
                {
                    p = p->next;
                }
                p->next = root->next;
                Node *q = root;
                x = q->data;
                root = root->next;
                delete q;
            }
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
};

int main()
{
    class Circular_linked_list l;
    int arr[]{2, 3, 4, 5, 6};
    l.create(arr, 5);
    l.display();
    return 0;
}