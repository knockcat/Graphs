// Detect a Cycle in a Directed Graph

// we have to use a self dfs along with the visited dfs

#include <iostream>
#include <vector>
using namespace std;

bool CheckForCycle(int sv, vector<int> adj[], vector<int> &visited, vector<int> &dfsvisited)
{
    visited[sv] = 1;
    dfsvisited[sv] = 1;

    for (auto itr : adj[sv])
    {
        if (!visited[itr])
        {
            if (CheckForCycle(itr, adj, visited, dfsvisited))
                return true;
        }
        else if (dfsvisited[itr])
            return true;
    }
    dfsvisited[sv] = false;
    return false;
}

bool isCyclic(int n, vector<int> adj[])
{
    vector<int> visited(n, false), dfsvisited(n, false);

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            if (CheckForCycle(i, adj, visited, dfsvisited))
                return true;
        }
    }

    return false;
}

int main()
{
    int n, m;
    cout << "Enter Number of Nodes and Number of Edges : ";
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cout << "Enter Vertices : ";
        cin >> u >> v;

        adj[u].push_back(v);
    }

    int ans = isCyclic(n, adj);

    if (ans)
        cout << "Graph Contains a Cycle ---";
    else
        cout << "Graph Doesn't Contains a Cycle ---";
    return 0;
}
