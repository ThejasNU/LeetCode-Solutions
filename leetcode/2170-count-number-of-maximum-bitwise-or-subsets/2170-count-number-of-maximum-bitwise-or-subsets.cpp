class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int num : nums) {
            maxOr |= num;
        }

        vector<vector<int>> dp(nums.size(), vector<int>(maxOr + 1, -1));

        return helper(nums, 0, 0, maxOr, dp);
    }

    int helper(vector<int>& nums, int idx, int cur, int tar,
               vector<vector<int>>& dp) {
        if (idx == nums.size()) {
            if (cur == tar) {
                return 1;
            } else {
                return 0;
            }
        }

        if (dp[idx][cur] != -1) {
            return dp[idx][cur];
        }

        int notIncluded = helper(nums, idx + 1, cur, tar, dp);
        int included = helper(nums, idx + 1, cur | nums[idx], tar, dp);

        return dp[idx][cur] = notIncluded + included;
    }
};