class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        
        dp[n1][n2]=0;
        
        int i=n1;
        for(int j=n2-1;j>=0;--j){
            dp[i][j]=dp[i][j+1]+int(s2[j]);
        }
        
        int j=n2;
        for(int i=n1-1;i>=0;--i){
            dp[i][j]=dp[i+1][j]+int(s1[i]);
        }
        
        function<int(int,int)> helper=[&](int i,int j)->int{
            if(dp[i][j]!=-1) return dp[i][j];

            if(s1[i]==s2[j]) return dp[i][j]=helper(i+1,j+1);
            else{
                int skip1=int(s1[i])+helper(i+1,j);
                int skip2=int(s2[j])+helper(i,j+1);
                return dp[i][j]=min(skip1,skip2);
            }
        };
        
        return helper(0,0);
    }
};