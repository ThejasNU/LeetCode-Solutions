class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<int> adj[n];
        for(int i=0;i<n;++i){
            long long x1=bombs[i][0];
            long long y1=bombs[i][1];
            long long r1=bombs[i][2];
            for(int j=0;j<n;++j){
                if(i!=j){
                    long long x2=bombs[j][0];
                    long long y2=bombs[j][1];
                    if(pow(x1-x2,2)+pow(y1-y2,2)<=pow(r1,2)) adj[i].push_back(j);
                }
            }
        }
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;++i){
            dfs(i,vis,adj);
            int cnt=count(vis.begin(),vis.end(),1);
            ans=max(cnt,ans);
            fill(vis.begin(),vis.end(),0);
        }
        return ans;
    }

    void dfs(int src,vector<int>& vis,vector<int> adj[]){
        vis[src]=1;
        for(int neigh:adj[src]){
            if(vis[neigh]==0) dfs(neigh,vis,adj);
        }
    }
};