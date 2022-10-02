class Solution {
public:
    const int MOD = 1e9+7;
    vector<vector<int>> memo;
    int numRollsToTarget(int n, int k, int target) {
        memo = vector<vector<int>>(n+1, vector<int>(target+1, -1));
        return helper(n, k, target);
    }
    int helper(int n, int k, int target) {
        if (target == 0) return n == 0;
        if (n == 0 || target < 0) return 0;
        if (memo[n][target] != -1) return memo[n][target];
        
        int ways = 0;
        for (int i=1; i<=k; ++i) {
            ways = (ways + helper(n-1, k, target-i)) % MOD;
        }
        return memo[n][target] = ways % MOD;
    }
};