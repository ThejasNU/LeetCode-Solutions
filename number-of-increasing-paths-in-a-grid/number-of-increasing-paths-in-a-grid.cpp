class Solution {
public:
    vector<vector<int>> dp;
    int M=1e9+7;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};

    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        dp.resize(m,vector<int>(n,0));

        int ans=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                ans=(ans+helper(i,j,grid))%M;
            }
        }
        return ans;
    }

    int helper(int i, int j,vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        if(dp[i][j]!=0) return dp[i][j];
        
        int ans=1;
        for(int x=0;x<4;++x){
            int newI=i+dx[x];
            int newJ=j+dy[x];
            if(newI>=0 && newI<m && newJ>=0 && newJ<n && grid[newI][newJ]>grid[i][j]){
                ans+=helper(newI,newJ,grid);
                ans%=M;
            }
        }

        return dp[i][j]=ans%M;
    }
};