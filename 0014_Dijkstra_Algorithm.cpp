// Dijkstra Algorithm - Single Source Shortest Path Algorithm
// TC = O(V+E);
// SC = O(N) + O(N) +O(V)
// Auxiliary Space: O(V)

#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<pair<int, int>> adj[], int &ans, int n, int k, int dest)
{
    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, 1e9);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, k});
    dist[k] = 0;

    while (!pq.empty())
    {
        int curr = pq.top().second;
        pq.pop();

        if (visited[curr])
            continue;

        visited[curr] = true;

        for (auto child : adj[curr])
        {
            int child_v = child.first;
            int wt = child.second;

            if (dist[curr] + wt < dist[child_v])
            {
                dist[child_v] = dist[curr] + wt;
                pq.push({dist[child_v], child_v});
            }
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);

    cout << endl;
    ans = dist[dest];
}

int main()
{
    int V, E;
    int src, dest;
    cout << "Enter Number of Vertices and Edges : ";
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

    cout << "Enter Source Vertex : ";
    cin >> src;

    cout << "Enter Distance Vertex : ";
    cin >> dest;
    cout << "Distance of dist Vertex from Source Vertex ";
    dijkstra(adj, ans, V, src, dest);
    cout << ans << endl;
    return 0;
}

/*
Enter Number of Vertices and Edges : 9 14
Enter Vertices and weight (u , v, w): 0 1 4
Enter Vertices and weight (u , v, w): 0 7 8
Enter Vertices and weight (u , v, w): 1 2 8
Enter Vertices and weight (u , v, w): 1 7 11
Enter Vertices and weight (u , v, w): 2 3 7
Enter Vertices and weight (u , v, w): 2 8 2
Enter Vertices and weight (u , v, w): 2 5 4
Enter Vertices and weight (u , v, w): 3 4 9
Enter Vertices and weight (u , v, w): 3 4 9
Enter Vertices and weight (u , v, w): 4 5 10
Enter Vertices and weight (u , v, w): 5 6 2
Enter Vertices and weight (u , v, w): 6 7 1
Enter Vertices and weight (u , v, w): 6 8 6
Enter Vertices and weight (u , v, w): 7 8 7
Enter Source Vertex : 0
Enter Distance Vertex : 6
Distance of dist Vertex from Source Vertex Vertex Distance from Source
0                0
1                4
2                12
3                19
4                28
5                16
6                18
7                8
8                14

18
*/