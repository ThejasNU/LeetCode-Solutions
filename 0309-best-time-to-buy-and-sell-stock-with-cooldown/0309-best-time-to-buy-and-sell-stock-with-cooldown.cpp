class Solution {
public:
    int dp[5010][2];
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        
        return helper(0,1,prices);
    }
    
    int helper(int ind,int buy,vector<int>& prices){
        if(ind>=prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        
        if(buy==1){
            return dp[ind][buy]=max(-prices[ind]+helper(ind+1,0,prices),0+helper(ind+1,1,prices));
        }
        else{
            return dp[ind][buy]=max(prices[ind]+helper(ind+2,1,prices),0+helper(ind+1,0,prices));
        }
    }
};