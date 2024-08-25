#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    int vis[V] = {0};
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    vector<int> bfs;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.emplace_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main()
{
    int n, m;
    cin >> n >> m;

    // //take input O(N^2) space complexity

    // adjcacency matrix
    int adj[n + 1][n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // adjacency list
    // O(2E) = O(E)
    vector<int> adj_list[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].emplace_back(v);
        adj_list[v].emplace_back(u);
    }

    return 0;
}