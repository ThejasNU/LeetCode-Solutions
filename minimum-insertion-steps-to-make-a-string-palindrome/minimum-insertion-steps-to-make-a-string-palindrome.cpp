class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        string sReverse=s;
        reverse(sReverse.begin(),sReverse.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return n-helper(s,sReverse,n,n,dp);
    }

    int helper(string& s1,string& s2,int m,int n,vector<vector<int>>& dp){
        if(m==0 || n==0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];

        if(s1[m-1]==s2[n-1]) return dp[m][n]=1+helper(s1,s2,m-1,n-1,dp);
        else return dp[m][n]=max(helper(s1,s2,m-1,n,dp),helper(s1,s2,m,n-1,dp));
    }
};