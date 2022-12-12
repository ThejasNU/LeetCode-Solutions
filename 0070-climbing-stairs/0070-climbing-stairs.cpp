class Solution {
public:  
    int dp[100];
    
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        int ans=helper(n);
        return ans;
    }
    
    int helper(int n){
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        
        int res=0;
        
        if(n-1>=0) res+=helper(n-1);
        if(n-2>=0) res+=helper(n-2);
        
        return dp[n]=res;
    }
};