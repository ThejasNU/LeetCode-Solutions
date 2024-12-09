class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        vector<int> prefix(nums.size(), 0);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                prefix[i] = prefix[i - 1] + 1;
            } else {
                prefix[i] = prefix[i - 1];
            }
        }

        vector<bool> ans(queries.size(), false);
        for (int i = 0; i < queries.size(); ++i) {
            ans[i] = ((prefix[queries[i][1]] - prefix[queries[i][0]]) == 0);
        }

        return ans;
    }
};