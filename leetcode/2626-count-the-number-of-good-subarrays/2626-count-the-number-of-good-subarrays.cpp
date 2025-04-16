class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        int pairs = 0, r = -1;
        long long ans = 0;
        for (int l = 0; l < n; ++l) {
            while (pairs < k && r+1 < n) {
                ++r;
                pairs += m[nums[r]];
                ++m[nums[r]];
            }
            if (pairs >= k) {
                ans += n - r;
            }
            --m[nums[l]];
            pairs -= m[nums[l]];
        }
        return ans;
    }
};