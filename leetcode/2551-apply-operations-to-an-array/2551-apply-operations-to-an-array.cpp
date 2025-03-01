class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                nums[i - 1] *= 2;
                nums[i] = 0;
            }
        }

        int i = 0;
        for (int n : nums) {
            if (n != 0) {
                nums[i++] = n;
            }
        }

        while (i < nums.size()) {
            nums[i++] = 0;
        }

        return nums;
    }
};