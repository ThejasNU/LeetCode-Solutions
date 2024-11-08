class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int total = 0;
        for (int num : nums) {
            total ^= num;
        }
        total ^= int(pow(2, maximumBit)) - 1;

        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            ans[i] = total;
            total ^= nums[nums.size() - 1 - i];
        }

        return ans;
    }
};