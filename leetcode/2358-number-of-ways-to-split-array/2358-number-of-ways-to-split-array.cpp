class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), (long long)0);
        long long cur = 0;
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            cur += (long long)nums[i];
            if (2 * cur >= sum) {
                ++ans;
            }
        }
        return ans;
    }
};