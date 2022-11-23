class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        vector<int> ans;

        for(int i=0;i<n;++i){
            if(!vis[i]){
                dfs(i,graph,vis,pathVis,ans);
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }

    bool dfs(int cur,vector<vector<int>>& graph,vector<int> &vis,vector<int> &pathVis,vector<int> &ans){
        vis[cur]=1;
        pathVis[cur]=1;

        for(int v:graph[cur]){
            if(!vis[v]){
                if(dfs(v,graph,vis,pathVis,ans)) return true;
            }

            else if(pathVis[v]) return true;
        }

        pathVis[cur]=0;
        ans.push_back(cur);
        return false;

    }
};