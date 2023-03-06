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
// DSU<int> dsu(n);

// dsu.unionByRank(u, v);
// dsu.unionBySize(u,v);
// dsu.isSame(u, v) bool

int main()
{
    DSU<int> dsu(7);

    // dsu.unionByRank(1, 2);
    // dsu.unionByRank(2, 3);
    // dsu.unionByRank(4, 5);
    // dsu.unionByRank(6, 7);
    // dsu.unionByRank(5, 6);

    // if (dsu.findParent(3) == dsu.findParent(7))
    //     cout << "Same"<<endl;
    // else
    //     cout << "Not Same" << endl;

    // dsu.unionByRank(3, 7);

    // if (dsu.findParent(3) == dsu.findParent(7))
    //     cout << "Same"<<endl;
    // else
    //     cout << "Not Same" << endl;

    dsu.unionBySize(1, 2);
    dsu.unionBySize(2, 3);
    dsu.unionBySize(4, 5);
    dsu.unionBySize(6, 7);
    dsu.unionBySize(5, 6);

    cout << (dsu.isSame(3, 7) ? "Same" : "Not Same") << endl;

    dsu.unionBySize(3, 7);

    cout << (dsu.isSame(3, 7) ? "Same" : "Not Same") << endl;

    return 0;
}