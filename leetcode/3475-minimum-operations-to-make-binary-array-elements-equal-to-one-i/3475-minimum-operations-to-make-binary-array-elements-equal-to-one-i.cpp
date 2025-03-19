class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] == 0) {
                nums[i] = 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ++ans;
            }
        }

        if (count(nums.begin(), nums.end(), 0) == 0) {
            return ans;
        } else {
            return -1;
        }
    }
};