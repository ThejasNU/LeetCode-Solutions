class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = 0;
        for (int cur = 2; cur < n; ++cur) {
            int l = 0, r = cur - 1;
            while (l < r) {
                int sum = arr[l] + arr[r];
                if (sum < arr[cur]) {
                    ++l;
                } else if (sum > arr[cur]) {
                    --r;
                } else {
                    dp[r][cur] = dp[l][r] + 1;
                    ans = max(ans, dp[r][cur]);
                    ++l;
                    --r;
                }
            }
        }
        return ans == 0 ? 0 : ans + 2;
    }
};