// Shortest Path in Undirected Graph with Unit Weights
// distance array
// TC = O(V+E);
// SC = O(N) + O(N);

#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<int> adj[], int N, int src)
{
    vector<int> dist(N, INT_MAX);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto itr : adj[curr])
        {
            if (dist[curr] + 1 < dist[itr])
            {
                dist[itr] = dist[curr] + 1;
                q.push(itr);
            }
        }
    }

    for (auto itr : dist)
        cout << itr << " ";
}

int main()
{

    int V, E;
    int src;
    cout << "Enter Number of Vertices and Edges : ";
    cin >> V >> E;

    vector<int> adj[V + 1];

    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cout << "Enter Vertices : ";
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(v);
    }

    cout << "Enter Source Vertex : ";
    cin >> src;

    cout << "Distance of Other Vertex from Source Vertex " << endl;
    BFS(adj, V, src);

    return 0;
}
