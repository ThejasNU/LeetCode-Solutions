class Solution {
public:
    int dp[1010][1010];
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,grid);
    }
    
    int helper(int i,int j,vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        if(i==m-1 && j==n-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=grid[i][j];
        int down=INT_MAX,right=INT_MAX;
        if(i+1<m) down=helper(i+1,j,grid);
        if(j+1<n) right=helper(i,j+1,grid);
        
        return dp[i][j]=ans+min(down,right);
    }
};