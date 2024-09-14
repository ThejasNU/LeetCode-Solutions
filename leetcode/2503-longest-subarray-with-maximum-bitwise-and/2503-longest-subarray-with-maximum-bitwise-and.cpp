class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxNum = 0;
        int ans = 0;
        int count;
        for (int i = 0; i < nums.size(); ++i) {
            count = 1;
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                ++count;
                ++i;
            }
            if (nums[i] > maxNum) {
                ans = count;
                maxNum = nums[i];
            } else if (nums[i] == maxNum) {
                ans = max(ans, count);
            }
        }
        return ans;
    }
};