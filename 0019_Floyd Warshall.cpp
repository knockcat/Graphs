//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    
	   // keeping node to node dist to 0 as node 1 can reach node 1 in 0 dist
	   // i == j , dist = 0;

        // Floyd Warshall (All path Shortest Path Algorithm)
        
	    int n = matrix.size();
	    
	    for(int i = 0; i < n; ++i)
	    {
	        for(int j = 0; j < n; ++j)
	        {
	            if(matrix[i][j] == -1)
	                matrix[i][j] = 1e8;
	            if(i == j)
	                matrix[i][j] = 0;
	        }
	    }
	    
	    for(int k = 0; k < n; ++k)
	    {
    	    for(int i = 0; i < n; ++i)
    	    {
    	        for(int j = 0; j < n; ++j)
    	        {
    	            matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
    	        }
    	    }
	    }
	    
	   // if graph contains negative cycle than matrix[i][i] will become less than 0
	   // although this condition not satisfied for this question given testcases
	   // as matrix contain -1 when there is no path so replacing no path value with other big value will be fine
	    
	    /*
	    for(int i = 0; i < n; ++i)
	    {
	        if(matrix[i][i] < 0)
	            return {-1};
	    }
	    */
	    
	    for(int i = 0; i < n; ++i)
	    {
	        for(int j = 0; j < n; ++j)
	        {
	            if(matrix[i][j] == 1e8)
	                matrix[i][j] = -1;
	        }
	    }
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
