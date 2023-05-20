class Solution
{
    private:
    
    void dfs(int sv, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st )
    {
        visited[sv] = true;
        
        for(auto itr : adj[sv])
        {
            if(!visited[itr])
                dfs(itr, adj, visited, st);
        }
        
        st.push(sv);
    }
    
    void dfs2(int sv, vector<int> revAdj[], vector<bool>& visited)
    {
        visited[sv] = true;
        
        for(auto itr : revAdj[sv])
        {
            if(!visited[itr])
                dfs2(itr, revAdj, visited);
        }
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        
        vector<bool> visited(V+1, false);
        
        stack<int> st;
        
        for(int i = 0; i < V; ++i)
        {
            if(!visited[i])
                dfs(i, adj, visited, st);
        }
        
        vector<int> revAdj[V+1];
        
        // reverse edges
        
        for(int i = 0; i < V; ++i)
        {
            for(auto itr : adj[i])
                 revAdj[itr].push_back(i);
        }
        
        for(int i = 0; i < V; ++i)
            visited[i] = false;
            
        int cnt = 0;
        
        while(!st.empty())
        {
            int curr = st.top();
            
            st.pop();
            
            if(!visited[curr])
            {
                ++cnt;
                
                dfs2(curr, revAdj, visited);
            }
        }
        
        return cnt;
    }
};
