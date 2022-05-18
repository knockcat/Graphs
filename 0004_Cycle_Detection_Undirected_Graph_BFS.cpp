// CYCLE DETECTION IN UNDIRECTED GRAPH USING BFS

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool CheckForCycle(int sv, vector<int> adj[], vector<bool> visited)
{
    queue<pair<int, int>> q;

    visited[sv] = true;
    q.push({sv, -1});

    while (!q.empty())
    {
        int curr = q.front().first;
        int prev = q.front().second;

        q.pop();

        for (auto itr : adj[curr])
        {
            if (!visited[itr])
            {
                visited[itr] = true;
                q.push({itr, curr});
            }
            else if (itr != prev)
                return true;
        }
    }
    return false;
}

bool isCycle(int n, vector<int> adj[])
{
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            if (CheckForCycle(i, adj, visited))
                return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cout << "Enter Number of Nodes & Edges : ";
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; ++i)
    {
        cout << "Enter Vertices : ";
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isCycle(n, adj))
        cout << "Input Graph Contains a Cycle ..." << endl;
    else
        cout << "Input Graph Doesn't Contains a Cycle ..." << endl;

    return 0;
}