class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        long long ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int diff = nums[i] - i;
            ans += i - m[diff];
            m[diff]++;
        }
        return ans;
    }
};