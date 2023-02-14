#include <bits/stdc++.h>
using namespace std;

class Array
{
    int size;
    int n;
    int *arr;

public:
    Array(int n);
    void No_of_ele();
    void Create();
    void Display();
    void Append(int key);
    void Insert(int index, int key);
    int Delete(int);
    int Linear_search(int key);
    int Linear_search_trans(int key);
    int Linear_search_move(int key);
    int Binary_search_I(int key);
    int Binary_search_R(int l, int h, int key);
    int Get(int index);
    int Set(int index, int key);
    int Max();
    int Min();
    int Sum();
    double Avg();
    void Reversing_1();
    void Reversing_2();
    void Inserted_sorted(int key);
    int Check_sorted();
    void Rearrange();
    Array operator+(Array &a);
    Array Union(Array &a);
    Array Inter_section(Array &a);
    Array Difference(Array &a);
    void Missing_sorted();
    void Missing_unsorted();
    void Duplicate_sorted();
    void Duplicate_sorted_hashing();
    void Duplicate_unsorted();
    void pairing(int k);
    void pairing_hashing(int k);
    void pairing_sorted(int k);
};
// TC will ne O(1)
Array ::Array(int n)
{
    size = n;
    arr = new int[n];
}
// TC will ne O(1)
void Array ::No_of_ele()
{
    cout << "NO of ele ";
    cin >> n;
}
// TC will ne O(1)
void Array ::Create()
{
    cout << "Enter " << n << " Elements ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
// TC will ne O(1)
void Array ::Display()
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// TC will be O(1)
void Array ::Append(int key)
{
    if (n < size)
    {
        arr[n] = key;
        n++;
    }
}
// TC will be O(N)
void Array ::Insert(int index, int key)
{
    if (index >= 0 && index <= n && n < size)
    {
        for (int i = n - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = key;
        n++;
    }
}
// TC will be O(N)
int Array ::Delete(int index)
{
    int x = -1;
    if (index >= 0 && index < n)
    {
        x = arr[index];
        for (int i = index; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        n--;
    }
    return x;
}
// TC will be O(N)
int Array ::Linear_search(int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}
// TC will be O(N)
int Array ::Linear_search_trans(int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            if (i == 0)
            {
                return 0;
            }
            else
            {
                swap(arr[i], arr[i - 1]);
                return i - 1;
            }
        }
    }
    return -1;
}
// TC will be O(N)
int Array ::Linear_search_move(int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            if (i == 0)
            {
                return 0;
            }
            else
            {
                swap(arr[i], arr[0]);
                return 0;
            }
        }
    }
}
// TC will be O(log N)
int Array ::Binary_search_I(int key)
{
    int l = 0;
    int h = n - 1;
    int mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}
// TC will be O(log N)
int Array ::Binary_search_R(int l, int h, int key)
{
    int mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            Binary_search_R(l, mid - 1, key);
        }
        else
        {
            Binary_search_R(mid + 1, h, key);
        }
    }
    return -1;
}
// TC will be O(1)
int Array ::Get(int index)
{
    if (index >= 0 && index < n)
    {
        return arr[index];
    }
}
// TC will be O(1)
int Array ::Set(int index, int key)
{
    if (index >= 0 && index < n)
    {
        arr[index] = key;
    }
}
// TC will be O(N)
int Array ::Max()
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > mx)
        {
            mx = arr[i];
        }
    }
    return mx;
}
// TC will be O(N)
int Array ::Min()
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < mx)
        {
            mx = arr[i];
        }
    }
    return mx;
}
// TC will be O(N)
int Array ::Sum()
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
    }
    return s;
}
// TC will be O(N)
double Array ::Avg()
{
    return static_cast<double>(Sum()) / n;
}
//  Tc will be O(N)
void Array ::Reversing_1()
{
    int *b = new int[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = arr[n - 1 - i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = b[i];
    }
    delete[] b;
}
//  Tc will be O(N)
void Array ::Reversing_2()
{
    for (int i = 0; i < n / 2; i++)
    {
        swap(arr[i], arr[n - i - 1]);
    }
}
//  Tc will be O(N)
void Array ::Inserted_sorted(int key)
{
    if (n == size)
        return;
    int i = n - 1;
    while (i >= 0 && key < arr[i])
    {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = key;
    n++;
}
//  Tc will be O(N)
int Array ::Check_sorted()
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] < arr[i])
            return false;
    }
    return true;
}
//  Tc will be O(N)
void Array ::Rearrange()
{
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        while (arr[i] < 0)
            i++;
        while (arr[j] > 0)
            j--;
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
}
//  Tc will be O(N+M)
Array Array ::operator+(Array &a)
{
    Array *aa = new Array(n + a.n);
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n && j < a.n)
    {
        if (arr[i] < a.arr[j])
        {
            aa->arr[k++] = arr[i++];
        }
        else if (arr[i] > a.arr[j])
        {
            aa->arr[k++] = a.arr[j++];
        }
        else
        {
            aa->arr[k++] = arr[i++];
            j++;
        }
    }

    for (; i < n; i++)
    {
        aa->arr[k++] = arr[i];
    }
    for (; j < a.n; j++)
    {
        aa->arr[k++] = a.arr[j];
    }
    aa->n = k;
    return *aa;
}
//  Tc will be O(N+M)
Array Array ::Union(Array &a)
{
    Array *aa = new Array(n + a.n);
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n && j < a.n)
    {
        if (arr[i] < a.arr[j])
        {
            aa->arr[k++] = arr[i++];
        }
        else if (arr[i] > a.arr[j])
        {
            aa->arr[k++] = a.arr[j++];
        }
        else
        {
            aa->arr[k++] = arr[i++];
            j++;
        }
    }

    for (; i < n; i++)
    {
        aa->arr[k++] = arr[i];
    }
    for (; j < a.n; j++)
    {
        aa->arr[k++] = a.arr[j];
    }
    aa->n = k;
    return *aa;
}
//  Tc will be O(N+M)
Array Array ::Inter_section(Array &a)
{
    Array *aa = new Array(n + a.n);
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n && j < a.n)
    {
        if (arr[i] < a.arr[j])
        {
            i++;
        }
        else if (arr[i] > a.arr[j])
        {
            j++;
        }
        else
        {
            aa->arr[k++] = arr[i++];
            j++;
        }
    }
    aa->n = k;
    return *aa;
}
//  Tc will be O(N+M)
Array Array ::Difference(Array &a)
{
    Array *aa = new Array(n + a.n);
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n && j < a.n)
    {
        if (arr[i] > a.arr[j])
        {
            j++;
        }
        else if (arr[i] < a.arr[j])
        {
            aa->arr[k++] = arr[i++];
        }
        else
        {
            i++;
        }
    }
    aa->n = k;
    return *aa;
}
//  Tc will be O(N)
void Array ::Missing_sorted()
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] - arr[i] != 1)
        {
            int x = arr[i + 1] - arr[i];
            int ii = 1;
            while (ii < x)
            {
                cout << arr[i] + ii << " ";
                ii++;
            }
        }
    }
}
//  Tc will be O(N)
void Array ::Missing_unsorted()
{
    int x = Max();
    int xx = Min();
    int hash[x + 1]{0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    for (int i = xx; i <= x; i++)
    {
        if (hash[i] == 0)
        {
            cout << i << " ";
        }
    }
}
//  Tc will be O(N)
void Array ::Duplicate_sorted()
{
    for (int i = 0; i < n - 1; i++)
    {
        int count = 1;
        if (arr[i + 1] == arr[i])
        {
            int j = i + 1;
            while (arr[j] == arr[i])
            {
                count++;
                j++;
            }
            i = j - 1;
        }
        if (count > 1)
        {
            cout << arr[i] << " " << count << endl;
        }
    }
}
//  Tc will be O(N)
void Array ::Duplicate_sorted_hashing()
{
    int x = Max();
    int hash[x + 1]{0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    for (int i = 0; i <= x; i++)
    {
        if (hash[i] > 1)
        {
            cout << i << " " << hash[i] << endl;
        }
    }
}
//  Tc will be O(N^2)
void Array ::Duplicate_unsorted()
{
    for (int i = 0; i < n - 1; i++)
    {
        int c = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] != -1)
            {
                if (arr[i] == arr[j])
                {
                    c++;
                    arr[j] = -1;
                }
            }
        }
        if (c > 1)
        {
            cout << c << " " << arr[i] << endl;
        }
    }
}
//  Tc will be O(N^2)
void Array ::pairing(int k)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n - 1; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                cout << arr[i] << " " << arr[j] << endl;
            }
        }
    }
}
//  Tc will be O(N)
void Array ::pairing_hashing(int k)
{
    int x = Max();
    int hash[x + 1]{0};
    for (int i = 0; i < n; i++)
    {
        if (hash[k - arr[i]] != 0)
        {
            cout << arr[i] << " " << k - arr[i] << endl;
        }
        hash[arr[i]]++;
    }
}
//  Tc will be O(N)
void Array ::pairing_sorted(int k)
{
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        if (arr[i] + arr[j] == k)
        {
            cout << arr[i] << " " << arr[j] << endl;
            i++;
            j++;
        }
        else if (arr[i] + arr[j] < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}
int main()
{
    return 0;
}