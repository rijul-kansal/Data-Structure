#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
};
class BSTIterator
{
public:
    stack<Node *> stk;
    BSTIterator(Node *root)
    {
        fn(root);
    }

    int next()
    {
        Node *p = stk.top();
        int x = stk.top()->data;
        stk.pop();
        p = p->rchild;
        if (p)
            fn(p);
        return x;
    }

    bool hasNext()
    {
        if (stk.size() > 0)
            return true;
        else
            return false;
    }
    void fn(Node *p)
    {
        while (p)
        {
            stk.push(p);
            p = p->lchild;
        }
    }
};
class Tree
{
    Node *root;

public:
    Node *getroot();
    Tree();
    void create();
    void preorder(Node *p);
    void inorder(Node *p);
    void postorder(Node *p);
    void iter_preorder();
    void iter_inorder();
    void iter_postorder();
    void Levelorder();
    int count(Node *p);
    int count_Degree2(Node *p);
    int count_Degree1(Node *p);
    int count_Leef(Node *p);
    int Sum(Node *p);
    int Height(Node *p);
    void postorder2(Node *p);
    void PreInPost(Node *p);

    int BalancedBT(Node *p);
    int DiameterBt(Node *p);
    int Diameter(Node *p, int &mx);
    int MaxPathSum(Node *p);
    int MaxPS(Node *p, int &sum);
    void BoundaryTraversal(Node *p);
    void pre(Node *p, vector<int> &v);
    void in(Node *p, vector<int> &v);
    void post(Node *p, vector<int> &v);
    vector<vector<int>> verticalTraversal(Node *p);
    void TopView(Node *p);
    Node *lowestCommonAncestor(Node *p, Node *q, Node *r);
    Node *solve(Node *p, Node *q, Node *r);
    int widthOfBinaryTree(Node *p);
    int Children_sum_prop(Node *p);
    vector<int> distanceK(Node *root, Node *target, int k);
    int LCA(Node *p, int x, int y);
    int Inorder_succ(Node *p, int key);
    void Morris_inorder(Node *root);
};

Node *Tree ::getroot()
{
    return root;
}
Tree ::Tree()
{
    root = NULL;
}
void Tree ::create()
{
    queue<Node *> q;
    int x;

    cout << "Enter Root Node data ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        cout << "Enter lchild child of " << p->data << " ";
        cin >> x;
        if (x != -1)
        {
            Node *t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.push(t);
        }
        cout << "Enter rchild child of " << p->data << " ";
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
void Tree ::preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
// Tc will be O(N)
void Tree ::inorder(Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}
// Tc will be O(N)
void Tree ::postorder(Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " ";
    }
}
// Tc will be O(N)
void Tree ::iter_preorder()
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
void Tree ::iter_inorder()
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
void Tree ::iter_postorder()
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
void Tree ::Levelorder()
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
int Tree ::count(Node *p)
{
    if (p)
    {
        int x = count(p->lchild);
        int y = count(p->rchild);
        return x + y + 1;
    }
    return 0;
}
int Tree ::count_Degree2(Node *p)
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
int Tree ::count_Degree1(Node *p)
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
int Tree ::count_Leef(Node *p)
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
int Tree ::Sum(Node *p)
{
    if (p)
    {
        int x = Sum(p->lchild);
        int y = Sum(p->rchild);
        return x + y + p->data;
    }
    return 0;
}
int Tree ::Height(Node *p)
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
void Tree :: postorder2(Node *p)
{
    stack<Node *> stk1;
    stack<int> stk2;
    stk1.push(p);
    while (!stk1.empty())
    {
        p = stk1.top();
        stk1.pop();
        stk2.push(p->data);
        if (p->lchild)
            stk1.push(p->lchild);
        if (p->rchild)
            stk1.push(p->rchild);
    }

    while (!stk2.empty())
    {
        cout << stk2.top() << " ";
        stk2.pop();
    }
}
void Tree :: PreInPost(Node *p)
{
    vector<int> pre, in, post;

    stack<pair<Node *, int>> stk;
    stk.push({p, 1});
    while (!stk.empty())
    {
        auto it = stk.top();
        stk.pop();
        p = it.first;
        int x = it.second;
        if (x == 1)
        {
            pre.push_back(p->data);
            stk.push({p, x + 1});
            if (p->lchild)
                stk.push({p->lchild, 1});
        }
        else if (x == 2)
        {
            in.push_back(p->data);
            stk.push({p, x + 1});
            if (p->rchild)
                stk.push({p->rchild, 1});
        }
        else
        {
            post.push_back(p->data);
        }
    }

    for (int i = 0; i < pre.size(); i++)
    {
        cout << pre[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < pre.size(); i++)
    {
        cout << in[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < pre.size(); i++)
    {
        cout << post[i] << " ";
    }
}

int Tree :: BalancedBT(Node *p)
{
    if (!p)
        return 0;
    int x = BalancedBT(p->lchild);
    int y = BalancedBT(p->rchild);
    if (x = -1 || y == -1)
        return -1;
    if (abs(x - y) > 1)
        return -1;
    return max(x, y) + 1;
}
int Tree :: DiameterBt(Node *p)
{
    int max = 0;
    Diameter(p, max);
    return max;
}
int  Tree ::Diameter(Node *p, int &mx)
{
    if (!p)
        return 0;
    int x = Diameter(p->lchild, mx);
    int y = Diameter(p->rchild, mx);
    mx = max(mx, x + y);
    return max(x, y) + 1;
}
int Tree :: MaxPathSum(Node *p)
{
    int sum = INT_MIN;
    MaxPS(p, sum);
    return sum;
}
int Tree :: MaxPS(Node *p, int &sum)
{
    if (!p)
        return 0;

    int x = max(0, MaxPS(p->lchild, sum));
    int y = max(0, MaxPS(p->rchild, sum));
    sum = max(sum, x + y + p->data);
    return max(x, y) + p->data;
}
void Tree :: BoundaryTraversal(Node *p)
{
    vector<int> v;
    v.push_back(p->data);
    vector<int> vv;
    pre(p->lchild, v);
    in(p, v);
    post(p->rchild, vv);
    for (int i = vv.size() - 1; i >= 0; i--)
    {
        v.push_back(vv[i]);
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
void Tree :: pre(Node *p, vector<int> &v)
{
    while (p)
    {
        if (p->lchild || p->rchild)
            v.push_back(p->data);
        if (p->lchild)
            p = p->lchild;
        else
            p = p->rchild;
    }
}
void Tree :: in(Node *p, vector<int> &v)
{

    if (p)
    {
        in(p->lchild, v);
        if (p->lchild == NULL && p->rchild == NULL)
            v.push_back(p->data);
        in(p->rchild, v);
    }
}
void Tree :: post(Node *p, vector<int> &v)
{

    while (p)
    {
        if (p->lchild || p->rchild)
            v.push_back(p->data);
        if (p->rchild)
            p = p->rchild;
        else
            p = p->lchild;
    }
}
vector<vector<int>> Tree ::  verticalTraversal(Node *p)
{
    map<int, map<int, multiset<int>>> mp;
    queue<pair<Node *, pair<int, int>>> q;
    q.push({p, {0, 0}});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        p = it.first;
        int lvl = it.second.first;
        int pos = it.second.second;
        mp[pos][lvl].insert(p->data);
        if (p->lchild)
        {
            q.push({p->lchild, {lvl + 1, pos - 1}});
        }
        if (p->rchild)
        {
            q.push({p->rchild, {lvl + 1, pos + 1}});
        }
    }
    vector<vector<int>> res;

    for (auto x : mp)
    {
        vector<int> v;
        for (auto y : x.second)
        {
            for (auto z : y.second)
            {
                v.push_back(z);
            }
        }
        res.push_back(v);
    }
    return res;
}
void Tree :: TopView(Node *p)
{
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({p, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        p = it.first;
        int x = it.second;
        if (mp.find(x) == mp.end())
        {
            mp[x] = p->data;
        }
        if (p->lchild)
        {
            q.push({p->lchild, x - 1});
        }
        if (p->rchild)
        {
            q.push({p->rchild, x + 1});
        }
    }
    for (auto x : mp)
    {
        cout << x.second << " ";
    }
}
Node *Tree ::lowestCommonAncestor(Node *p, Node *q, Node *r)
{
    return solve(p, q, r);
}
Node * Tree ::solve(Node *p, Node *q, Node *r)
{
    if (p == NULL || p == r || p == q)
        return p;

    Node *x = solve(p->lchild, q, r);
    Node *y = solve(p->rchild, q, r);

    if (x == NULL)
        return y;
    else if (y == NULL)
        return x;
    else
        return p;
}
int Tree :: widthOfBinaryTree(Node *p)
{
    int ans = 0;
    queue<pair<Node *, int>> q;
    q.push({p, 0});
    while (!q.empty())
    {
        int x = q.size();
        int l, h;
        int mn = q.front().second;
        for (int i = 0; i < x; i++)
        {
            auto it = q.front();
            q.pop();
            p = it.first;
            long long int y = it.second - mn;
            if (i == 0)
                l = y;
            if (i == x - 1)
                h = y;
            if (p->lchild)
            {
                q.push({p->lchild, 2 * y + 1});
            }
            if (p->rchild)
            {
                q.push({p->rchild, 2 * y + 2});
            }
        }
        ans = max(ans, h - l + 1);
    }
    return ans;
}
int Tree :: Children_sum_prop(Node *p)
{
    if (p == NULL)
        return 0;
    int l, r;
    if (p->lchild)
        l = p->lchild->data;
    if (p->rchild)
        r = p->rchild->data;
    if (p->data >= (l + r))
    {
        p->lchild->data = p->data;
        p->rchild->data = p->data;
    }
    int x = Children_sum_prop(p->lchild);
    int y = Children_sum_prop(p->rchild);

    if ((x + y) >= p->data)
    {
        p->data = (x + y);
    }
    return p->data;
}
vector<int> Tree :: distanceK(Node *root, Node *target, int k)
{
    queue<Node *> q;
    unordered_map<Node *, Node *> mp;
    q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        if (p->lchild)
        {
            q.push(p->lchild);
            mp[p->lchild] = p;
        }
        if (p->rchild)
        {
            q.push(p->rchild);
            mp[p->rchild] = p;
        }
    }
    q.push(target);
    unordered_set<Node *> set1;
    set1.insert(target);
    while (true)
    {
        if (k == 0)
            break;
        k--;
        int z = q.size();
        for (int i = 0; i < z; i++)
        {
            Node *p = q.front();
            q.pop();
            if (p->lchild && set1.find(p->lchild) == set1.end())
            {
                q.push(p->lchild);
                set1.insert(p->lchild);
            }
            if (p->rchild && set1.find(p->rchild) == set1.end())
            {
                set1.insert(p->rchild);
                q.push(p->rchild);
            }
            if (mp.find(p) != mp.end() && set1.find(mp[p]) == set1.end())
            {
                set1.insert(mp[p]);
                q.push(mp[p]);
            }
        }
    }
    vector<int> v;
    while (!q.empty())
    {
        v.push_back(q.front()->data);
        q.pop();
    }
    return v;
}
int Tree :: LCA(Node *p, int x, int y)
{
    while (p)
    {
        if (x == p->data || y == p->data)
        {
            return p->data;
        }
        if (x > p->data && y > p->data)
        {
            p = p->rchild;
        }
        else if (x < p->data && y < p->data)
        {
            p = p->lchild;
        }
        else
        {
            return p->data;
        }
    }
}
int Tree :: Inorder_succ(Node *p, int key)
{
    int x = 0;
    while (p)
    {
        if (p->data > key)
        {
            x = p->data;
            p = p->lchild;
        }
        else
            p = p->rchild;
    }
    return x;
}
void Tree :: Morris_inorder(Node *root)
{
    Node *curr = root;
    while (curr)
    {
        if (curr->lchild == NULL)
        {
            cout << curr->data << " ";
            curr = curr->rchild;
        }
        else
        {
            Node *prev = curr->lchild;
            while (prev->rchild && prev->rchild != curr)
            {
                prev = prev->rchild;
            }
            if (prev->rchild == NULL)
            {
                prev->rchild = curr;
                prev = prev->lchild;
            }
            else
            {
                prev->rchild = NULL;
                cout << curr->data << " ";
                curr = curr->rchild;
            }
        }
    }
}
int main()
{
    return 0;
}
