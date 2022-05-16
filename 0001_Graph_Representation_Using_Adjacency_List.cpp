// Graph Representation Adjacency List

#include <iostream>
#include <vector>
using namespace std;

void adjacencylist(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << i << "->";
        for (int &x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    cout << "Enter number of Nodes and number of Edges : ";
    cin >> n >> m;

    vector<int> g[n + 1];              // for storing edges
    vector<pair<int, int>> adj[n + 1]; // storing edges with waits

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    /* For a Waited Graph

    for (int i = 0; i < m; ++i)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    */

    cout << "Printing Graph as Adjacency List " << endl;
    adjacencylist(g, n + 1);

    return 0;
}