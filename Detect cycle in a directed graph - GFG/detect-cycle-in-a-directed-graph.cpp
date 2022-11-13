//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        for(int i=0;i<V;++i){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis)) return true;
            } 
        }
        return false;
    }
    
    bool dfs(int cur,vector<int> adj[],vector<int>&vis,vector<int>&pathVis){
        vis[cur]=1;
        pathVis[cur]=1;
        
        for(int v:adj[cur]){
            if(!vis[v]){
                if(dfs(v,adj,vis,pathVis)) return true;
            }
            else if(pathVis[v]) return true;
        }
        
        pathVis[cur]=0;
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends