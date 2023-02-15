#include <bits/stdc++.h>
using namespace std;

class Diagonal
{
    int *arr;
    int n;

public:
    Diagonal(int x);
    void Set(int i, int j, int k);
    int Get(int i, int j);
    void Display();
};
Diagonal ::Diagonal(int x)
{
    n = x;
    arr = new int[n];
}
void Diagonal ::Set(int i, int j, int k)
{
    if (i == j)
        arr[i - 1] = k;
}
int Diagonal ::Get(int i, int j)
{
    if (i == j)
        return arr[i - 1];
    else
        return 0;
}
void Diagonal ::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                cout << arr[i - 1] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
class LowerTriangular
{
    int *arr;
    int n;

public:
    LowerTriangular(int x);
    void Set(int i, int j, int k);
    int Get(int i, int j);
    void Display();
};
LowerTriangular ::LowerTriangular(int x)
{
    n = x;
    arr = new int[n * (n - 1) / 2];
}
void LowerTriangular ::Set(int i, int j, int k)
{
    if (i >= j)
        arr[i * (i - 1) / 2 + j - 1] = k;
    // arr[n*(j-1)+((j-1)*(j-2))/2+i-j]=k;
}
int LowerTriangular ::Get(int i, int j)
{
    if (i >= j)
        return arr[i * (i - 1) / 2 + j - 1];
    // return arr[n*(j-1)+((j-1)*(j-2))/2+i-j];
    else
        return 0;
}
void LowerTriangular ::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                cout << arr[i * (i - 1) / 2 + j - 1] << " ";
                // cout<<arr[n*(j-1)+((j-1)*(j-2))/2+i-j];
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
class UpperTriangular
{
    int *arr;
    int n;

public:
    UpperTriangular(int x);
    void Set(int i, int j, int k);
    int Get(int i, int j);
    void Display();
};
UpperTriangular ::UpperTriangular(int x)
{
    n = x;
    arr = new int[n * (n - 1) / 2];
}
void UpperTriangular ::Set(int i, int j, int k)
{
    if (i <= j)
        arr[j * (j - 1) / 2 + i - 1] = k;
    // arr[n*(i-1)+((i-1)*(i-2))/2+j-i]=k;
}
int UpperTriangular ::Get(int i, int j)
{
    if (i <= j)
        return arr[j * (j - 1) / 2 + i - 1];
    // return arr[n*(i-1)+((i-1)*(i-2))/2+j-i];
    else
        return 0;
}
void UpperTriangular ::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
            {
                cout << arr[j * (j - 1) / 2 + i - 1] << " ";
                // cout<<arr[n*(i-1)+((i-1)*(i-2))/2+j-i];
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
class TriDiagonal
{
    int *arr;
    int n;

public:
    TriDiagonal(int x);
    void Set(int i, int j, int k);
    int Get(int i, int j);
    void Display();
};
TriDiagonal ::TriDiagonal(int x)
{
    n = x;
    arr = new int[3 * n - 2];
}
void TriDiagonal ::Set(int i, int j, int k)
{
    if (i == j)
        arr[n + i - 2] = k;
    else if (i - j == 1)
    {
        arr[i - 2] = k;
    }
    else if (j - i == 1)
    {
        arr[2 * n + i - 2] = k;
    }
}
int TriDiagonal ::Get(int i, int j)
{
    if (i == j)
        return arr[n + i - 2];
    else if (i - j == 1)
    {
        return arr[i - 2];
    }
    else if (j - i == 1)
    {
        return arr[2 * n + i - 2];
    }
    else
        return 0;
}
void TriDiagonal ::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                cout << arr[n + i - 2] << " ";
            else if (i - j == 1)
            {
                cout << arr[i - 2] << " ";
            }
            else if (j - i == 1)
            {
                cout << arr[2 * n + i - 2] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
class Toepitz
{
    int *arr;
    int n;

public:
    Toepitz(int x);
    void Set(int i, int j, int k);
    int Get(int i, int j);
    void Display();
};
Toepitz::Toepitz(int x)
{
    n = x;
    arr = new int[2 * n - 1];
}
void Toepitz::Set(int i, int j, int k)
{
    if (i <= j)
        arr[j - i] = k;
    else if (i > j)
    {
        arr[n + i - j - 1] = k;
    }
}
int Toepitz ::Get(int i, int j)
{
    if (i <= j)
        return arr[j - i];
    else if (i > j)
    {
        return arr[n + i - j - 1];
    }
    else
        return 0;
}
void Toepitz ::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
                cout << arr[j - i] << " ";
            else if (i > j)
            {
                cout << arr[n + i - j - 1] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main()
{
    return 0;
}