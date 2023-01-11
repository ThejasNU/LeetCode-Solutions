class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        return dfs(0,-1,adj,hasApple);
    }
    
    int dfs(int node,int parent,vector<int> adj[],vector<bool>& hasApple){
        int totalTime=0,childTime=0;
        
        for(int child:adj[node]){
            if(child==parent) continue;
            
            childTime=dfs(child,node,adj,hasApple);
            //childTime>0 means subree has apples
            if(childTime || hasApple[child]) totalTime+=childTime+2;
        }
        
        return totalTime;
    }
};