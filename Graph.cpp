#include <bits/stdc++.h>
using namespace std;

void BFS(int graph[101][101], int u, int n)
{
    int vis[n + 1]{0};
    vis[u] = 1;
    queue<int> q;
    q.push(u);
    cout << u << " ";

    while (!q.empty())
    {
        u = q.front();
        q.pop();
        // cout<<u<<" ";
        for (int v = 1; v <= n; v++)
        {
            // cout << vis[v] << " " << u << " " << v << " " << graph[u][v] << endl;
            if (vis[v] == 0 && graph[u][v] == 1)
            {
                cout << v << " ";
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}
void DFS(int graph[101][101], int u, int n, int vis[])
{
    cout << u << " ";
    if (vis[u] != 1)
    {
        vis[u] = 1;
        for (int v = 0; v < n; v++)
        {
            if (vis[v] == 0 && graph[u][v] == 1)
            {
                DFS(graph, v, n, vis);
            }
        }
    }
}
int main()
{
    int arr[101][101] =
        {
            {0, 1, 0, 0, 1, 0, 1},
            {1, 0, 1, 0, 0, 1, 0},
            {0, 1, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 1, 0, 0},
            {1, 0, 0, 1, 0, 1, 1},
            {0, 1, 1, 0, 1, 0, 0},
            {1, 0, 0, 0, 1, 0, 0},
        };
    int vis[7]{0};
    DFS(arr, 0, 7,vis);
    return 0;
}