class Solution {
public:
    int dp[1010][2010];
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        return helper(n, k,piles);
    }

    int helper(int i, int coins,vector<vector<int>>& piles) {
        if (i == 0) return 0;
        if (dp[i][coins] != -1) return dp[i][coins];
        int currentSum = 0;
        for (int currentCoins = 0; currentCoins <= min((int)piles[i - 1].size(), coins); currentCoins++) {
            if (currentCoins > 0) currentSum += piles[i - 1][currentCoins - 1];
            dp[i][coins] = max(dp[i][coins], currentSum+helper(i - 1, coins - currentCoins,piles));
        }
        return dp[i][coins];
    };
};