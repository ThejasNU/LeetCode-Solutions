//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[]){
        vector<int> vis(V,0);
        stack<int> st;
        
        //step1: Finding finishing time
        for(int i=0;i<V;++i){
            if(!vis[i]) dfs(i,vis,adj,st);
        }
        
        //step2: Reversing the edges
        vector<int> adjT[V];
        for(int i=0;i<V;++i){
            vis[i]=0;
            for(int adjNode:adj[i]){
                adjT[adjNode].push_back(i);
            }
        }
        
        //step3: Calling the dfs on reversed graph
        int scc=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfsFinal(node,vis,adjT);
            }
        }
        
        return scc;
        
    }
    
    void dfs(int node,vector<int>& vis,vector<int> adj[],stack<int> &st){
        vis[node]=1;
        
        for(int adjNode:adj[node]){
            if(vis[adjNode]) continue;
            
            dfs(adjNode,vis,adj,st);
        }
        
        st.push(node);
    }
    
    void dfsFinal(int node,vector<int>& vis,vector<int> adj[]){
        vis[node]=1;
        
        for(int adjNode:adj[node]){
            if(vis[adjNode]) continue;
            
            dfsFinal(adjNode,vis,adj);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends