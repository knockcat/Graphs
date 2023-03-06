// Kruskal's Algorithm for Minimum Spanning Tree

// Sort All The Edges According to their waits
// then we will check if we have edge already in the same component
// if it than we will not add that edge othewise we will add that edge
// unionByRank and unionBySize both can be used but unionBySize is mostly used
// when we add the edge we will also add the edges to mst(tree vector) and keep tract of mstWt.

// TC : O(N + E) + O(N Log M) + O(m X 4 X alpha X 2)
// SC : O(M)

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class DSU
{
public:
    int N;
    vector<T> rank, parent, size;
    DSU(int n)
    {
        N = n;
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (T i = 0; i <= n; ++i)
        {
            parent[i] = i;
        }
    }

    template <typename X>
    X findParent(X u)
    {
        if (u == parent[u])
            return u;
        return parent[u] = findParent(parent[u]);
    }

    // Not be using unionByRank
    // but yes for future reference
    template <typename X>
    void unionByRank(X u, X v)
    {
        int nodeX = findParent(u);
        int nodeY = findParent(v);

        if (nodeX == nodeY)
            return;

        if (rank[nodeX] < rank[nodeY])
        {
            parent[nodeX] = nodeY;
        }
        else if (rank[nodeY] < rank[nodeX])
        {
            parent[nodeY] = nodeX;
        }
        else
        {
            parent[nodeY] = nodeX;
            ++rank[nodeX];
        }
    }

    void unionBySize(int u, int v)
    {
        int nodeX = findParent(u);
        int nodeY = findParent(v);

        if (nodeX == nodeY)
            return;

        if (size[nodeX] < size[nodeY])
        {
            parent[nodeX] = nodeY;
            size[nodeY] += size[nodeX];
        }
        else
        {
            parent[nodeY] = nodeX;
            size[nodeX] += size[nodeY];
        }
    }

    template <typename X>
    bool isSame(X u, X v)
    {
        return findParent(u) == findParent(v);
    }
};

int main()
{
    cout << "Enter the Number of Nodes and Edges : " << endl;
    int V, E;
    cin >> V >> E;

    vector<pair<int, int>> adj[V + 1];

    int ans = 1e9;

    for (int i = 0; i < E; ++i)
    {
        int u, v, wt;
        cout << "Enter Vertices and weight (u , v, w): ";
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        // adj[v].push_back({u, wt});
    }

    // Making tuple  seperately assuming graph exist as adjacency list
    // but I can take input as tuple also

    vector<tuple<int, int, int>> G;

    // O(N + E)
    for (int i = 0; i < V; ++i)
    {
        for (auto itr : adj[i])
        {
            int u = i;
            int v = itr.first;
            int wt = itr.second;
            G.push_back(make_tuple(wt, u, v));
        }
    }

    // O(N Log M)
    // sort edges as per waits
    sort(G.begin(), G.end());

    int mstWt = 0;
    vector<int> mst;

    DSU<int> dsu(V);

    for (auto itr : G)
    {
        int wt = get<0>(itr);
        int u = get<1>(itr);
        int v = get<2>(itr);

        // O(m X 4 X alpha X 2)
        if (dsu.isSame(u, v))
            continue;
        else
        {
            mstWt += wt;
            dsu.unionBySize(u, v);
            mst.push_back(u);
            mst.push_back(v);
        }
    }

    cout << "Minimum Spanning Tree is : " << endl;
    for (auto itr : mst)
        cout << itr << " ";
    cout << endl;
    cout << "Minimum Weight of MST : " << mstWt << endl;
}
