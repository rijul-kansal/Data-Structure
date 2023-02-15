#include <bits/stdc++.h>
using namespace std;

class Sparse
{
    int n, m, no;
    int *a, *an, *am;

public:
    Sparse(int x, int y, int z)
    {
        m = x;
        n = y;
        no = z;
        a = new int[no];
        an = new int[n];
        am = new int[m];
    }
    void create()
    {
        for (int i = 0; i < no; i++)
        {
            cin >> am[i] >> an[i] >> a[i];
        }
    }
    void display()
    {
        int k = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (am[k] == i && an[k] == j)
                {
                    cout << a[k++] << " ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
    Sparse *operator+(Sparse &s)
    {
        Sparse *ss = new Sparse(m , n, no + s.no);

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < no && j < s.no)
        {
            if (am[i] < s.am[j])
            {
                ss->am[k] = am[i];
                ss->an[k] = an[i];
                ss->a[k++] = a[i++];
            }
            else if (am[i] > s.am[j])
            {
                ss->am[k] = s.am[j];
                ss->an[k] = s.an[j];
                ss->a[k++] = s.a[j++];
            }
            else
            {
                if (an[i] < s.an[j])
                {
                    ss->am[k] = am[i];
                    ss->an[k] = an[i];
                    ss->a[k++] = a[i++];
                }
                else if (an[i] > s.an[j])
                {
                    ss->am[k] = s.am[j];
                    ss->an[k] = s.an[j];
                    ss->a[k++] = s.a[j++];
                }
                else
                {
                    ss->am[k] = s.am[j];
                    ss->an[k] = s.an[j];
                    ss->a[k++] = s.a[j++] + a[i++];
                }
            }
        }
        ss->no=k;
        return ss;
    }
};

int main()
{
    class Sparse s1(5, 6, 5);
    s1.create();
    s1.display();
    class Sparse s2(5, 6, 5);
    s2.create();
    s2.display();
    class Sparse *s;
    s = s1 + s2;
    s->display();
    return 0;
}