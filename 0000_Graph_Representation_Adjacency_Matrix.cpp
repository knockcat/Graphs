#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter number of Nodes and number of Edges : ";
    cin >> n >> m;

    vector<vector<int>> g(n + 1, vector<int>(n + 1));

    for (int i = 0; i < m; ++i)
    {
        cout << "Enter Edges : ";
        int u, v;
        cin >> u >> v;

        g[u][v] = 1;
        g[v][u] = 1;
    }

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}