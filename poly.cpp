#include <bits/stdc++.h>
using namespace std;

class Poly
{
    int n;
    int *coff, *poww;

public:
    Poly(int x)
    {
        n = x;
        coff = new int[n];
        poww = new int[n];
    }
    void create()
    {
        for (int i = 0; i < n; i++)
        {
            cin >> coff[i] >> poww[i];
        }
    }
    void display()
    {
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            cout << coff[i] << "*x^" << poww[i] << " + ";
        }
    }
    Poly *operator+(Poly &s)
    {
        Poly *ss = new Poly(n + s.n);

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < n && j < s.n)
        {
            if (poww[i] > s.poww[j])
            {
                ss->coff[k] = coff[i];
                ss->poww[k++] = poww[i++];
            }
            else if (poww[i] < s.poww[j])
            {
                ss->coff[k] = s.coff[j];
                ss->poww[k++] = s.poww[j++];
            }
            else
            {
                ss->coff[k] = s.coff[j] + coff[i++];
                ss->poww[k++] = s.poww[j++];
            }
        }
        ss->n=k;
        return ss;
    }
};

int main()
{
    class Poly s1(5);
    s1.create();
    s1.display();
    class Poly s2(4);
    s2.create();
    s2.display();
    class Poly *s;
    s = s1 + s2;
    s->display();
    return 0;
}
