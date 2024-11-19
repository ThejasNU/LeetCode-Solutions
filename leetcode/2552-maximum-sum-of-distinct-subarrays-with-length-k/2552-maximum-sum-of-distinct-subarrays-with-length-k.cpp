class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, cur = 0;
        int l = 0, r = 0;
        unordered_map<int, int> m;

        while (r < nums.size()) {
            int lastIdx = (m.find(nums[r]) != m.end() ? m[nums[r]] : -1);

            while (l <= lastIdx || r - l + 1 > k) {
                cur -= nums[l];
                ++l;
            }

            m[nums[r]] = r;
            cur += nums[r];

            if (r - l + 1 == k) {
                ans = max(ans, cur);
            }

            ++r;
        }

        return ans;
    }
};