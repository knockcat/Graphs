// Topological Sorting

// (Linear Ordering of vertices such that if their is a edge from u -> v , u appears before v in that ordering )

//  Topological Sort is applicable for Directed Acyclic Graph

// BFS

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topoSort(int n, vector<int> adj[])
{
    queue<int> q;
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; ++i)
    {
        for (auto itr : adj[i])
            ++indegree[itr];
    }

    for (int i = 0; i < n; ++i)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        topo.push_back(curr);
        for (auto itr : adj[curr])
        {
            --indegree[itr];
            if (indegree[itr] == 0)
                q.push(itr);
        }
    }

    return topo;
}

int main()
{
    int n, m;
    cout << "Enter Number of Nodes and Edges : ";
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cout << "Enter Vertices : ";
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> ans = topoSort(n, adj);

    cout << "Topological Sort " << endl;
    for (int i : ans)
        cout << i << " ";

    return 0;
}
