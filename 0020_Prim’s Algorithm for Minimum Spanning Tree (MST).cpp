//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        vector<bool> visited(V, false);
        
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>> , greater<tuple<int,int,int>> > pq;
        
        pq.push(make_tuple(0, 0,-1));
        
        int minWt = 0;
        
        // vector<vector<int>> mst;
        
        while(!pq.empty())
        {
            tuple<int,int,int> t = pq.top();
            
            int wt = get<0>(t);
            int node = get<1>(t);
            int par = get<2>(t);
            
            pq.pop();
            
            if(visited[node])
                continue;
            
            minWt += wt;
            
            // if(par != -1)
            //     mst.push_back({par, node});
            
            visited[node] = true;
            
            for(auto itr : adj[node])
            {
                int adjNode = itr[0];
                int adjWt = itr[1];
                
                if(!visited[adjNode])
                {
                    pq.push(make_tuple(adjWt, adjNode, node));
                }
            }
        }
        
        // MST
        
        // for(auto itr : mst)
        // {
        //     cout<<itr[0]<<"-->"<<itr[1]<<" ";
        // }
        
        // cout<<endl;
        
        
        return minWt;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
