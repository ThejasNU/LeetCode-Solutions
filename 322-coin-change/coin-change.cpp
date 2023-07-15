class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0]=0;
        int ans=helper(amount,coins,dp);
        return ans==INT_MAX?-1:ans;
    }

    int helper(int amount,vector<int>& coins,vector<int>& dp){
        if(dp[amount]!=-1) return dp[amount];

        int ans=INT_MAX;
        for(int coin:coins){
            if(amount-coin>=0){
                int res=helper(amount-coin,coins,dp);
                if(res!=INT_MAX) ans=min(ans,1+res);
            }
        }
        return dp[amount]=ans;
    }
};