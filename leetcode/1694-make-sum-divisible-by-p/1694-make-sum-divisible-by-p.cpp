class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int totalSum = 0;
        for (int num : nums) {
            totalSum = (totalSum + num) % p;
        }

        int toRemove = totalSum % p;
        if (toRemove == 0) {
            return 0;
        }

        unordered_map<int, int> m;
        m[0] = -1;

        int curSum = 0, ans = n;
        for (int i = 0; i < n; ++i) {
            curSum = (curSum + nums[i]) % p;
            int needed = (curSum - toRemove + p) % p;
            if (m.find(needed) != m.end()) {
                ans = min(ans, i - m[needed]);
            }
            m[curSum] = i;
        }

        return ans == n ? -1 : ans;
    }
};