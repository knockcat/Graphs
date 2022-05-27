// Detect Cycle in Directed Graph ( BFS ) [Kahn's Algorithm]

// we know topological sort is only possible for Directed Acyclic Graph,
// therfore if we unable to generate the topological sort by using Kahn's Algorithm.
// that means the graph contains a Cycle.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool Detect_Cycle(vector<int> adj[], int V)
{
    vector<int> indegree(V, 0);
    vector<int> topo;
    queue<int> q;
    int cnt = 0;

    for (int i = 0; i < V; ++i)
    {
        for (auto itr : adj[i])
            ++indegree[itr];
    }

    for (int i = 0; i < V; ++i)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        ++cnt;

        for (auto itr : adj[curr])
        {
            --indegree[itr];
            if (indegree[itr] == 0)
                q.push(itr);
        }
    }

    return cnt == V;
}

int main()
{
    int V, E;
    cout << "Enter Number of Vertices and Edges : ";
    cin >> V >> E;

    vector<int> adj[V + 1];

    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cout << "Enter Vertices : ";
        cin >> u >> v;
        adj[u].push_back(v);
    }

    bool ans = Detect_Cycle(adj, V);

    if (!ans)
        cout << "Cycle Exist --------" << endl;
    else
        cout << "No Cycle ---------" << endl;

    return 0;
}