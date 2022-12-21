class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n];
        
        for(auto edge:dislikes){
            adj[edge[0]-1].push_back(edge[1]-1);
            adj[edge[1]-1].push_back(edge[0]-1);
        }
        
        vector<int> color(n,-1);
        
        for(int i=0;i<n;++i){
            if(color[i]==-1){
                if(!bfs(i,adj,color)) return false;
            }
        }
        
        return true;
    }
    
    bool bfs(int src,vector<int> adj[],vector<int> &color){
        queue<int> q;
        q.push(src);
        color[src]=0;
        
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            
            for(int v:adj[cur]){
                if(color[v]==color[cur]) return false;
                
                if(color[v]==-1){
                    color[v]=1-color[cur];
                    q.push(v);
                }
            }
        }
        
        return true;
    }
};