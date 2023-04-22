class Solution {
public:
    int mod = 1e9 + 7;
    int dp[110][110][110];
             
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1,sizeof(dp));
        return helper(0, 0, 0, n, minProfit, group, profit);
    }

    int helper(int pos, int count, int profit, int n, int minProfit, vector<int>& group, vector<int>& profits) {
        if (pos == group.size()) return profit >= minProfit;
        
        if (dp[pos][count][profit] != -1) return dp[pos][count][profit];
        
        //without this crime.
        int totalWays = helper(pos + 1, count, profit, n, minProfit, group, profits);       //including this crime.
        if (count + group[pos] <= n) {
            totalWays += helper(pos + 1, count + group[pos], min(minProfit, profit + profits[pos]), n, minProfit, group, profits);
        }
        
        return dp[pos][count][profit] = totalWays % mod;
    }
};