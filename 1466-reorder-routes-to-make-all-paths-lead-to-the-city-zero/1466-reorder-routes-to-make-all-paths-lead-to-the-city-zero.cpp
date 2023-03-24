class Solution {
public:
    int count;
    
    int minReorder(int n, vector<vector<int>>& connections) {
        count=0;
        vector<vector<pair<int,int>>> adj(n);
        for(auto& connection:connections){
            adj[connection[0]].push_back({connection[1],1});
            adj[connection[1]].push_back({connection[0],0});
        }
        dfs(0,-1,adj);
        return count;
    }
    
    void dfs(int node,int parent,vector<vector<pair<int, int>>>& adj){
        for(auto& [child,sign]:adj[node]){
            if(child!=parent){
                count+=sign;
                dfs(child,node,adj);
            }
        }
    }
};