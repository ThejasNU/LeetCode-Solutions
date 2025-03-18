class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int cur = 0, start = 0, ans = 0;
        for (int end = 0; end < nums.size(); ++end) {
            while ((cur & nums[end]) != 0) {
                cur ^= nums[start];
                ++start;
            }
            cur |= nums[end];
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};