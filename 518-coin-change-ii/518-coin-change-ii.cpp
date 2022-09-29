class Solution {
public:
    int dp[310][10010];
    
    int find(int ind,int amount,vector<int>& coins){
        if(amount==0) return 1;
        if(ind<0) return 0;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        
        int ways=0;
        for(int coinAmount=0;coinAmount<=amount;coinAmount+=coins[ind]){
            ways+=find(ind-1,amount-coinAmount,coins);
        }
        
        return dp[ind][amount]=ways;
    }
    
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        int res=find(coins.size()-1,amount,coins);
        return res;
    }
};