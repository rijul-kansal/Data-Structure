#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    int height;
    Node *lchild;
    Node *rchild;
};

class AVL
{

public:
    Node *root;
    AVL();
    Node *getNode();
    int BF(Node *p);
    Node *LL(Node *p);
    Node *RR(Node *p);
    Node *LR(Node *p);
    Node *RL(Node *p);
    Node *rInsert(Node *p, int key);
    int Height(Node *p);
    Node *presucc(Node *p);
    Node *insucc(Node *p);
    Node *Delete(Node *p, int key);
    void inorder(Node *p);
};
AVL ::AVL()
{
    root = NULL;
}
Node *AVL ::getNode()
{
    return root;
}
int AVL::BF(Node *p)
{
    int x = (p && p->lchild) ? p->lchild->height : 0;
    int y = (p && p->rchild) ? p->rchild->height : 0;
    return x - y;
}
Node *AVL::LL(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    pl->height = Height(pl);
    plr->height = Height(plr);
    p->height = Height(p);

    if (p == root)
    {
        root = pl;
    }
    return pl;
}
Node *AVL::RR(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    pr->height = Height(pr);
    prl->height = Height(prl);
    p->height = Height(p);

    if (p == root)
    {
        root = pr;
    }
    return pr;
}
Node *AVL::LR(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    p->lchild = plr->rchild;
    pl->rchild = plr->lchild;

    plr->rchild = p;
    plr->lchild = pl;

    pl->height = Height(pl);
    plr->height = Height(plr);
    p->height = Height(p);

    if (p == root)
    {
        root = plr;
    }
    return plr;
}
Node *AVL::RL(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;

    prl->lchild = p;
    prl->rchild = pr;

    pr->height = Height(pr);
    prl->height = Height(prl);
    p->height = Height(p);

    if (p == root)
    {
        root = prl;
    }
    return prl;
}
// Tc will be O(N)
Node *AVL ::rInsert(Node *p, int key)
{
    if (p == NULL)
    {
        p = new Node;
        p->data = key;
        p->height = 1;
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

    p->height = Height(p);

    if (BF(p) == 2 && BF(p->lchild) == 1)
    {
        return LL(p);
    }
    else if (BF(p) == 2 && BF(p->lchild) == -1)
    {
        return LR(p);
    }
    else if (BF(p) == -2 && BF(p->rchild) == -1)
    {
        return RR(p);
    }
    else if (BF(p) == -2 && BF(p->rchild) == 1)
    {
        return RL(p);
    }
    return p;
}
// Tc will be O(N)
int AVL ::Height(Node *p)
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
Node *AVL::presucc(Node *p)
{
    while (p && p->rchild)
        p = p->rchild;
    return p;
}
// Tc will be O(N)
Node *AVL ::insucc(Node *p)
{
    while (p && p->lchild)
        p = p->lchild;
    return p;
}
// Tc will be O(N)
Node *AVL ::Delete(Node *p, int key)
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
    p->height = Height(p);

    if (BF(p) == 2 && BF(p->lchild) == 0)
    {
        return LL(p);
    }
    else if (BF(p) == 2 && BF(p->lchild) == 1)
    {
        return LL(p);
    }
    else if (BF(p) == 2 && BF(p->lchild) == -1)
    {
        return LR(p);
    }
    else if (BF(p) == -2 && BF(p->rchild) == 0)
    {
        return RR(p);
    }
    else if (BF(p) == -2 && BF(p->rchild) == -1)
    {
        return RR(p);
    }
    else if (BF(p) == -2 && BF(p->rchild) == 1)
    {
        return RL(p);
    }
    return p;
}
void AVL :: inorder(Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}
int main()
{
    class AVL a;
    a.root=a.rInsert(a.root,2);
    a.root=a.rInsert(a.root,1);
    a.root=a.rInsert(a.root,3);
    a.root=a.rInsert(a.root,5);
    a.root=a.rInsert(a.root,4);
    a.inorder(a.root);
     return 0;
}