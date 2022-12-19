class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        vector<int> vis(n,0);
        
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        return dfs(source,adj,vis,destination);
    }
    
    bool dfs(int v,vector<int> adj[],vector<int> &vis,int dest){
        if(v==dest) return true;
        
        vis[v]=1;
        
        for(int child:adj[v]){
            if(!vis[child]) if(dfs(child,adj,vis,dest)) return true;
        }
        return false;
        
    }
};