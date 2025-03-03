class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        int less = 0, greater = n - 1;
        for (int i = 0, j = n - 1; i < n; ++i, --j) {
            if (nums[i] < pivot) {
                ans[less] = nums[i];
                ++less;
            }
            if (nums[j] > pivot) {
                ans[greater] = nums[j];
                --greater;
            }
        }
        while (less <= greater) {
            ans[less] = pivot;
            ++less;
        }
        return ans;
    }
};