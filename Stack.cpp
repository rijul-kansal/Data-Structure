#include <bits/stdc++.h>
using namespace std;

class Stack_arr
{
    int *arr;
    int top;
    int size;

public:
    Stack_arr(int x);
    bool empty();
    bool full();
    void push(int x);
    void pop();
    int peek(int index);
    int stacktop();
    void display();
};
Stack_arr ::Stack_arr(int x)
{
    top = -1;
    size = x;
    arr = new int[size];
}
bool Stack_arr ::empty()
{
    if (top == -1)
        return true;
    else
        return false;
}
bool Stack_arr ::full()
{
    if (top == size - 1)
        return true;
    else
        return false;
}
void Stack_arr ::push(int x)
{
    if (full())
        return;

    top++;
    arr[top] = x;
}
void Stack_arr ::pop()
{
    if (empty())
        return;

    top--;
}
int Stack_arr ::peek(int index)
{
    if (top - index + 1 < 0 || top - index + 1 == size)
        return -1;

    return arr[top - index + 1];
}
int Stack_arr ::stacktop()
{
    if (empty())
        return -1;
    else
        return arr[top];
}
void Stack_arr ::display()
{
    for (int i = top; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
}
class Node
{
public:
    int data;
    Node *next;
};
class Stack_LL
{
    Node *top;

public:
    Stack_LL();
    bool empty();
    void push(int x);
    void pop();
    int peek(int index);
    int stacktop();
    void display();
};
Stack_LL ::Stack_LL()
{
    top = NULL;
}
bool Stack_LL ::empty()
{
    if (top == NULL)
        return true;
    else
        return false;
}
void Stack_LL ::push(int x)
{
    Node *t = new Node;
    t->data = x;
    if (top == NULL)
    {
        top = t;
        t->next = NULL;
    }
    else
    {
        t->next = top;
        top = t;
    }
}
void Stack_LL ::pop()
{
    if (empty())
        return;

    Node *q = top;
    top = top->next;
    delete q;
}
int Stack_LL ::peek(int index)
{
    Node *p = top;
    for (int i = 0; i < index - 1 && p; i++)
    {
        p = p->next;
    }
    if (p)
        return p->data;
    else
        return -1;
}
int Stack_LL ::stacktop()
{
    if (empty())
        return -1;
    else
        return top->data;
}
void Stack_LL ::display()
{
    Node *p = top;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int Parenthesis_matching(string s)
{
    stack<char> stk;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stk.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (stk.empty())
                return false;
            if (s[i] == ')' && stk.top() == '(')
            {
                stk.pop();
            }
            else if (s[i] == ']' && stk.top() == '[')
            {
                stk.pop();
            }
            else if (s[i] == '}' && stk.top() == '{')
            {
                stk.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (stk.empty())
        return true;
    else
        return false;
}
int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else
        return -1;
}
string Convert_inTopost(string s)
{
    stack<char> stk;
    string res;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9'))
        {
            res += s[i];
        }
        else if (s[i] == '(')
        {
            stk.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (stk.top() != '(')
            {
                res += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else
        {
            while (!stk.empty() && precedence(s[i]) <= precedence(stk.top()))
            {
                res += stk.top();
                stk.pop();
            }
            stk.push(s[i]);
        }
    }
    while (!stk.empty())
    {
        res.push_back(stk.top());
        stk.pop();
    }
    return res;
}

int Eval(string s)
{
    stack<int> stk;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            stk.push(s[i] - '0');
        }
        else
        {
            char x = s[i];
            int x1, x2, r;
            x1 = stk.top();
            stk.pop();
            x2 = stk.top();
            stk.pop();
            switch (x)
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x2 - x1;
                break;
            case '*':
                r = x1 * x2;
                break;
            case '/':
                r = x2 / x1;
                break;
            }
            stk.push(r);
        }
    }
    return stk.top();
}
int main()
{
    string s;
    cin >> s;
    cout <<Eval(s);
    return 0;
}