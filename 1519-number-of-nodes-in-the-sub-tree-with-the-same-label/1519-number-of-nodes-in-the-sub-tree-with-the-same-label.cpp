class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> adj[n];
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> ans(n,0);
        dfs(0,-1,adj,labels,ans);
        return ans;
    }
    
    vector<int> dfs(int node,int parent,vector<int> adj[],string &labels,vector<int> &ans){
        vector<int> count(26,0);
        count[labels[node]-'a']++;
        
        for(int neigh:adj[node]){
            if(neigh==parent) continue;
            
            vector<int> temp= dfs(neigh,node,adj,labels,ans);
            for(int i=0;i<26;++i){
                count[i]+=temp[i];
            }
        }
        
        ans[node]=count[labels[node]-'a'];
        return count;
    }
};