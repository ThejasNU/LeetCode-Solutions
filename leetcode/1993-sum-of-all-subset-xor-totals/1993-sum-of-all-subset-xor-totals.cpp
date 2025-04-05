class Solution {
public:
    int subsetXORSum(vector<int>& nums) { return helper(0, nums, 0); }

private:
    int helper(int idx, vector<int>& nums, int cur) {
        if (idx == nums.size()) {
            return cur;
        }
        int without = helper(idx + 1, nums, cur);
        int with = helper(idx + 1, nums, cur ^ nums[idx]);
        return without + with;
    }
};