class Solution {
public:
    vector<vector<int>> dp;
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        dp.resize(n,vector<int>(2,-1));
        return helper(0,prices,fee,0);
    }

    int helper(int curInd,vector<int>& prices, int fee,int isPurchased){
        if(curInd>=prices.size()) return 0;
        if(dp[curInd][isPurchased]!=-1) return dp[curInd][isPurchased];

        int res;
        if(isPurchased){
            //don't sell
            res=helper(curInd+1,prices,fee,1);

            //sell
            res=max(res,prices[curInd]-fee+helper(curInd+1,prices,fee,0));
        }
        else{
            //don't purchase
            res=helper(curInd+1,prices,fee,0);

            //purchase
            res=max(res,-prices[curInd]+helper(curInd+1,prices,fee,1));
        }

        return dp[curInd][isPurchased]=res;
    }
};