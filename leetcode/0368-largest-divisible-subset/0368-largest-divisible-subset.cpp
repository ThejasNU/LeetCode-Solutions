class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        int maxSize = 1;
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] % nums[i] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    maxSize = max(maxSize, dp[i]);
                }
            }
        }

        int lastNum = -1;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (maxSize == dp[i] && (lastNum == -1 || nums[i] % lastNum == 0)) {
                ans.push_back(nums[i]);
                maxSize -= 1;
                lastNum = nums[i];
            }
        }
        return ans;
    }
};