class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int> vis(n,0);
        int nonRemovables=0;
        for(int i=0;i<n;++i){
            if(vis[i]) continue;
            nonRemovables++;
            dfs(i,stones,vis,n);
        }
        return n-nonRemovables;
    }

    void dfs(int idx,vector<vector<int>>& stones,vector<int> &vis,int n){
        vis[idx]=1;

        for(int i=0;i<n;++i){
            if(vis[i]) continue;

            if(stones[idx][0]==stones[i][0] || stones[idx][1]==stones[i][1]){
                dfs(i,stones,vis,n);
            }
        }
        return;
    }
};