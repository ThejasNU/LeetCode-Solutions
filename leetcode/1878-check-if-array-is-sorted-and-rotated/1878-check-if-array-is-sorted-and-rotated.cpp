class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        int count = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i + 1] < nums[i]) {
                ++count;
            }
        }

        // check for edge case since array is rotated
        if (nums[0] < nums[n - 1]) {
            ++count;
        }

        return count < 2;
    }
};