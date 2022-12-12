// 0014_Tarjan's_ALgorithm of time in and low time (Articulation_Point - I)

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution
{

private:
    int timer = 0;

    void helper(int sv, int parent, vector<bool> &visited, vector<int> &tin, vector<int> &low, vector<int> adj[], int timer, vector<bool> &articulation)
    {
        visited[sv] = true;
        tin[sv] = low[sv] = timer++;
        int child = 0;
        for (auto itr : adj[sv])
        {
            if (itr == parent)
                continue;
            if (!visited[itr])
            {
                helper(itr, sv, visited, tin, low, adj, timer, articulation);
                low[sv] = min(low[sv], low[itr]);

                if (low[itr] >= tin[sv] and parent != -1)
                {
                    articulation[sv] = 1;
                }
                ++child;
            }
            else
            {
                low[sv] = min(low[sv], tin[itr]);
            }
        }
        if (parent == -1 and child > 1)
            articulation[sv] = 1;
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        // Code here

        int n = V;
        vector<int> ans;
        vector<bool> visited(n, false), articulation(n + 1, false);
        vector<int> tin(n, -1), low(n, -1);

        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
                helper(i, -1, visited, tin, low, adj, timer, articulation);
        }

        for (int i = 0; i < n; ++i)
        {
            if (articulation[i] == 1)
                ans.push_back(i);
        }

        if (ans.size() == 0)
            return {-1};
        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, adj);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends

/*
5 5
0 1
1 4
2 4
3 4
2 3
*/
