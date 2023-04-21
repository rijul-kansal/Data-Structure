#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
};

class BST
{
    Node *root;

public:
    BST();
    Node *getNode();
    int rSearch(Node *p, int key);
    Node *rInsert(Node *p, int key);
    int Search(int key);
    void Insert(int key);
    void inorder(Node *p);  
    int Height(Node *p);
    Node *presucc(Node *p);
    Node *insucc(Node *p);
    Node *Delete(Node *p, int key);
    void Generate_Tree(int arr[], int n);
};
BST ::BST()
{
    root = NULL;
}
Node * BST ::getNode()
{
    return root;
}
// Tc will be O(N)
int BST :: rSearch(Node *p, int key)
{
    if (p == NULL)
    {
        return 0;
    }
    if (p->data == key)
    {
        return 1;
    }
    else if (p->data > key)
    {
        rSearch(p->lchild, key);
    }
    else
    {
        rSearch(p->rchild, key);
    }
}
// Tc will be O(N)
Node * BST ::rInsert(Node *p, int key)
{
    if (p == NULL)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        return p;
    }
    if (p->data > key)
    {
        p->lchild = rInsert(p->lchild, key);
    }
    else if (p->data < key)
    {
        p->rchild = rInsert(p->rchild, key);
    }
    return p;
}
// Tc will be O(N)
int BST :: Search(int key)
{
    Node *p = root;
    while (p)
    {
        if (p->data == key)
        {
            return 1;
        }
        else if (p->data > key)
        {
            p = p->lchild;
        }
        else
        {
            p = p->rchild;
        }
    }
    return 0;
}
// Tc will be O(N)
void BST :: Insert(int key)
{
    Node *p = root;
    if (root == NULL)
    {
        root = new Node;
        root->data = key;
        root->lchild = NULL;
        root->rchild = NULL;
        return;
    }
    Node *q;
    while (p)
    {
        q = p;
        if (p->data == key)
        {
            return;
        }
        else if (p->data > key)
        {
            p = p->lchild;
        }
        else
        {
            p = p->rchild;
        }
    }
    Node *r = new Node;
    r->data = key;
    r->lchild = NULL;
    r->rchild = NULL;
    if (q->data > key)
    {
        q->lchild = r;
    }
    else
    {
        q->rchild = r;
    }
}
// Tc will be O(N)
void BST :: inorder(Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}
// Tc will be O(N)
int  BST ::Height(Node *p)
{
    if (p)
    {
        int x = Height(p->lchild);
        int y = Height(p->rchild);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    return 0;
}
// Tc will be O(N)
Node *presucc(Node *p)
{
    while (p && p->rchild)
        p = p->rchild;
    return p;
}
// Tc will be O(N)
Node * BST ::insucc(Node *p)
{
    while (p && p->lchild)
        p = p->lchild;
    return p;
}
// Tc will be O(N)
Node * BST ::Delete(Node *p, int key)
{
    if (p->lchild == NULL && p->rchild == NULL)
    {
        int x = p->data;
        delete p;
        return NULL;
    }
    if (p->data > key)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (p->data < key)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        if (Height(presucc(p->lchild)) > Height(presucc(p->rchild)))
        {
            Node *q = presucc(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            Node *q = insucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}
// Tc will be O(N)
void BST :: Generate_Tree(int arr[], int n)
{
    root = new Node;
    root->data = arr[0];
    root->lchild = root->rchild = NULL;
    stack<Node *> stk;
    int i = 1;
    Node *p = root;
    while (i < n)
    {
        if (arr[i] < p->data)
        {
            Node *t = new Node;
            t->data = arr[i++];
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            stk.push(p);
            p = t;
        }
        else
        {
            if (arr[i] > p->data && arr[i] < stk.empty() ? 65535 : stk.top()->data)
            {
                Node *t = new Node;
                t->data = arr[i++];
                t->lchild = t->rchild = NULL;
                p->lchild = t;
                p = t;
            }
            else
            {
                p = stk.top();
                stk.pop();
            }
        }
    }
}
int main()
{
    return 0;
}