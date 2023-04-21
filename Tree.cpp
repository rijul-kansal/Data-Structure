#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
};

class Tree
{
    Node *root;

public:
    Node *getroot()
    {
        return root;
    }
    Tree()
    {
        root = NULL;
    }
    void create()
    {
        queue<Node *> q;
        int x;

        cout << "Enter Root Node val ";
        cin >> x;
        root = new Node;
        root->data = x;
        root->lchild = root->rchild = NULL;
        q.push(root);

        while (!q.empty())
        {
            Node *p = q.front();
            q.pop();

            cout << "Enter left child of " << p->data << " ";
            cin >> x;
            if (x != -1)
            {
                Node *t = new Node;
                t->data = x;
                t->lchild = t->rchild = NULL;
                p->lchild = t;
                q.push(t);
            }
            cout << "Enter right child of " << p->data << " ";
            cin >> x;
            if (x != -1)
            {
                Node *t = new Node;
                t->data = x;
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                q.push(t);
            }
        }
    }
    // Tc will be O(N)
    void preorder(Node *p)
    {
        if (p)
        {
            cout << p->data << " ";
            preorder(p->lchild);
            preorder(p->rchild);
        }
    }
    // Tc will be O(N)
    void inorder(Node *p)
    {
        if (p)
        {
            inorder(p->lchild);
            cout << p->data << " ";
            inorder(p->rchild);
        }
    }
    // Tc will be O(N)
    void postorder(Node *p)
    {
        if (p)
        {
            postorder(p->lchild);
            postorder(p->rchild);
            cout << p->data << " ";
        }
    }
    // Tc will be O(N)
    void iter_preorder()
    {
        Node *p = root;
        stack<Node *> stk;
        while (p || !stk.empty())
        {
            if (p)
            {
                cout << p->data << " ";
                stk.push(p);
                p = p->lchild;
            }
            else
            {
                p = stk.top();
                stk.pop();
                p = p->rchild;
            }
        }
    }
    // Tc will be O(N)
    void iter_inorder()
    {
        Node *p = root;
        stack<Node *> stk;
        while (p || !stk.empty())
        {
            if (p)
            {
                stk.push(p);
                p = p->lchild;
            }
            else
            {
                p = stk.top();
                stk.pop();
                cout << p->data << " ";
                p = p->rchild;
            }
        }
    }
    // Tc will be O(N)
    void iter_postorder()
    {
        Node *p = root;
        stack<int long long> stk;
        while (p || !stk.empty())
        {
            if (p)
            {
                long long int temp = (long long int)p;
                stk.push(temp);
                p = p->lchild;
            }
            else
            {
                long long int temp = stk.top();
                stk.pop();
                if (temp > 0)
                {
                    stk.push(-1 * temp);
                    p = ((Node *)(temp))->rchild;
                }
                else
                {
                    p = ((Node *)(-1 * temp));
                    cout << p->data << " ";
                    p = NULL;
                }
            }
        }
    }
    // Tc will be O(N)
    void Levelorder()
    {
        Node *p = root;
        queue<Node *> q;
        q.push(p);
        cout << p->data << " ";
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            if (p->lchild)
            {
                cout << p->lchild->data << " ";
                q.push(p->lchild);
            }
            if (p->rchild)
            {
                cout << p->rchild->data << " ";
                q.push(p->rchild);
            }
        }
    }
    int count(Node *p)
    {
        if (p)
        {
            int x = count(p->lchild);
            int y = count(p->rchild);
            return x + y + 1;
        }
        return 0;
    }
    int count_Degree2(Node *p)
    {
        if (p)
        {
            int x = count_Degree2(p->lchild);
            int y = count_Degree2(p->rchild);
            if (p->lchild && p->rchild)
                return x + y + 1;
            else
                return x + y;
        }
        return 0;
    }
    int count_Degree1(Node *p)
    {
        if (p)
        {
            int x = count_Degree1(p->lchild);
            int y = count_Degree1(p->rchild);
            if (p->lchild != NULL ^ p->rchild != NULL)
                return x + y + 1;
            else
                return x + y;
        }
        return 0;
    }
    int count_Leef(Node *p)
    {
        if (p)
        {
            int x = count_Leef(p->lchild);
            int y = count_Leef(p->rchild);
            if (p->lchild == NULL & p->rchild == NULL)
                return x + y + 1;
            else
                return x + y;
        }
        return 0;
    }
    int Sum(Node *p)
    {
        if (p)
        {
            int x = Sum(p->lchild);
            int y = Sum(p->rchild);
            return x + y + p->data;
        }
        return 0;
    }
    int Height(Node *p)
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
};
int main()
{
    class Tree t;
    t.create();
    cout << t.Height(t.getroot());
    return 0;
}