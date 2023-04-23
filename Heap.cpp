#include <bits/stdc++.h>
using namespace std;
// Tc will be O(LogN)
void Insert(vector<int> &arr, int key)
{
    arr.push_back(key);
    int i = arr.size() - 1;
    while (i >= 0)
    {
        if (arr[i % 2 == 0 ? i / 2 - 1 : i / 2] < arr[i])
        {
            swap(arr[i], arr[i % 2 == 0 ? i / 2 - 1 : i / 2]);
            i = i % 2 == 0 ? i / 2 - 1 : i / 2;
        }
        else
        {
            break;
        }
    }
}
// Tc will be O(NLogN)
void Insert_Implace(vector<int> &arr, int id)
{
    for (int i = id; i < arr.size(); i++)
    {
        int idx = i;
        while (idx >= 0)
        {
            if (arr[idx % 2 == 0 ? idx / 2 - 1 : idx / 2] < arr[idx])
            {
                swap(arr[idx], arr[idx % 2 == 0 ? idx / 2 - 1 : idx / 2]);
                idx = idx % 2 == 0 ? idx / 2 - 1 : idx / 2;
            }
            else
            {
                break;
            }
        }
    }
}
// Tc will be O(LogN)
int Delete(vector<int> &v)
{
    int x = v[0];
    v[0] = v.back();
    v.pop_back();
    int n = v.size();
    int i = 0;

    while (i < n)
    {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        if (left < n && v[left] >= v[right])
        {
            swap(v[left], v[i]);
            i = left;
        }
        else if (right < n && v[left] < v[right])
        {
            swap(v[right], v[i]);
            i = right;
        }
        else
        {
            break;
        }
    }
    return x;
}
void Heapify(vector<int> &v)
{
    int n = v.size();
    for (int idx = n / 2 - 1; idx >= 0; idx--)
    {
        int i=idx;
        while (i < n)
        {
            int left = i * 2 + 1;
            int right = i * 2 + 2;
            if (left < n && v[left] >= v[right])
            {
                swap(v[left], v[i]);
                i = left;
            }
            else if (right < n && v[left] < v[right])
            {
                swap(v[right], v[i]);
                i = right;
            }
            else
            {
                break;
            }
        }
    }
}
int main()
{
    vector<int> h = {10, 20, 30, 25, 5, 40, 35};
    Heapify(h);
    for (auto x : h)
    {
        cout << x << " ";
    }
    return 0;
}