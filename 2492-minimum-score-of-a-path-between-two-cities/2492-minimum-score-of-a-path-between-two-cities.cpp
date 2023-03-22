class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> vis(n+1,0);
        vector<int> adj[n+1];
        for(auto road:roads){
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        
        dfs(1,adj,vis);
        
        int ans=INT_MAX;
        for(auto road:roads){
            if(vis[road[0]] || vis[road[1]]) ans=min(ans,road[2]);
        }
        return ans;
    }
    
    void dfs(int node,vector<int> adj[],vector<int> &vis){
        vis[node]=1;
        for(int v:adj[node]){
            if(!vis[v]) dfs(v,adj,vis);
        }
    }
};
