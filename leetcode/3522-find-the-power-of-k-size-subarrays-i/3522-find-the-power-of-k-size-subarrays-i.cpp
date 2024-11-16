class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }

        int n = nums.size();
        vector<int> ans(n - k + 1, -1);

        int count = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                ++count;
            } else {
                count = 1;
            }

            if (count >= k) {
                ans[i - k + 1] = nums[i];
            }
        }

        return ans;
    }
};