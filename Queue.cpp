#include <bits/stdc++.h>
using namespace std;

class Queue_arr
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue_arr(int x);
    bool empty();
    bool full();
    void push(int x);
    int pop();
    void Display();
};
Queue_arr ::Queue_arr(int x)
{
    size = x;
    front = rear = -1;
    arr = new int[size];
}
bool Queue_arr ::empty()
{
    if (rear == front)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Queue_arr ::full()
{
    if (rear == size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Queue_arr ::push(int x)
{
    if (full())
    {
        return;
    }
    rear++;
    arr[rear] = x;
}
int Queue_arr ::pop()
{
    if (empty())
    {
        return -1;
    }
    front++;
    return arr[front];
}
void Queue_arr ::Display()
{
    for (int i = front + 1; i <= rear; i++)
    {
        cout << arr[i] << " ";
    }
}
class CircularQueue_arr
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue_arr(int x);
    bool empty();
    bool full();
    void push(int x);
    int pop();
    void Display();
};
CircularQueue_arr ::CircularQueue_arr(int x)
{
    size = x;
    front = rear = 0;
    arr = new int[size];
}
bool CircularQueue_arr ::empty()
{
    if (rear == front)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool CircularQueue_arr ::full()
{
    if ((rear + 1) % size == front)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void CircularQueue_arr ::push(int x)
{
    if (full())
    {
        return;
    }
    rear = (rear + 1) % size;
    arr[rear] = x;
}
int CircularQueue_arr ::pop()
{
    if (empty())
    {
        return -1;
    }
    front = (front + 1) % size;
    return arr[front];
}
void CircularQueue_arr ::Display()
{
    int i = front + 1;
    do
    {
        cout << arr[i] << " ";
        i = (i + 1) % size;
    } while ((rear + 1) % size != i);
}

class Node
{
public:
    int data;
    Node *next;
};
class Queue_LL
{
    Node *front;
    Node *rear;

public:
    Queue_LL();
    bool empty();
    void push(int x);
    int pop();
    void Display();
};
Queue_LL ::Queue_LL()
{

    front = rear = NULL;
}
bool Queue_LL::empty()
{
    if (front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Queue_LL ::push(int x)
{
    Node *t = new Node;
    t->data = x;
    t->next = NULL;
    if (front == NULL)
    {
        front = rear = t;
        return;
    }
    rear->next = t;
    rear = t;
}
int Queue_LL ::pop()
{
    int x;
    if (empty())
    {
        return -1;
    }
    if (front == rear)
    {
        x = rear->data;
        delete rear;
        front = rear = NULL;
        return x;
    }
    else
    {
        x = front->data;
        Node *q = front;
        front = front->next;
        delete q;
        return x;
    }
}
void Queue_LL ::Display()
{
    Node *p = front;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

class Dequeue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Dequeue(int x);
    bool empty();
    bool full();
    void push_front(int x);
    void push_back(int x);
    int pop_front();
    int pop_back();
    void Display();
};
Dequeue ::Dequeue(int x)
{
    size = x;
    front = rear = -1;
    arr = new int[size];
}
bool Dequeue ::empty()
{
    if (rear == front)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Dequeue ::full()
{
    if (rear == size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Dequeue ::push_back(int x)
{
    if (full())
    {
        return;
    }
    rear++;
    arr[rear] = x;
}
void Dequeue ::push_front(int x)
{
    if (front == -1)
    {
        return;
    }
    arr[front] = x;
    front--;
}
int Dequeue ::pop_front()
{
    if (empty())
    {
        return -1;
    }
    front++;
    return arr[front];
}
int Dequeue ::pop_back()
{
    if (rear == -1)
    {
        return -1;
    }
    int x = arr[rear];
    rear--;
    return x;
}
void Dequeue ::Display()
{
    for (int i = front + 1; i <= rear; i++)
    {
        cout << arr[i] << " ";
    }
}

class Queue_stk
{
    stack<int> s1;
    stack<int> s2;

public:
    void pushQ(int x)
    {
        s1.push(x);
    }
    int popQ()
    {
        if (s2.empty())
        {
            if (s1.empty())
            {
                return -1;
            }
            else
            {
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
        }
        int x=s2.top();
        s2.pop();
        return x;
    }
};
int main()
{
    class Queue_LL q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.pop() << "^";
    cout << q.pop() << "^";
    cout << q.pop() << "^";
    cout << q.pop() << "^";
    q.Display();
    return 0;
}