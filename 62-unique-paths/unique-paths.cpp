class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[m-1][n-1]=1;
        function<int(int,int)> helper=[&](int i,int j)->int{
            if(i>=m || j>=n) return 0;
            if(dp[i][j]!=-1) return dp[i][j];

            return dp[i][j]=helper(i+1,j)+helper(i,j+1);
        };
        return helper(0,0);
    }
};