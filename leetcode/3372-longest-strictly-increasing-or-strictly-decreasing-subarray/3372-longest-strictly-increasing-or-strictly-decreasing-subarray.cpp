class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incLen = 1, decLen = 1, ans = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                ++incLen;
                decLen = 1;
            } else if (nums[i - 1] > nums[i]) {
                ++decLen;
                incLen = 1;
            } else {
                incLen = 1;
                decLen = 1;
            }

            ans = max(ans, max(incLen, decLen));
        }

        return ans;
    }
};