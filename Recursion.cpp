#include <bits/stdc++.h>
using namespace std;
// Tc will be O(N)
void Tail_R(int n)
{
    if (n)
    {
        cout << n << " ";
        Tail_R(n - 1);
    }
}
// Tc will be O(N)
void Head_R(int n)
{
    if (n)
    {
        Head_R(n - 1);
        cout << n << " ";
    }
}
// int x=0;
int Static_Global(int n)
{
    static int x = 0;
    if (n)
    {
        x++;
        return Static_Global(n - 1) + x;
    }
    return 0;
}
// Tc will be O(2^N)
void Tree_R(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        Tree_R(n - 1);
        Tree_R(n - 1);
    }
}
void Indirect_R_1(int n);
void Indirect_R_Main(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        Indirect_R_1(n - 1);
    }
}
void Indirect_R_1(int n)
{
    if (n > 1)
    {
        cout << n << " ";
        Indirect_R_Main(n / 2);
    }
}

int Nested_R(int n)
{
    if (n > 100)
    {
        return n - 10;
    }
    else
    {
        return Nested_R(Nested_R(n + 11));
    }
}

// TC will be O(N)
int Sum_R(int n)
{
    if (n == 0)
        return 0;
    return Sum_R(n - 1) + n;
}
// TC will be O(N)
int Sum_I(int n)
{
    int x = 1;
    for (int i = 2; i <= n; i++)
    {
        x += i;
    }
    return x;
}
// TC will be O(1)
int Sum(int n)
{
    return (n * (n + 1)) / 2;
}
// TC will be O(N)
int Factorial_R(int n)
{
    if (n == 0)
        return 1;
    return Factorial_R(n - 1) * n;
}
// TC will be O(N)
int Factorial_I(int n)
{
    int x = 1;
    for (int i = 2; i <= n; i++)
    {
        x *= i;
    }
    return x;
}
// TC will be O(N)
int Power_R_1(int m, int n)
{
    if (n == 0)
        return 1;
    return Power_R_1(m, n - 1) * m;
}
// TC will be O(Log N)
int Power_R_2(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        return Power_R_2(m * m, n / 2);
    }
    else
    {
        return Power_R_2(m * m, (n - 1) / 2) * m;
    }
}
double Taylor_Series_R_1(double x, int n)
{
    static double p = 1;
    static double f = 1;
    double r;

    if (n == 0)
        return 1;
    else
    {
        r = Taylor_Series_R_1(x, n - 1);
        p *= x;
        f *= n;
        return r + static_cast<double>(p) / f;
    }
}
// TC will be O(N)
double Taylor_Series_I(double x, int n)
{
    double s = 1;
    while (n > 0)
    {
        s = 1 + (x / n) * s;
        n--;
    }
    return s;
}
// TC will be O(N)
double Taylor_Series_R_2(double x, int n)
{
    static double s = 1;
    if (n == 0)
    {
        return s;
    }
    else
    {
        s = 1 + (x / n) * s;
        return Taylor_Series_R_2(x, n - 1);
    }
}
// TC will be O(2^N)
int Fibonachhi_No_R(int n)
{
    if (n < 2)
        return n;
    else
        return Fibonachhi_No_R(n - 2) + Fibonachhi_No_R(n - 1);
}
// TC will be O(N)
int Fibonachhi_No_I(int n)
{
    if (n < 2)
        return n;
    int to = 0;
    int t1 = 1;
    int s;
    for (int i = 0; i < n - 2; i++)
    {
        s = to + t1;
        to = t1;
        t1 = s;
    }
    return s;
}
// TC will be O(N)
int arr[10];
int Fibonachhi_No_M(int n)
{
    if (n <= 1)
    {
        arr[n] = n;
        return n;
    }

    if (arr[n - 2] == -1)
    {
        arr[n - 2] = Fibonachhi_No_M(n - 2);
    }
    if (arr[n - 1] == -1)
    {
        arr[n - 1] = Fibonachhi_No_M(n - 1);
    }
    return arr[n - 2] + arr[n - 1];
}
int NCR_1(int n, int r)
{
    return Factorial_I(n) / (Factorial_I(n - r) * Factorial_I(r));
}
int NCR_2(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    return NCR_2(n - 1, r - 1) + NCR_2(n - 1, r);
}
void TOH(int n, int a, int b, int c)
{
    if (n)
    {
        TOH(n - 1, a, c, b);
        cout << "(" << a << "," << c << ")" << endl;
        TOH(n - 1, b, a, c);
    }
}
int main()
{
    TOH(3,1,2,3);
    return 0;
}